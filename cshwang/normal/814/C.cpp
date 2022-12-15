#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1500 + 10 , MAX_C = 'z' + 10 ;

struct Link {
	int L , R , sum ;
}list[MAX_C][MAX_N] ;

int n , m , f[MAX_N][MAX_N] , tot[MAX_C] , ans[MAX_C][MAX_N] ;

void ins(int x , int s , int st , int ed) {
	int cur = ++tot[x] ;
	list[x][cur].L = st ;
	list[x][cur].R = ed ;
	list[x][cur].sum = s ;
}

int main() {
	scanf("%d" , &n) ; getchar() ;

	int s = 0 , st = 1 ; char c , last ;
	c = getchar() ; last = c ;
	for (int i = 1 ; 'a' <= c && c <= 'z' ; ++i) {
		if (last != c) {
			ins((int)last , s , st , i - 1) ;
		   	s = 1 ; st = i ; last = c ;
		}
		else ++s ;

		c = getchar() ;
	}
	ins((int)last , s , st , n) ;

	///

	for (int i = 'a' ; i <= 'z' ; ++i) {
		if (tot[i] <= 1) continue ;

		memset(f , 0 , sizeof(f)) ;

		for (int j = 0 ; j < list[i][1].L ; ++j) f[1][j] = list[i][1].sum + j ;
		for (int j = 2 ; j <= tot[i] ; ++j) {
			int k = 0 , cost = list[i][j].L - list[i][j - 1].R - 1 ;
			for (; k < cost ; ++k) f[j][k] = list[i][j].sum + k ;
			for (; list[i][j].L > k ; ++k) f[j][k] = f[j - 1][k - cost] + list[i][j].sum + cost ;
		}

		for (int j = 1 ; j <= n ; ++j) {
			int res = ans[i][j - 1] + 1 ;
			for (int k = 1 ; k <= tot[i] ; ++k) res = std::max(f[k][j] , res) ;

			ans[i][j] = res ;
		}
	}

	///
	
	scanf("%d" , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int num , res ; char c ;
		scanf("%d %c" , &num , &c) ;

		if (!tot[c]) res = num ;
		else if (tot[c] == 1) res = num + list[c][1].sum ;
		else res = ans[c][num] ;

		printf("%d\n" , std::min(res , n)) ;
	}
	
	return 0 ;
}