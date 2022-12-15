#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 300 + 10 ;

int T , n , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		int l = 1 , r = n ;
		for (int i = 1 ; i <= n ; ++i)
			if (i & 1) printf("%d " , a[l++]) ;
			else printf("%d " , a[r--]) ;
		printf("\n") ;
	}

	return 0 ;
}