#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define db double
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const db eps = 1e-6 , INF = 1e18 ;
const int MAX_N = 1e5 + 10 , MAX_M = 10 + 5 ;

struct data {
	int c , pre ;
}g[MAX_N][MAX_M] ;

db f[MAX_N][MAX_M] ;
int n , d , a[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &d) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	for (int i = 0 ; i <= 10 ; ++i) f[0][i] = -INF ;
	f[0][1] = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 0 ; j <= 10 ; ++j) {
			f[i][j] = f[i - 1][j] ;
			g[i][j] = (data){0 , j} ;
		}

		db val = log(a[i]) ;
		for (int j = 0 ; j <= 10 ; ++j) {
			int nj = j * a[i] % 10 ;
			db tmp = f[i - 1][j] + val ;

			if (f[i][nj] - tmp < eps) {
				f[i][nj] = tmp ;
				g[i][nj] = (data){1 , j} ;
			}
		}
	}

	if (f[n][d] < eps) printf("-1\n") ;
	else {
		int s = 0 , t = d ;
		for (int i = n ; i ; --i) {
			s += g[i][t].c ;
			t = g[i][t].pre ;
		}

		printf("%d\n" , s) ;
		t = d ;
		for (int i = n ; i ; --i) {
			if (g[i][t].c) printf("%d " , a[i]) ;
			t = g[i][t].pre ;
		}
		printf("\n") ;
	}

	return 0 ;
}