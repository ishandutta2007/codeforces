#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_L = 5e3 + 10 , Hmod = 1e9 + 7 ;

char st[MAX_L] ;
bool f[2][MAX_L][MAX_L] ;
int len , sum[MAX_L] , hash[2][MAX_L][MAX_L]  ;

int main() {
	scanf("%s" , st) ;
	len = strlen(st) ;

	///
	
	for (int i = 0 ; i < len ; ++i) hash[0][i][i] = hash[1][i][i] = st[i] - 'a' ;
	for (int L = 2 ; L <= len ; ++L)
		for (int i = 0 ; i < len ; ++i) {
			int j = i + L - 1 ;
			if (j >= len) break ;

			hash[0][i][j] = ((hash[0][i][j - 1] * 26) % Hmod + st[j] - 'a') % Hmod ;
			hash[1][i][j] = ((hash[1][i + 1][j] * 26) % Hmod + st[i] - 'a') % Hmod ;
		}

	///
	
	bool ans = 1 ; int op = 0 , nt = 2 ;
	for (int i = 0 ; i < len ; ++i)
		for (int j = i ; j < len ; ++j) {
			int pl = (j - i + 1) / 2 , p1 = i + pl - 1 , p2 = j - pl + 1 ;

			if (i == j || hash[0][i][p1] == hash[1][p2][j])
				f[0][i][j] = 1 , ++sum[1] ;
		}

	while (ans) {
		ans = 0 ;
		memset(f[op^1] , 0 , sizeof(f[op^1])) ;

		for (int i = 0 ; i < len ; ++i)
			for (int j = i ; j < len ; ++j) {
				int pl = (j - i + 1) / 2 , p1 = i + pl - 1 , p2 = j - pl + 1 ;
				if (f[op][i][p1] && f[op][p2][j]) {
					if (hash[0][i][p1] == hash[1][p2][j]) {
						ans = 1 ;
						f[op^1][i][j] = 1 ; ++sum[nt] ;
					}
				}
			}

		op ^= 1 ; ++nt ;
	}

	for (int i = 1 ; i <= len ; ++i) printf("%d " , sum[i]) ;
	printf("\n") ;

	return 0 ;	
}