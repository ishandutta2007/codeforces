#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 60 + 5 , MAX_K = 1e4 + 10 , mod = 1e9 + 7 ;

ll n ;
int ans , k , inv[MAX_N] , f[MAX_K][MAX_N] , g[MAX_K][MAX_N] ;

int qpow(int x , int t) {
	int tmp = x , s = 1 ;
	for (; t ; t >>= 1 , tmp = (ll)tmp * tmp % mod)
		if (t & 1) s = (ll)s * tmp % mod ;

	return s ;
}

int work(ll x , int n) {
	f[0][0] = g[0][0] = 1 ;
	for (int i = 1 ; i <= n ; ++i) {
		f[0][i] = (ll)f[0][i - 1] * x % mod ;
		g[0][i] = (g[0][i - 1] + f[0][i]) % mod ;
	}

	for (int i = 1 ; i <= n + 1 ; ++i) inv[i] = qpow(i , mod - 2) ;

	for (int i = 1 ; i <= k ; ++i)
		for (int j = 0 ; j <= n ; ++j) {
			f[i][j] = (ll)g[i - 1][j] * inv[j + 1] % mod ;
			if (!j) g[i][j] = f[i][j] ;
			else g[i][j] = (g[i][j - 1] + f[i][j]) % mod ;
		}

	return f[k][n] ;
}

int main() {
	scanf("%lld %d" , &n , &k) ;

	ans = 1 ;
	for (ll i = 2 ; i * i <= n ; ++i) {
		if (n % i) continue ;
		int cnt = 0 ; for (; !(n % i) ; n /= i , ++cnt) ;

		ans = (ll)ans * work(i , cnt) % mod ;
	}
	if (n > 1) ans = (ll)ans * work(n , 1) % mod ;

	printf("%d\n" , ans) ;

	return 0 ;
}