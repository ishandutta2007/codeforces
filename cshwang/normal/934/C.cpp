#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e3 + 10 ;

int cnt[2][MAX_N][MAX_N] ;
int n , a[MAX_N] , f[2][MAX_N][MAX_N] , g[2][MAX_N][MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	for (int i = 1 ; i <= n ; ++i)
		for (int j = i ; j <= n ; ++j) {
			f[0][i][j] = f[0][i][j - 1] ; f[1][i][j] = f[1][i][j - 1] ;

			if (a[j] == 1) f[0][i][j] = f[0][i][j - 1] + 1 ;
			else f[1][i][j] = std::max(f[0][i][j - 1] , f[1][i][j - 1]) + 1 ;
		}

	for (int i = 1 ; i <= n ; ++i)
		for (int j = i ; j <= n ; ++j) {
			g[0][i][j] = g[0][i][j - 1] ; g[1][i][j] = g[1][i][j -1] ;

			if (a[j] == 2) g[1][i][j] = g[1][i][j - 1] + 1 ;
			else g[0][i][j] = std::max(g[1][i][j - 1] , g[0][i][j - 1]) + 1 ;
		}

	for (int i = 1 ; i <= n ; ++i)
		for (int j = i ; j <= n ; ++j) {
			cnt[0][i][j] = cnt[0][i][j - 1] ; cnt[1][i][j] = cnt[1][i][j - 1] ;

			if (a[j] == 1) ++cnt[0][i][j] ;
			else ++cnt[1][i][j] ;
		}

	///

	int ans = std::max(f[0][1][n] , f[1][1][n]) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = i ; j <= n ; ++j) {
			int tmp = cnt[0][1][i - 1] + std::max(g[1][i][j] , g[0][i][j]) + cnt[1][j + 1][n] ;
			ans = std::max(ans , tmp) ;
		}

	printf("%d\n" , ans) ;

	return 0 ;
}