#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e3 + 10 , mod = 1e9 + 7 ;

int n , k , q , a[MAX_N] , f[MAX_N][MAX_N] , g[MAX_N][MAX_N] ;

int main() {
	scanf("%d %d %d" , &n , &k , &q) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	for (int i = 1 ; i <= n ; ++i) f[i][0] = 1 ;
	for (int j = 1 ; j <= k ; ++j)
		for (int i = 1 ; i <= n ; ++i) {
			int tmp = 0 ;
			if (i > 1) (tmp += f[i - 1][j - 1]) %= mod ;
			if (i < n) (tmp += f[i + 1][j - 1]) %= mod ;

			f[i][j] = tmp ;
		}

	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 0 ; j <= k ; ++j) g[i][j] = (ll)f[i][j] * f[i][k - j] % mod ;
		for (int j = 1 ; j <= k ; ++j) (g[i][j] += g[i][j - 1]) %= mod ;
	}

	///

	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		int tmp = (ll)g[i][k] * a[i] % mod ;
		(ans += tmp) %= mod ;
	}

	for (; q-- ;) {
		int p , x ;
		scanf("%d %d" , &p , &x) ;

		int t1 = (ll)a[p] * g[p][k] % mod , t2 = (ll)x * g[p][k] % mod ;
		a[p] = x ;
		ans = (ans + mod - t1) % mod ; (ans += t2) %= mod ;
		printf("%d\n" , ans) ;
	}

	return 0 ;
}