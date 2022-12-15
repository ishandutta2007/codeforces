#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

struct data {
	int dis , rt ;
}tre[MAX_N] ;

bool ap[MAX_N] ;
Link *head[MAX_N] ;
int n , m , cur , md , rt , cnt , f[MAX_N] , g[MAX_N] ;

void getf(int x , int fa) {
	ap[x] = 1 ; f[x] = 0 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		getf(nx , x) ;
		f[x] = std::max(f[x] , f[nx] + 1) ;
	}
}

void getg(int x , int fa) {
	int d1 = -1 , d2 = -1 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		if (f[nx] >= d1) d2 = d1 , d1 = f[nx] ;
		else if (f[nx] > d2) d2 = f[nx] ;
	}

	int tmp = std::max(f[x] , g[x]) ;
	if (tmp < md) md = tmp , rt = x ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		if (f[nx] == d1) g[nx] = std::max(d2 + 2 , g[x] + 1) ;
		else g[nx] = std::max(d1 + 2 , g[x] + 1) ;

		getg(nx , x) ;
	}
}

void dfs(int x , int fa) {
	if (f[x] > md) md = f[x] , rt = x ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		f[nx] = f[x] + 1 ;
		dfs(nx , x) ;
	}
}

bool cmp(data x , data y) {return x.dis > y.dis ;}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///

	for (int i = 1 ; i <= n ; ++i)
		if (!ap[i]) {
			md = n ;
			getf(i , i) ; getg(i , i) ;

			tre[cnt++] = (data){md , rt} ;
		}

	std::sort(tre + 0 , tre + cnt , cmp) ;

	for (int i = 1 ; i < cnt ; ++i) ins(tre[0].rt , tre[i].rt) , ins(tre[i].rt , tre[0].rt) ;
	f[1] = 0 ; md = -1 ; dfs(1 , 1) ;
	f[rt] = 0 ; md = -1 ; dfs(rt , rt) ;

	printf("%d\n" , md) ;
	for (int i = 1 ; i < cnt ; ++i) printf("%d %d\n" , tre[0].rt , tre[i].rt) ;

	return 0 ;
}