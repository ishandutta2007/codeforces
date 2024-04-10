#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 , mod = 998244353 ;

int n , a[MAX_N] ;

int qpow(int a , int t) {
	int s = 1 ;
	for (; t ; t >>= 1 , a = (ll)a * a % mod)
		if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

int main() {
	scanf("%d" , &n) ;
	int m = n << 1 ;
	for (int i = 1 ; i <= m ; ++i) scanf("%d" , &a[i]) ;
	std::sort(a + 1 , a + 1 + m) ;

	///

	int s = 0 , pw = 1 , ny = 1 ;
	for (int i = m ; i > n ; --i) (s += a[i]) %= mod ;
	for (int i = n ; i ; --i) s = (s + mod - a[i]) % mod ;
	for (int i = 1 ; i <= n ; ++i) ny = (ll)ny * i % mod ;
	pw = ny ; for (int i = n + 1 ; i <= m ; ++i) pw = (ll)pw * i % mod ;
	ny = qpow((ll)ny * ny % mod , mod - 2) ;

	///

	s = (ll)s * pw % mod * ny % mod ;
	printf("%d\n" , s) ;

	return 0 ;
}