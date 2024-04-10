#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

ll BIT[MAX_N] ;
Link *head[MAX_N] ;
int n , q , ti , cur , a[MAX_N] , siz[MAX_N] , fa[MAX_N] , lfa[MAX_N] , dfn[MAX_N] , dep[MAX_N] ;

///

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs1(int x , int f) {
	siz[x] = 1 ; fa[x] = f ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == f) continue ;

		dep[nx] = dep[x] + 1 ;
		dfs1(nx , x) ; siz[x] += siz[nx] ;
	}
}

void dfs2(int x , int f) {
	dfn[x] = ++ti ; lfa[x] = f ;

	int hson = -1 , s = -1 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa[x]) continue ;

		if (s < siz[nx]) s = siz[nx] , hson = nx ;
	}

	if (hson != -1) dfs2(hson , f) ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa[x] || nx == hson) continue ;

		dfs2(nx , nx) ;
	}
}

///

inline int lowbit(int x) {return x & (-x) ;}

void add(int x , int y) {
	for (; x <= n ; x += lowbit(x)) BIT[x] += y ;
}

ll calc(int x) {
	ll s = 0 ;
	for (; x ; x -= lowbit(x)) s += BIT[x] ;

	return s ;
}

inline ll getsum(int x , int y) {
	return calc(y) - calc(x - 1) ;
}

ll query(int x , int y) {
	ll res = 0 ;
	for (; lfa[x] != lfa[y] ;) {
		if (dep[lfa[x]] > dep[lfa[y]]) std::swap(x , y) ;

		res += getsum(dfn[lfa[y]] , dfn[y]) ; y = fa[lfa[y]] ;
	}

	if (dep[x] > dep[y]) std::swap(x , y) ;
	return res + getsum(dfn[x] , dfn[y]) ;
}

///

int main() {
	scanf("%d %d" , &n , &q) ;
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d" , &a[i]) , a[i] = abs(a[i]) ;
	
	for (int i = 1 ; i < n ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///

	dep[1] = 1 ;
	dfs1(1 , 1) ; dfs2(1 , 1) ;
	for (int i = 1 ; i <= n ; ++i) add(dfn[i] , a[i]) ;

	for (; q-- ;) {
		int op , x , y ;
		scanf("%d %d %d" , &op , &x , &y) ;

		if (op == 1) {
			y = abs(y) ;
			add(dfn[x] , -a[x]) ; add(dfn[x] , y) ; a[x] = y ;
		}
		else {
			ll res = query(x , y) ;
			res <<= 1 ; res -= a[x] + a[y] ;
			printf("%lld\n" , res) ;
		}
	}

	return 0 ;
}