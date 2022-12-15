#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 4e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N] ;

ll ans[MAX_N] ;
bool ap[MAX_N] ;
Link *head[MAX_N] ;
int T , n , cur , siz[MAX_N] , fa[MAX_N] ;

void init() {
	cur = 0 ;
	for (int i = 0 ; i <= n + 1 ; ++i)
		ans[i] = 0 , ap[i] = 0 , head[i] = NULL ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int f) {
	siz[x] = 1 ; fa[x] = f ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == f) continue ;

		dfs(nx , x) ; siz[x] += siz[nx] ;
	}
}

bool extend(int &p1 , int &p2 , int x) {
	if (ap[x]) return 1 ;

	int t = x ;
	for (; !ap[t] ; t = fa[t]) ap[t] = 1 ;

	if (t == p1) {p1 = x ; return 1 ;}
	else if (t == p2) {p2 = x ; return 1 ;}
	else return 0 ;
}

ll cal(int x) {
	if (siz[x] == n) {
		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ;
			if (ap[nx]) siz[x] -= siz[nx] ;
		}
	}

	return siz[x] ;
}

void work() {
	ll nw = 0 ;
	for (Link *h = head[0] ; h ; h = h->next) {
		int nx = h->num ;
		ans[1] += siz[nx] * (nw + 1) ; nw += siz[nx] ;
	}

	///

	ap[0] = 1 ;
	int p1 = 0 , p2 = 0 ;
	for (int i = 1 ; i < n ; ++i)
		if (extend(p1 , p2 , i)) ans[i + 1] = cal(p1) * cal(p2) ;
		else break ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		init() ;

		scanf("%d" , &n) ;
		for (int i = 1 ; i < n ; ++i) {
			int x , y ; scanf("%d %d" , &x , &y) ;
			ins(x , y) ; ins(y , x) ;
		}

		///

		dfs(0 , 0) ;
		ans[0] = ((ll)n * (n - 1)) >> 1 ;
		work() ;

		ll pre = ans[n] ;
		for (int i = n - 1 ; i >= 0 ; --i) {
			if (!ans[i]) continue ;
			ll tmp = ans[i] ;
			ans[i] -= pre ; pre = tmp ;
		}
		for (int i = 0 ; i <= n ; ++i) printf("%lld " , ans[i]) ;
		printf("\n") ;
	}

	return 0 ;
}