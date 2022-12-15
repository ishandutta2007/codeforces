#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e16 ;
const int MAX_N = 2e5 + 10 , MAX_L = 4e5 + 10 ;

struct Link {
	int num , val ;
	Link *next ;
}list[MAX_L] ;
struct data {
	int idx ; ll val ;

	friend ll operator +(data a , data b) {return a.val + b.val ;}
	friend data operator +(data a , int x) {return (data){a.idx , a.val + x} ;}
	friend bool operator <(data a , data b) {return a.val < b.val || (a.val == b.val && a.idx < b.idx) ;}
	friend bool operator >(data a , data b) {return a.val > b.val || (a.val == b.val && a.idx > b.idx) ;}
}f[MAX_N] , pf[MAX_L][2] ;

std::set<data> que[2] ;

ll s[MAX_L] ;
bool cir[MAX_N] ;
Link *head[MAX_N] ;
int n , tot , st , ed , cur , fa[MAX_N] , pre[MAX_N] , val[MAX_N] , lt[MAX_L] ;

int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

void dfs(int x) {
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == pre[x]) continue ;

		pre[nx] = x ; val[nx] = h->val ;
		dfs(nx) ;
	}
}

void dp(int x , int fa) {
	f[x] = (data){x , 0} ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa || cir[nx]) continue ;

		dp(nx , x) ;
		f[x] = std::max(f[x] , f[nx] + h->val) ;
	}
}

void ins(int x , int y , int v) {
	list[cur].num = y ;
	list[cur].val = v ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void add(int x) {
	if (x != st) add(pre[x]) ;

	cir[x] = 1 ; lt[++tot] = x ;
}

ll getpath(int x) {
	dp(x , x) ;

	int p = f[x].idx ;
	dp(p , p) ;

	return f[p].val ;
}

void push(int x) {que[0].insert(pf[x][0]) ; que[1].insert(pf[x][1]) ;}

void pop(int x) {
	if (x <= 0) return ;

	que[0].erase(pf[x][0]) ; que[1].erase(pf[x][1]) ;
}

int main() {
	scanf("%d" , &n) ;

	for (int i = 1 ; i <= n ; ++i) fa[i] = -1 ;
	for (int i = 0 ; i < n ; ++i) {
		int x , y , v ;
		scanf("%d %d %d" , &x , &y , &v) ;

		///

		int fx = findset(x) , fy = findset(y) ;
		if (fx == fy) {st = x ; ed = y ; val[x] = v ;}
		else ins(x , y , v) , ins(y , x , v) , fa[fx] = fy ;
	}

	///

	dfs(st) ;
	add(ed) ;

	int o = tot ;
	for (int i = 1 ; i <= o ; ++i) lt[++tot] = lt[i] ;

	s[1] = 0 ;
	for (int i = 2 ; i <= tot ; ++i) s[i] = s[i - 1] + val[lt[i]] ;

	///

	ll init = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (!cir[i]) continue ;

		cir[i] = 0 ;

		init = std::max(init , getpath(i)) ;
		dp(i , i) ;

		cir[i] = 1 ;
	}

	///

	ll ans = INF ;

	for (int i = 1 ; i <= tot ; ++i)
		pf[i][0] = (data){i , f[lt[i]].val + s[i]} ,
		pf[i][1] = (data){i , f[lt[i]].val - s[i]} ;

	for (int i = 1 ; i <= tot ; ++i) {
		pop(i - o) ; push(i) ;

		if (i < o) continue ;

		ll s1 = 0 , s2 = 0 ;
		std::set<data> :: iterator p1 = que[0].end() , p2 = que[0].end() , q1 = que[1].end() , q2 = que[1].end() ;
		--p1 ; --p2 ; --q1 ; --q2 ; --p2 ; --q2 ;

		if (p1->idx != q1->idx) s1 = *p1 + *q1 ;
		else {s1 = *p1 + *q2 ; s2 = *p2 + *q1 ;}

		ans = std::min(ans , std::max(init , std::max(s1 , s2))) ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}