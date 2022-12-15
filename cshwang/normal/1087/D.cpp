#include <stdio.h>
#include <stdlib.h>

#define db double
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const db eps = 1e-7 ;
const int MAX_N = 1e5 + 10 ;

struct Link {
	int num ; db val ;
	Link *next ;
}list[MAX_N << 1] ;
struct Edge {
	int x , y ;
}eg[MAX_N] ;

Link *head[MAX_N] ;
db dis[MAX_N] , mdis ;
int n , s , cur , mp , in[MAX_N] ;

void dfs(int x , int fa) {
	if (mdis - dis[x] < eps) mdis = dis[x] , mp = x ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dis[nx] = dis[x] + h->val ;
		dfs(nx , x) ;
	}
}

void ins(int x , int y , db v) {
	list[cur].num = y ;
	list[cur].val = v ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	scanf("%d %d" , &n , &s) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		eg[i] = (Edge){x , y} ;

		++in[x] ; ++in[y] ;
	}

	int sum = 0 ;
	for (int i = 1 ; i <= n ; ++i) if (in[i] == 1) ++sum ;
	if (n == 2) sum = 1 ;

	db v = s * 1.0 / sum ;
	for (int i = 1 ; i < n ; ++i) {
		Edge *p = &eg[i] ;

		if (in[p->x] == 1 || in[p->y] == 1) ins(p->x , p->y , v) , ins(p->y , p->x , v) ;
		else ins(p->x , p->y , 0) , ins(p->y , p->x , 0) ;
	}

	///

	dis[1] = 0 ; mdis = 0 ; dfs(1 , 1) ;
	dis[mp] = 0 ; mdis = 0 ; dfs(mp , mp) ;

	printf("%0.7lf\n" , mdis) ;

	return 0 ;
}