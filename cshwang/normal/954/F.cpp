#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e4 + 10 , MAX_K = 5 , mod = 1e9 + 7 ;

struct data {int a ; ll l , r ;}t[MAX_N] ;

ll m , pt[MAX_N] ;
int n , tot , cnt[3] , ad[MAX_N][3] ;
int A[MAX_K][MAX_K] , B[MAX_K][MAX_K] , C[MAX_K][MAX_K] , T[MAX_K][MAX_K] ;

void init() {
	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			if (abs(i - j) <= 1) B[i][j] = 1 ;
			else B[i][j] = 0 ;

	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			if (cnt[j]) B[i][j] = 0 ;

	for (int i = 0 ; i < 3 ; ++i)
		for (int j = 0 ; j < 3 ; ++j)
			C[i][j] = B[i][j] ;
}

void times(int (*A)[MAX_K] , int (*B)[MAX_K] , int n , int m) {
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; ++j) {
			T[i][j] = 0 ;
			for (int r = 0 ; r < 3 ; ++r) (T[i][j] += (ll)A[i][r] * B[r][j] % mod) %= mod ;
		}

	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; ++j)
			B[i][j] = T[i][j] ;
}

void qpow(ll t) {
	if (t == 1) return ;

	qpow(t >> 1) ;
	times(B , B , 3 , 3) ;
	if (t & 1) times(C , B , 3 , 3) ;
}

int find(ll x) {
	for (int i = 0 ; i < tot ; ++i)
		if (pt[i] == x) return i ;
}

int main() {
	scanf("%d %lld" , &n , &m) ; pt[tot++] = m ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d %lld %lld" , &t[i].a , &t[i].l , &t[i].r) ;
		pt[tot++] = t[i].l ; pt[tot++] = t[i].r + 1 ;
	}

	///

	std::sort(pt + 0 , pt + tot) ;
	tot = std::unique(pt + 0 , pt + tot) - pt ;

	for (int i = 0 ; i < n ; ++i) {
		data *p = &t[i] ;

		++ad[find(p->l)][p->a - 1] ;
		--ad[find(p->r + 1)][p->a - 1] ;
	}

	A[0][0] = A[2][0] = 0 ; A[1][0] = 1 ;

	///

	ll last = 1 ;
	for (int i = 0 ; i < tot ; ++i) {
		init() ;
		qpow(pt[i] - last) ;
		times(B , A , 3 , 1) ;

		for (int j = 0 ; j < 3 ; ++j) cnt[j] += ad[i][j] ;
		for (int j = 0 ; j < 3 ; ++j) if (cnt[j]) A[j][0] = 0 ;

		last = pt[i] ;
	}

	printf("%d\n" , A[1][0]) ;

	return 0 ;
}