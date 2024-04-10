#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N] ;

int n , cur ;
Link *head[MAX_N] ;
bool son[MAX_N] , ans ;

void dfs(int x) {
	int cnt = 0 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;

		if (son[nx]) ++cnt ;
		else dfs(nx) ;
	}

	if (cnt < 3) ans = 0 ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) son[i] = 1 ;
	for (int i = 2 ; i <= n ; ++i) {
		int x ; scanf("%d" , &x) ;
		son[x] = 0 ; ins(x , i) ;
	}

	ans = 1 ; dfs(1) ;

	if (ans) printf("Yes\n") ;
	else printf("No\n") ;

	return 0 ;
}