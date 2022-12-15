#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 2e5 + 10 , MAX_K = 10 ;

struct Link {
	int num ;
	Link *next ;
}list[2 * MAX_N] ;

Link *head[MAX_N] ;
long long S , g[MAX_K] , temp[MAX_N][MAX_K] ;
int n , k , cur , dep[MAX_N] , siz[MAX_N] , fa[MAX_N] , f[MAX_N][MAX_K] ;

void dfs(int x) {
	siz[x] = 1 ;
	f[x][dep[x] % k] = 1 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa[x]) continue ;

		fa[nx] = x ;
		dep[nx] = dep[x] + 1 ;
		dfs(nx) ;
		
		siz[x] += siz[nx] ;
		for (int j = 0 ; j < k ; ++j)
			f[x][j] += f[nx][j] ;

		S += (long long)siz[nx] * (n - siz[nx]) ;
	}
}

void GetG(int x) {
	temp[x][dep[x] % k] = 1 ;
	for (Link *h = head[x] ; h ; h = h ->next) {
		int nx = h->num ;
		if (nx == fa[x]) continue ;

		GetG(nx) ;
		for (int p = 0 ; p < k ; ++p)
			for (int q = 0 ; q < k ; ++q) {
				long long tot = temp[x][p] * f[nx][q] ;
				int ny = (2 * dep[x]) % k , ys = (p + q - ny + k) % k ;
				
				if (ys > 0) S += tot * (k - ys) ;
			}

		for (int i = 0 ; i < k ; ++i)
			temp[x][i] += f[nx][i] ;
	}
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///

	fa[1] = -1 ; dep[1] = 0 ;
	dfs(1) ;
	GetG(1) ;

	///

	printf("%I64d\n" , S / k) ;

	return 0 ;
}