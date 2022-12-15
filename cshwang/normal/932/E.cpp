#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_K = 5e3 + 10 , mod = 1e9 + 7 ;

int n , k , pw[MAX_K] , inv[MAX_K] , S[MAX_K][MAX_K] ;

int qpow(int x , int t) {
	int s = 1 , tmp = x ;

	for (; t ; t >>= 1 , tmp = (ll)tmp * tmp % mod)
		if (t & 1) s = (ll)s * tmp % mod ;

	return s ;
}

int main() {
	scanf("%d %d" , &n , &k) ;

	S[0][0] = 1 ;
	for (int i = 1 ; i <= k ; ++i)
		for (int j = 1 ; j <= i ; ++j)
			S[i][j] = (S[i - 1][j - 1] + (ll)j * S[i - 1][j]) % mod ;

	pw[0] = 1 ;
	for (int i = 1 ; i <= k ; ++i) pw[i] = (ll)pw[i - 1] * i % mod ;
	for (int i = 1 ; i <= k ; ++i) inv[i] = qpow(i , mod - 2) ;

	///

	int ans = 0 , C = 1 ;
	for (int p = 0 ; p <= k ; ++p) {
		if (p > n) break ;

		int tmp = qpow(2 , n - p) ;

		tmp = (ll)tmp * S[k][p] % mod ;
		tmp = (ll)tmp * pw[p] % mod ;
		tmp = (ll)tmp * C % mod ;

		(ans += tmp) %= mod ;
		C = (ll)C * (n - p) % mod ;
		C = (ll)C * inv[p + 1] % mod ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}