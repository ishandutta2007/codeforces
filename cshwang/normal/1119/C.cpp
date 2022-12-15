#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 500 + 10 ;

int n , m , A[MAX_N][MAX_N] , B[MAX_N][MAX_N] , r[MAX_N] , c[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j) scanf("%d" , &A[i][j]) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j) scanf("%d" , &B[i][j]) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j) {
			A[i][j] = abs(A[i][j] - B[i][j]) ;

			if (A[i][j]) ++r[i] , ++c[j] ;
		}

	///

	bool ans = 1 ;
	for (int i = 1 ; i <= n ; ++i) if (r[i] % 2) ans = 0 ;
	for (int i = 1 ; i <= m ; ++i) if (c[i] % 2) ans = 0 ;

	if (ans) printf("Yes\n") ;
	else printf("No\n") ;

	return 0 ;
}