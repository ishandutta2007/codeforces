#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int T , n , m , d[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;

		m = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int a ; scanf("%d" , &a) ;

			if (a == 1) {d[++m] = a ;}
			else {
				for (; m > 0 && d[m] + 1 != a ; --m) ;
				++d[m] ;
			}

			for (int i = 1 ; i <= m ; ++i) {
				printf("%d" , d[i]) ;
				if (i < m) printf(".") ;
				else printf("\n") ;
			}
		}
	}

	return 0 ;
}