#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

int n , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d" , &a[i]) ;
		if (a[i] < 0) a[i] = -a[i] ;
	}

	///

	std::sort(a + 0 , a + n) ;

	int p = -1 ; ll ans = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		for (; p + 1 < n && (a[i] << 1) >= a[p + 1] ; ++p) ;

		if (p > i) ans += p - i ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}