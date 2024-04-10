#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e16 ;
const int MAX_N = 3e5 + 10 ;

ll s[MAX_N] ;
int n , m , p , a[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	s[1] = a[1] ;
	for (int i = 2 ; i <= n ; ++i) s[i] = s[i - 1] + a[i] ;

	ll ans = s[n] * m ;
	std::sort(s + 1 , s + n) ;
	for (int i = 1 ; i <= m - 1 ; ++i) ans -= s[i] ;

	printf("%lld\n" , ans) ;

	return 0 ;
}