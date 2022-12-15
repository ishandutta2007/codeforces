#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 4e5 + 10 ;

ll s[MAX_N] ;
int n , m , a[MAX_N] ;

int main() {
	ll tot = 0 ;
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%d" , &a[i]) ;
		tot += a[i] ; a[i + n] = a[i] ;
	}

	///

	m = (n - 1) >> 1 ;
	for (int i = 0 ; i < m ; ++i) {
		s[1] += a[(i << 1) + 1] ;
		s[2] += a[(i << 1) + 2] ;
	}
	for (int i = 3 ; i <= n ; ++i) s[i] = s[i - 2] - a[i - 2] + a[i - 2 + (m << 1)] ;

	ll ans = tot - s[1] ;
	for (int i = 2 ; i <= n ; ++i) ans = std::max(ans , tot - s[i]) ;

	printf("%lld\n" , ans) ;

	return 0 ;
}