#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 500 + 10 , dx[2] = {0 , 1} , dy[2] = {-1 , 0} ;

int n , a[MAX_N] , ans[MAX_N][MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	for (int i = 1 ; i <= n ; ++i) ans[i][i] = a[i] ;
	for (int i = 1 ; i <= n ; ++i) {
		int nw = a[i] , x = i , y = i ;
		for (int j = 1 ; j < nw ; ++j) {
			int op = 0 ;
			if (y + dy[0] >= 1 && !ans[x + dx[0]][y + dy[0]]) op = 0 ;
			else op = 1 ;

			x += dx[op] ; y += dy[op] ;
			ans[x][y] = nw ;
		}
	}

	for (int i = 1 ; i <= n ; ++i , printf("\n"))
		for (int j = 1 ; j <= i ; ++j) printf("%d " , ans[i][j]) ;

	return 0 ;
}