#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n , a[MAX_N] ;

int work() {
	int s = 0 , r = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		s += a[i] ;
		r = std::max(r , s) ;
	}

	return r ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		int ans = work() ;
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		ans += work() ;
		printf("%d\n" , ans) ;
	}

	return 0 ;
}