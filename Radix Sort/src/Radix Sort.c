/*
 ============================================================================
 Name        : Radix.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int *a, n, i;
	setbuf(stdout, NULL);

	printf("Enter n\n");
	scanf("%d",&n);

	a = (int*) calloc(n, sizeof(int));

	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}

	radixSort(a, n);

	for(i = 0; i < n; i++){
		printf("%d\t", a[i]);
	}

	return EXIT_SUCCESS;
}

void radixSort(int a[], int n){
	int i;
	int max = 0;

	for(i = 0; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}

	int exp = 1;

	while(exp <= max){

		int bucket[10] = {0};
		int t[n];

		for(i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;

		for(i = 1; i < 10; i++)
			bucket[i] += bucket[i-1];

		for(i = n-1; i >= 0; i--)
			t[--bucket[a[i]/exp%10]] = a[i];

		for(i = 0; i < n; i++){
			a[i] = t[i];
		}

		exp *= 10;


	}

}
