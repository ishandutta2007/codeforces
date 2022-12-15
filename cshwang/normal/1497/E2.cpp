#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 , MAX_K = 20 + 5 , MAX_M = 1e7 + 10 ;

bool ap[MAX_M] ;
int f[MAX_N][MAX_K] , g[MAX_N][MAX_K] , cnt[MAX_M] ;
int T , n , k , tot , a[MAX_N] , pri[MAX_M] , fir[MAX_M] ;

void init() {
	int n = 1e7 ;
	for (int i = 2 ; i <= n ; ++i) {
		if (!ap[i]) {pri[tot++] = i ; fir[i] = i ;}

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * pri[j] ;
			if (tmp > n) break ;
			ap[tmp] = 1 ; fir[tmp] = pri[j] ;

			if (!(i % pri[j])) break ;
		}
	}
}

int work(int x) {
	int s = 1 ;
	for (; x > 1 ;) {
		int a = fir[x] , c = 0 ;
		for (; fir[x] == a ; x /= a , ++c) ;

		if (c & 1) s *= a ;
	}

	return s ;
}

int main() {
	init() ;

	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (int i = 1 ; i <= n ; ++i) {
			int t ;
			scanf("%d" , &t) ;
			a[i] = work(t) ;
		}

		///

		for (int j = 0 ; j <= k ; ++j) {
			for (int i = 1 ; i <= n ; ++i) cnt[a[i]] = 0 ;

			int l = 1 , k = 0 ;
			for (int i = 1 ; i <= n ; ++i) {
				int nw = a[i] ;
				if (cnt[nw]) ++k ;
				++cnt[nw] ;

				for (; k > j ;) {
					if (cnt[a[l]] > 1) --k ;
					--cnt[a[l]] ; ++l ;
				}

				g[i][j] = l ;
			}
		}

		for (int i = 0 ; i <= k ; ++i) f[0][i] = 0 ;
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 0 ; j <= k ; ++j) {
				f[i][j] = n ;

				for (int p = 0 ; p <= j ; ++p) f[i][j] = std::min(f[i][j] , f[g[i][p] - 1][j - p] + 1) ;
			}

		int ans = f[n][0] ;
		for (int i = 1 ; i <= k ; ++i) ans = std::min(ans , f[n][i]) ;
		printf("%d\n" , ans) ;
	}

	return 0 ;
}