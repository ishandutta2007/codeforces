#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DBEUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 5e17 ;
const int MAX_N = 2e5 + 10 , MAX_E = 6e5 + 10 ;

struct Link {
	int num ; ll val ;
	Link *next ;
}list[MAX_E] ;

ll dis[MAX_N] ;
bool ap[MAX_N] ;
Link *head[MAX_N] ;
int n , m , cur , tot , hp[MAX_N] , pl[MAX_N] ;

///

void swp(int x , int y) {
	int px = pl[x] , py = pl[y] ;
	std::swap(hp[px] , hp[py]) ; std::swap(pl[x] , pl[y]) ;
}

void update(int x) {
	for (int p = pl[x] ; p > 1 ;) {
		int fa = p >> 1 ;
		if (dis[hp[fa]] > dis[hp[p]]) swp(hp[fa] , hp[p]) , p = fa ;
		else break ;
	}
}

void push(int x) {
	++tot ; hp[tot] = x ; pl[x] = tot ;
	update(x) ;
}

int getmin(int x) {
	int L = x << 1 , R = L + 1 ;
	if (R > tot) return L ;
	else if (dis[hp[L]] > dis[hp[R]]) return R ;
	else return L ;
}

void pop() {
	swp(hp[1] , hp[tot--]) ;

	for (int p = 1 ; (p << 1) <= tot ;) {
		int son = getmin(p) ;

		if (dis[hp[son]] < dis[hp[p]]) swp(hp[son] , hp[p]) , p = son ;
		else break ;
	}
}

///

void dij() {
	dis[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) dis[i] = INF ;

	push(0) ;
	for (; tot ;) {
		int x = hp[1] ; pop() ;

		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ; ll nd = dis[x] + h->val ;

			if (dis[nx] > nd) {
				dis[nx] = nd ;
				if (!ap[nx]) {push(nx) ; ap[nx] = 1 ;}
				else update(nx) ;
			}
		}
	}
}

void ins(int x , int y , ll v) {
	list[cur].num = y ;
	list[cur].val = v ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

///

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y ; ll v ;
		scanf("%d %d %lld" , &x , &y , &v) ; v <<= 1 ;

		ins(x , y , v) ; ins(y , x , v) ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		ll a ; scanf("%lld" , &a) ;
		ins(0 , i , a) ;
	}

	///

	dij() ;

	for (int i = 1 ; i <= n ; ++i) printf("%lld " , dis[i]) ;
	printf("\n") ;

	return 0 ;
}