#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e16 ;
const int MAX_N = 2e5 + 10 ;

int T , n , a[MAX_N] ;
ll f[MAX_N][2] , g[MAX_N] ;

bool work(int x) {
	int y = x + 1 ;
	int ax = a[y] , ay = a[x] ;
	ll g1 = ax - g[x - 1] , g2 = ay - g1 ;

	if (g1 < 0 || g2 < 0) return 0 ;

	if (y == n) {
		if (g2 || g1 < 0) return 0 ;
		bool ok = 1 ;
		for (int i = 1 ; i < x ; ++i) ok |= (g[i] >= 0) ;

		return ok ;
	}

	int ty1 = (y + 1) & 1 , ty2 = y & 1 , ed = n & 1 ;
	ll yx1 = - (-a[y] + a[x]) + (-a[x] + a[y]) , yx2 = - (a[y] - a[x]) + (a[x] - a[y]) , ng ;

	bool ok = 1 ;
	ok &= (f[y + 1][ty1] + yx1 >= 0) ;
	ok &= (f[y + 1][ty2] + yx2 >= 0) ;

	if (ed == ty1) ng = g[n] + yx1 ;
	else ng = g[n] + yx2 ;
	ok &= (ng == 0) ;

	return ok ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		g[0] = 0 ; for (int i = 1 ; i <= n ; ++i) g[i] = a[i] - g[i - 1] ;

		///

		f[n][0] = f[n][1] = f[n - 1][0] = f[n - 1][1] = INF ;
		f[n][n & 1] = g[n] ; f[n - 1][(n - 1) & 1] = g[n - 1] ;

		for (int i = n - 2 ; i > 0 ; --i) {
			f[i][0] = f[i + 1][0] ; f[i][1] = f[i + 1][1] ;
			if (i & 1) f[i][1] = std::min(f[i + 2][1] , g[i]) ;
			else f[i][0] = std::min(f[i + 2][0] , g[i]) ;
		}

		///

		if (!g[n] && f[1][0] >= 0 && f[1][1] >= 0) {printf("YES\n") ; continue ;}

		bool ok = 0 ;
		for (int i = 1 ; i < n ; ++i) {
			ok |= work(i) ;
			if (g[i] < 0) break ;
		}

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}