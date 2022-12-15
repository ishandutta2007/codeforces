#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e15 ;
const int MAX_N = 5e3 + 10 ;

struct data {int p ; ll c ;}h[MAX_N] , que[MAX_N] ;

ll offset , f[2][MAX_N] ;
int n , m , L , R , x[MAX_N] ;

bool cmp(data a , data b) {return a.p < b.p ;}

ll dis(int a , int b) {return abs(x[a] - h[b].p) ;}

void push(data x) {
	for (; que[R].c >= x.c && R >= L ; --R) ;
	que[++R] = x ;
}

void pop(int x) {
	if (que[L].p == x) ++L ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &x[i]) ;
	for (int i = 1 ; i <= m ; ++i) scanf("%d %lld" , &h[i].p , &h[i].c) ;

	///

	std::sort(x + 1 , x + 1 + n) ;
	std::sort(h + 1 , h + 1 + m , cmp) ;

	///

	for (int j = 1 ; j <= n ; ++j) f[0][j] = INF ;

	int np = 1 ;
	for (int i = 1 ; i <= m ; ++i , np ^= 1) {
		for (int j = 1 ; j <= n ; ++j) f[np][j] = INF ;

		L = 1 ; R = 0 ; offset = 0 ;
		f[np][1] = std::min(f[np^1][1] , dis(1 , i)) ;
		push((data){0 , dis(1 , i)}) ; push((data){1 , f[np^1][1]}) ;

		for (int j = 2 ; j <= n ; ++j) {
			pop(j - h[i].c - 1) ; offset += dis(j , i) ;
			push((data){j , f[np^1][j] - offset}) ;

			f[np][j] = que[L].c + offset ;
		}
	}

	np ^= 1 ;
	if (f[np][n] == INF) printf("-1\n") ;
	else printf("%lld\n" , f[np][n]) ;

	return 0 ;
}