#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_L = 1e5 + 10 , MAX_N = 1e6 + 10 , MAX_M = 2e6 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_M] ;

std::stack<int> sta ;

Link *head[MAX_N] ;
int n , m , k , pl[MAX_N] ;
char s[10] , tmp[10] , ts[MAX_L][10] ;
int cur , tcol , tim , dfn[MAX_N] , low[MAX_N] , state[MAX_N] , col[MAX_N] , in[MAX_N] , queue[MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++tim ;
	state[x] = 1 ; sta.push(x) ;
	
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (state[nx] == 2) continue ;
		if (!state[nx]) tarjan(nx) ;
		
		low[x] = std::min(low[x] , low[nx]) ;
	}
	
	if (dfn[x] == low[x]) {
		while (sta.top() != x) {
			int nx = sta.top() ; sta.pop() ;
			
			state[nx] = 2 ; col[nx] = tcol ;
		}
		
		state[x] = 2 ; col[x] = tcol++ ; sta.pop() ;
	}
}

bool eql(int x) {
	for (int i = 0 ; i < k ; ++i) {
		if (ts[x][i] == '_') continue ;
		if (s[i] != ts[x][i]) return 0 ;
	}

	return 1 ;
}

int trans() {
	int bs = 1 , num = 0 ;
	for (int i = 0 ; i < k ; ++i) {
		int x = s[i] - 'a' ;
		if (s[i] == '_') x = 26 ;

		num += x * bs ;
		bs *= 27 ;
	}

	return num ;
}

void link(int x) {
	int S = 1 << k , rt ;
	for (int i = 0 ; i < k ; ++i) s[i] = ts[x][i] ;
	rt = trans() ;

	for (int i = 0 ; i < S ; ++i) {
		for (int j = 0 ; j < k ; ++j)
			if ((1 << j) & i) s[j] = '_' ;
			else s[j] = tmp[j] ;

		int nw = trans() ;
		if (pl[nw] == x || !pl[nw]) continue ;
		ins(rt , nw) ; ++in[nw] ;
	}
}

int main() {
	scanf("%d %d %d" , &n , &m , &k) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%s" , s) ;
		for (int j = 0 ; j < k ; ++j) ts[i][j] = s[j] ;

		pl[trans()] = i ;
	}

	///

	bool ans = 1 ;
	for (int i = 0 ; i < m ; ++i) {
		int x ; scanf("%s %d" , s , &x) ;
		for (int j = 0 ; j < k ; ++j) tmp[j] = s[j] ;

		if (!eql(x)) ans = 0 ;
		else link(x) ;
	}

	///

	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 0 ; j < k ; ++j) s[j] = ts[i][j] ;

		int x = trans() ;
		if (!state[x]) tarjan(x) ;
	}

	if (tcol != n) ans = 0 ;

	if (ans) {
		int L = 0 , R = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			for (int j = 0 ; j < k ; ++j) s[j] = ts[i][j] ;

			int x = trans() ;
			if (!in[x]) queue[++R] = x ;
		}

		for (; L < R ;) {
			int x = queue[++L] ;
			for (Link *h = head[x] ; h ; h = h->next) {
				int nx = h->num ;
				--in[nx] ;
				if (!in[nx]) queue[++R] = nx ;
			}
		}

		printf("YES\n") ;
		for (int i = 1 ; i <= n ; ++i) printf("%d " , pl[queue[i]]) ;
		printf("\n") ;
	}
	else printf("NO\n") ;

	return 0 ;
}