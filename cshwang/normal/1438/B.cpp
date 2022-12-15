#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int T , n , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		std::sort(a + 1 , a + 1 + n) ;

		///

		bool ok = 0 ;
		for (int i = 2 ; i <= n ; ++i) ok |= (a[i] == a[i - 1]) ;

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}