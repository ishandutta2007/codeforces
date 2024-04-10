#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 , mod = 1e9 + 7 ;

int n , m , equl , ans , ny , nny , s1[MAX_N] , s2[MAX_N] ;

int qpow(int a , int t) {
	if (t == 1) return a ;

	int s = qpow(a , t >> 1) ;
	s = (ll)s * s % mod ;
	if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &s1[i]) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &s2[i]) ;

	///

	equl = 1 ; ans = 0 ;
	ny = qpow(m , mod - 2) ; nny = qpow(m << 1 , mod - 2) ;
	for (int i = 0 ; i < n ; ++i)
		if (!s1[i] && s2[i]) {
			int P = (ll)(m - s2[i]) * ny % mod ;
			P = (ll)P * equl % mod ;

			(ans += P) %= mod ;
			equl = (ll)equl * ny % mod ;
		}
		else if (s1[i] && !s2[i]) {
			int P = (ll)(s1[i] - 1) * ny % mod ;
			P = (ll)P * equl % mod ;

			(ans += P) %= mod ;
			equl = (ll)equl * ny % mod ;
		}
		else if (!s1[i] && !s2[i]) {
			int P = (ll)(m - 1) * nny % mod ;
			P = (ll)P * equl % mod ;

			(ans += P) %= mod ;
			equl = (ll)equl * ny % mod ;
		}
		else if (s1[i] != s2[i]) {
			if (s1[i] > s2[i]) (ans += equl) %= mod ;

			break ;
		}

	printf("%d\n" , ans) ;

	return 0 ;
}