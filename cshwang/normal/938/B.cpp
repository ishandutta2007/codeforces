#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int n , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

	int ans = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int t1 = a[i] - 1 , t2 = 1e6 - a[i] , t = std::min(t1 , t2) ;
		ans = std::max(ans , t) ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}