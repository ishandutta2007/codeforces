#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10 ;

int n , sg ;

int main() {
	scanf("%d" , &n) ; sg = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int a ; scanf("%d" , &a) ;
		(a &= 1) ^= 1 ; sg ^= a ;

		if (sg) printf("1\n") ;
		else printf("2\n") ;
	}

	return 0 ;
}