#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n , m , c[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 1 ; i <= 100 ; ++i) c[i] = 0 ;

		int ans = 0 ;
		for (int i = 1 ; i <= n + m ; ++i) {
			int a ; scanf("%d" , &a) ;

			++c[a] ;
			if (c[a] > 1) ++ans ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}