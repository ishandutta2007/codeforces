#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int N = 2e5 , MAX_N = 2e5 + 10 , MAX_C = 10 + 5 , mod = 1e9 + 7 ;

int T , n , k , f[MAX_C][MAX_N] ;

void init() {
	for (int i = 0 ; i < 10 ; ++i) f[i][0] = 1 ;
	for (int j = 1 ; j <= N ; ++j) {
		f[9][j] = (f[1][j - 1] + f[0][j - 1]) % mod ;
		for (int i = 0 ; i < 9 ; ++i) f[i][j] = f[i + 1][j - 1] ;
	}
}

int main() {
	init() ;

	scanf("%d" , &T) ;
	for (; T-- ;) {
		int ans = 0 ;
		scanf("%d %d" , &n , &k) ;
		for (; n ; n /= 10) {
			int x = n % 10 ;
			(ans += f[x][k]) %= mod ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}