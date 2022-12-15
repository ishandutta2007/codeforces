#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 , INF = 0x3f3f3f3f ;

std::vector<int> lk[MAX_N] , p1[MAX_N][MAX_N] , p2[MAX_N][MAX_N] ;

int T , n , k , siz[MAX_N] , f[MAX_N][MAX_N] , g[MAX_N][MAX_N] ;

void init() {
	for (int i = 1 ; i <= n ; ++i) lk[i].clear() ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= n ; ++j) {
			f[i][j] = g[i][j] = INF ;
			p1[i][j].clear() ; p2[i][j].clear() ;
		}
}

void dfs(int x) {
	siz[x] = 1 ;
	f[x][1] = g[x][1] = 1 ;
	p1[x][1].clear() ; p2[x][1].clear() ;
	p1[x][1].push_back(x) ; p2[x][1].push_back(x) ;

	///

	int m = lk[x].size() ;
	for (int i = 0 ; i < m ; ++i) {
		int nx = lk[x][i] ;
		dfs(nx) ;

		///

		int ns = siz[x] + siz[nx] , os = siz[nx] ;
		for (int j = ns ; j > 1 ; --j) {
			int p = -1 , ty = -1 ;
			for (int k = 1 ; k <= std::min(j , os) ; ++k) {
				int tmp = g[nx][k] + f[x][j - k] ;
				if (tmp < g[x][j]) {g[x][j] = tmp ; p = k ; ty = 0 ;}
			}
			for (int k = 1 ; k <= std::min(j , os) ; ++k) {
				int tmp = f[nx][k] + g[x][j - k] + 1 ;
				if (tmp < g[x][j]) {g[x][j] = tmp ; p = k ; ty = 1 ;}
			}

			if (!ty) {
				p2[x][j].clear() ;
				int s1 = p1[x][j - p].size() , s2 = p2[nx][p].size() ;
				for (int k = 0 ; k < s1 ; ++k) p2[x][j].push_back(p1[x][j - p][k]) ;
				for (int k = 0 ; k < s2 ; ++k) p2[x][j].push_back(p2[nx][p][k]) ;
			}
			else if (ty == 1) {
				p2[x][j].clear() ; p2[x][j].push_back(x) ;
				int s1 = p1[nx][p].size() , s2 = p2[x][j - p].size() ;
				for (int k = 0 ; k < s1 ; ++k) p2[x][j].push_back(p1[nx][p][k]) ;
				for (int k = 0 ; k < s2 ; ++k) p2[x][j].push_back(p2[x][j - p][k]) ;
			}
		}

		for (int j = ns ; j > 1 ; --j) {
			int p = -1 ;
			for (int k = 1 ; k <= std::min(j , os) ; ++k) {
				int tmp = f[x][j - k] + f[nx][k] + 1 ;
				if (tmp < f[x][j]) {f[x][j] = tmp ; p = k ;}
			}

			if (p != -1) {
				p1[x][j].clear() ;
				int s1 = p1[x][j - p].size() , s2 = p1[nx][p].size() ;
				for (int k = 0 ; k < s1 ; ++k) p1[x][j].push_back(p1[x][j - p][k]) ;
				for (int k = 0 ; k < s2 ; ++k) p1[x][j].push_back(p1[nx][p][k]) ;
				p1[x][j].push_back(x) ;
			}
		}

		siz[x] = ns ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ; init() ;
		for (int i = 2 ; i <= n ; ++i) {
			int x ; scanf("%d" , &x) ;
			lk[x].push_back(i) ;
		}

		///

		dfs(1) ;

		printf("%d\n" , g[1][k] - 1) ;
		int s = p2[1][k].size() ;
		for (int i = 0 ; i < s ; ++i) printf("%d " , p2[1][k][i]) ;
		printf("\n") ;
	}

	return 0 ;
}