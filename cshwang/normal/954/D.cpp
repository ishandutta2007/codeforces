#include <queue>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 , INF = 0x3f3f3f3f ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

std::queue<int> que ;

Link *head[MAX_N] ;
bool ap[MAX_N] , eg[MAX_N][MAX_N] ;
int n , m , S , T , cur , dis[2][MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void spfa(int s , int ty) {
	for (int i = 1 ; i <= n ; ++i) dis[ty][i] = INF , ap[i] = 0 ;
	dis[ty][s] = 0 ; que.push(s) ; ap[s] = 1 ;

	for (; !que.empty() ;) {
		int x = que.front() ; que.pop() ;
		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ;
			if (ap[nx]) continue ;

			dis[ty][nx] = dis[ty][x] + 1 ;
			ap[nx] = 1 ; que.push(nx) ;
		}
	}
}

int main() {
	scanf("%d %d %d %d" , &n , &m , &S , &T) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ; eg[x][y] = eg[y][x] = 1 ;
	}

	///

	spfa(S , 0) ; spfa(T , 1) ;

	int ans = 0 , md = dis[0][T] ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = i + 1 ; j <= n ; ++j) {
			if (eg[i][j]) continue ;

			int tmp = std::min(dis[0][i] + dis[1][j] , dis[0][j] + dis[1][i]) + 1 ;
			if (tmp >= md) ++ans ;
		}

	printf("%d\n" , ans) ;

	return 0 ;
}