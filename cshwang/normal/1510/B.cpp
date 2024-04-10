#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = (1 << 11) + 10 , MAX_M = 10 + 5 , MAX_E = (1 << 22) + 10 , INF = 0x3f3f3f3f ;

struct Link {
	int num , cap , cost ;
	Link *next , *reg ;
}list[MAX_E] ;

std::queue<int> q ;
std::vector<int> ans ;

char s[MAX_N][MAX_M] ;
Link *head[MAX_N] , *id[MAX_N] ;
bool st[MAX_N] , ud[MAX_M] , vis[MAX_N] ;
int n , m , tot , cur , pt[MAX_N][2] , lt[MAX_N] ;
int S , T , pre[MAX_N] , dis[MAX_N] , flow[MAX_N] ;

void ins(int x , int y , int f , int c) {
	list[cur].num = y ;
	list[cur].cap = f ;
	list[cur].cost = c ;
	list[cur].reg = &list[cur + 1] ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;

	list[cur].num = x ;
	list[cur].cap = 0 ;
	list[cur].cost = -c ;
	list[cur].reg = &list[cur - 1] ;
	list[cur].next = head[y] ;
	head[y] = &list[cur++] ;
}

///

bool spfa() {
	for (int i = 0 ; i <= tot ; ++i) dis[i] = INF , vis[i] = 0 ;
	vis[S] = 1 ; dis[S] = 0 ; flow[S] = INF ; q.push(S) ;

	while (!q.empty()) {
		int x = q.front() ; vis[x] = 0 ; q.pop() ;

		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ;
			if (dis[nx] <= dis[x] + h->cost || !h->cap) continue ;

			flow[nx] = std::min(flow[x] , h->cap) ;
			dis[nx] = dis[x] + h->cost ;
			pre[nx] = x ; id[nx] = h ;

			if (!vis[nx]) {vis[nx] = 1 ; q.push(nx) ;}
		}
	}

	return dis[T] < INF ;
}

void dinic() {
	while (spfa()) {
		int x = T ;
		for (; x != S ; x = pre[x]) {
			id[x]->cap -= flow[T] ;
			id[x]->reg->cap += flow[T] ;
		}
	}
}

///

int main() {
	scanf("%d %d" , &m , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%s" , s[i]) ;

	///

	for (int i = 1 ; i <= n ; ++i) pt[i][0] = ++tot , pt[i][1] = ++tot ;
	S = 0 ; T = ++tot ;

	for (int i = 1 ; i <= n ; ++i) {
		int cnt = 1 ;
		for (int j = 0 ; j < m ; ++j) if (s[i][j] == '1') ++cnt ;

		for (int j = 1 ; j <= n ; ++j) {
			if (i == j) continue ;

			bool ok = 1 ;
			for (int k = 0 ; k < m ; ++k) if (s[i][k] == '1' && s[j][k] == '0') ok = 0 ;
			if (ok) ins(pt[i][0] , pt[j][1] , 1 , -cnt) ;
		}
	}

	for (int i = 1 ; i <= n ; ++i)
		ins(S , pt[i][0] , 1 , 0) , ins(pt[i][1] , T , 1 , 0) ;

	///

	dinic() ;
	for (int i = 1 ; i <= n ; ++i) {
		int x = pt[i][0] ;
		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ;
			if (h->cap || !nx) continue ;

			nx >>= 1 ;
			lt[(x + 1) >> 1] = nx ; st[nx] = 1 ;
		}
	}

	///

	for (int i = 1 ; i <= n ; ++i)
		if (!st[i]) {
			for (int j = 0 ; j < m ; ++j) ud[j] = 0 ;
			for (int j = i ; j ; j = lt[j])
				for (int k = 0 ; k < m ; ++k)
					if (s[j][k] == '1' && !ud[k]) ans.push_back(k) , ud[k] = 1 ;
			ans.push_back(-1) ;
		}

	int m = ans.size() - 1 ;
	printf("%d\n" , m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x = ans[i] ;
		if (x == -1) printf("R ") ;
		else printf("%d " , x) ;
	}
	printf("\n") ;

	return 0 ;
}