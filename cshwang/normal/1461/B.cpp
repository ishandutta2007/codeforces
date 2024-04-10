#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 500 + 10 ;

char a[MAX_N][MAX_N] ;
int T , n , m , sum[MAX_N][MAX_N] ;

int check(int x , int y) {
	int ans = 0 , l = y , r = y ;
	for (; ;) {
		if (l < 0 || r >= m || x + ans >= n) break ;

		int t = l ? (sum[x + ans][r] - sum[x + ans][l - 1]) : sum[x + ans][r] ;
		if (t != r - l + 1) break ;
		++ans ; --l ; ++r ;
	}

	return ans ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 0 ; i < n ; ++i) scanf("%s" , a[i]) ;

		for (int i = 0 ; i < n ; ++i) {
			sum[i][0] = a[i][0] == '*' ? 1 : 0 ;
			for (int j = 1 ; j < m ; ++j) sum[i][j] = sum[i][j - 1] + (a[i][j] == '*' ? 1 : 0) ;
		}

		///

		int s = 0 ;
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < m ; ++j) s += check(i , j) ;
		printf("%d\n" , s) ;
	}

	return 0 ;
}