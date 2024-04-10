#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 2e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[2 * MAX_N] ;

bool vis[MAX_N] ;
Link *head[MAX_N] ;
int n , m , k , cur , tot , et[2 * MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;

	head[x] = &list[cur++] ;
}

void dfs(int x) {
	vis[x] = 1 ;
	et[tot++] = x ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (vis[nx]) continue ;

		dfs(nx) ;
		et[tot++] = x ;
	}
}

int main() {
	scanf("%d %d %d" , &n , &m , &k) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;

		ins(x , y) ; ins(y , x) ;
	}

	///
	
	dfs(1) ;

	///
	
	int ep = tot / k , sp = tot % k , p = 0 ;
	for (int i = 0 ; i < k ; ++i) {
		int s = ep ;
		if (i < sp) ++s ;

		printf("%d " , s) ;
		for (int j = 0 ; j < s ; ++j , ++p) printf("%d " , et[p]) ;
		printf("\n") ;
	}

	return 0 ;
}