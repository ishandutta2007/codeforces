#include <stdio.h>
#include <stdlib.h> 

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;

		if (n % 2) {
			for (int i = 1 ; i <= n ; ++i) {
				for (int j = 1 ; j <= n ; ++j) {
					int rj = n - j + 1 , ri = n - i + 1 ;
					if (i == j || i == rj || (i == 1 && j == rj) || (j == 1 && i == ri)) printf("1 ") ;
					else printf("0 ") ;
				}
				printf("\n") ;
			}
		}
		else {
			for (int i = 1 ; i <= n ; ++i) {
				for (int j = 1 ; j <= n ; ++j) {
					int rj = n - j + 1 ;
					if (i == j || i == rj) printf("1 ") ;
					else printf("0 ") ;
				}
				printf("\n") ;
			}
		}
	}

	return 0 ;
}