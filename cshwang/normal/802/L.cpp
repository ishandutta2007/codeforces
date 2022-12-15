#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 , mod = 1e9 + 7 ;

struct Link {
	int num , val ;
	Link *next ;
}list[MAX_N << 1] ;
struct data {
	int a , b ;

	data friend operator +(data x , data y) {
		return (data){((ll)x.a + y.a + mod) % mod , ((ll)x.b + y.b + mod) % mod} ;
	}
	data friend operator *(data x , int y) {
		return (data){(ll)x.a * y % mod , (ll)x.b * y % mod} ;
	}
}f[MAX_N] ;

Link *head[MAX_N] ;
int n , cur , d[MAX_N] ;

void ins(int x , int y , int v) {
	list[cur].num = y ;
	list[cur].val = v ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int qpow(int x , int t) {
	if (t == 1) return x ;

	int s = qpow(x , t >> 1) ;
	s = (ll)s * s % mod ;
	if (t & 1) s = (ll)s * x % mod ;

	return s ;
}

void dfs(int x , int fa) {
	bool son = 1 ;
	data tmp = (data){mod - d[x] , 0} ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) {(tmp.b += h->val) %= mod ; continue ;}

		dfs(nx , x) ; son = 0 ;
		tmp = tmp + f[nx] ; (tmp.b += h->val) %= mod ;
	}

	if (son) f[x] = (data){0 , 0} ;
	else {
		int ny = qpow(mod - tmp.a , mod - 2) ;
		tmp.a = 1 ; f[x] = tmp * ny ;
	}
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y , v ; scanf("%d %d %d" , &x , &y , &v) ;
		ins(x , y , v) ; ins(y , x , v) ; ++d[x] ; ++d[y] ;
	}

	///

	dfs(0 , 0) ;

	printf("%d\n" , f[0].b) ;

	return 0 ;
}