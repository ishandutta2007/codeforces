#include <bitset>
#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 500 + 10 ;

std::bitset<MAX_N> f[2][64][MAX_N] , g , temp ;

int n , m ;

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y , t ;
		scanf("%d %d %d" , &x , &y , &t) ;
		f[t][0][x][y] = 1 ;
	}

	///

	for (int i = 1 ; i <= 60 ; ++i)
		for (int j = 1 ; j <= n ; ++j)
			for (int k = 1 ; k <= n ; ++k)
				for (int t = 0 ; t < 2 ; ++t)
					if (f[t][i - 1][j][k])
						f[t][i][j] |= f[t^1][i - 1][k] ;

	///

	int flg = 0 ;
	long long ans = 0 , INF = 1e18 ; g[1] = 1 ;

	for (int i = 60 ; i >= 0 ; --i) {
		temp = 0 ;

		for (int j = 1 ; j <= n ; ++j)
			if (g[j]) temp |= f[flg][i][j] ;

		if (temp.count()) {ans += ((long long)1 << i) ; g = temp ; flg ^= 1 ;}
	}

	if (ans > INF) printf("-1\n") ;
    else printf("%I64d\n" , ans) ;

	return 0 ;
}