#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n , m , h , a[MAX_N] , b[MAX_N] , res[MAX_N][MAX_N] ;

int main() {
	scanf("%d %d %d" , &n , &m , &h) ;
	for (int i = 1 ; i <= m ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &b[i]) ;

	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j) {
			int ty ; scanf("%d" , &ty) ;

			if (ty) res[i][j] = std::min(b[i] , a[j]) ;
		}

	for (int i = 1 ; i <= n ; ++i , printf("\n"))
		for (int j = 1 ; j <= m ; ++j) printf("%d " , res[i][j]) ;

	return 0 ;
}