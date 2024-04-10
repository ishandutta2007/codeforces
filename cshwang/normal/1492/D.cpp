#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int a , b , k ;

int main() {
	scanf("%d %d %d" , &a , &b , &k) ;
	if (b == 1) {
		if (k) printf("No\n") ;
		else {
			printf("Yes\n") ;
			for (int t = 0 ; t < 2 ; ++t) {
				printf("1") ;
				for (int i = 0 ; i < a ; ++i) printf("0") ;
				printf("\n") ;
			}
		}
	}
	else if (!a) {
		if (k) printf("No\n") ;
		else {
			printf("Yes\n") ;
			for (int t = 0 ; t < 2 ; ++t) {
				for (int i = 0 ; i < b ; ++i) printf("1") ;
				printf("\n") ;
			}
		}
	}
	else {
		if (k >= a + b - 1) printf("No\n") ;
		else if (k <= a) {
			printf("Yes\n") ;
			for (int i = 0 ; i < b ; ++i) printf("1") ;
			for (int i = 0 ; i < a ; ++i) printf("0") ;
			printf("\n") ;

			for (int i = 1 ; i < b ; ++i) printf("1") ;
			for (int i = 0 ; i < k ; ++i) printf("0") ;
			printf("1") ;
			for (int i = 0 ; i < a - k ; ++i) printf("0") ;
			printf("\n") ;
		}
		else {
			printf("Yes\n") ;
			for (int i = 0 ; i < b ; ++i) printf("1") ;
			for (int i = 0 ; i < a ; ++i) printf("0") ;
			printf("\n") ;

			int lef = k - a ;
			for (int i = 1 ; i < b - lef ; ++i) printf("1") ;
			printf("0") ;
			for (int i = 0 ; i < lef ; ++i) printf("1") ;
			for (int i = 1 ; i < a ; ++i) printf("0") ;
			printf("1\n") ;
		}
	}

	return 0 ;
}