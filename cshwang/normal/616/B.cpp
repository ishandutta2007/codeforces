#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n , m , a[MAX_N][MAX_N] ;

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; ++j) scanf("%d" , &a[i][j]) ;

	///

	int ans = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int tmp = a[i][0] ;
		for (int j = 1 ; j < m ; ++j) tmp = std::min(tmp , a[i][j]) ;
		ans = std::max(ans , tmp) ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}