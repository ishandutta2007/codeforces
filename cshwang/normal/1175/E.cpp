#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e5 + 10 , lgN = 20 + 5 ;

int T , n , m , f[MAX_N][lgN] , nxt[MAX_N] ;

int jump(int x , int y) {
	int ans = 0 ;
	for (int i = 20 ; i >= 0 ; --i) {
		int t = f[x][i] ;
		if (t >= y) continue ;

		ans += (1 << i) ; x = t ;
	}

	return ans + 1 ;
}

int main() {
	scanf("%d %d" , &T , &m) ;
	for (; T-- ;) {
		int l , r ;
		scanf("%d %d" , &l , &r) ;

		n = std::max(n , r) ;
		nxt[l] = std::max(nxt[l] , r) ;
	}

	///

	for (int i = 1 ; i <= n ; ++i) nxt[i] = std::max(nxt[i] , nxt[i - 1]) ;
	for (int i = 0 ; i <= n ; ++i) f[i][0] = std::max(i , nxt[i]) ;

	for (int j = 1 ; j <= 20 ; ++j)
		for (int i = 0 ; i <= n ; ++i) f[i][j] = f[f[i][j - 1]][j - 1] ;

	for (; m-- ;) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;

		if (x > n) printf("-1\n") ;
		else if (f[x][20] < y) printf("-1\n") ;
		else printf("%d\n" , jump(x , y)) ;
	}

	return 0 ;
}