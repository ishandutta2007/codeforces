#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n , m , a[MAX_N] , b[MAX_N] , f[MAX_N][MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	scanf("%d" , &m) ;
	for (int i = 1 ; i <= m ; ++i) scanf("%d" , &b[i]) ;

	///

	std::sort(a + 1 , a + 1 + n) ;
	std::sort(b + 1 , b + 1 + m) ;

	///

	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j) {
			f[i][j] = std::max(f[i][j - 1] , f[i - 1][j]) ;
			if (abs(a[i] - b[j]) <= 1) f[i][j] = std::max(f[i][j] , f[i - 1][j - 1] + 1) ;
		}

	printf("%d\n" , f[n][m]) ;

	return 0 ;
}