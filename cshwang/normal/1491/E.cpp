#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int N = 2e5 , MAX_N = 2e5 + 10 ;

struct Link {
	int num ; bool ck ;
	Link *next , *reg ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
int n , cur , siz[MAX_N] , fib[MAX_N] , pl[MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	list[cur].reg = &list[cur^1] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int f) {
	siz[x] = 1 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num	;
		if (h->ck || nx == f) continue ;

		dfs(nx , x) ; siz[x] += siz[nx] ;
	}
}

bool cut(int x , int f , int tot , int ned) {
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (h->ck || nx == f) continue ;

		if (siz[nx] == ned || siz[nx] == tot - ned) {
			h->ck = h->reg->ck = 1 ;
			return 1 ;
		}
		if (cut(nx , x , tot , ned)) return 1 ;
	}

	return 0 ;
}

int main() {
	fib[0] = fib[1] = 1 ; pl[1] = 1 ;
	int cnt = 2 ;
	for (; fib[cnt - 1] + fib[cnt - 2] <= N ;) {
		fib[cnt] = fib[cnt - 1] + fib[cnt - 2] ;
		pl[fib[cnt]] = cnt ; ++cnt ;
	}

	///

	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	bool ok = pl[n] ;
	for (int i = pl[n] ; i > 1 && ok ; --i)
		for (int j = 1 ; j <= n && ok ; ++j) {
			dfs(j , j) ;

			int tmp = siz[j] ;
			if (tmp == 1) continue ;
			if (!pl[tmp]) {ok = 0 ; break ;}

			ok &= cut(j , j , tmp , fib[pl[tmp] - 1]) ;
		}

	if (ok) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}