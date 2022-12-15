#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 , mod = (119 << 23) + 1 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
int n , cur , son[MAX_N] , f[MAX_N] , jc[MAX_N] , siz[MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int f) {
	siz[x] = 1 ; son[x] = 0 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == f) continue ;

		dfs(nx , x) ;
		siz[x] += siz[nx] ; ++son[x] ;
	}
}

void dp(int x , int fa) {
	int s = x == 1 ? n : (son[x] + 1) ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dp(nx , x) ;
		s = (ll)s * f[nx] % mod ;
	}

	f[x] = (ll)s * jc[son[x]] % mod ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;

		ins(x , y) ; ins(y , x) ;
	}

	///

	dfs(1 , 1) ;

	jc[1] = jc[0] = 1 ;
	for (int i = 2 ; i <= n ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;

	dp(1 , 1) ;
	printf("%d\n" , f[1]) ;

	return 0 ;
}