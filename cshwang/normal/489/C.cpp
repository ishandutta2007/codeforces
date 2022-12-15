#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 , MAX_S = 900 + 10 ;

struct data {
	bool ok ;
	int len ;
	char s[MAX_N] ;

	friend data operator *(data x , int a) {
		if (!x.ok) return x ;

		for (int i = x.len ; i ; --i) x.s[i] = x.s[i - 1] ;
		++x.len ;
		return x ;
	}
	friend data operator +(data x , int a) {
		if (!x.ok) return x ;

		x.s[0] = a + '0' ;
		return x ;
	}
}f[MAX_N][MAX_S] , g[MAX_N][MAX_S] ;

int n , s ;

data min(data x , data y) {
	if (!x.ok) return y ;
	else if (!y.ok) return x ;

	for (int i = x.len - 1 ; i >= 0 ; --i)
		if (x.s[i] < y.s[i]) return x ;
		else if (x.s[i] > y.s[i]) return y ;

	return x ;
}

data max(data x , data y) {
	if (!x.ok) return y ;
	else if (!y.ok) return x ;

	for (int i = x.len - 1 ; i >= 0 ; --i)
		if (x.s[i] < y.s[i]) return y ;
		else if (x.s[i] > y.s[i]) return x ;

	return x ;
}

int main() {
	scanf("%d %d" , &n , &s) ;

	if (n == 1) {
		if (s > 9) printf("-1 -1\n") ;
		else printf("%d %d\n" , s , s) ;
		
		return 0 ;
	}

	///

	f[1][0].ok = g[1][0].ok = 0 ;

	for (int i = 1 ; i <= 9 ; ++i) {
		f[1][i].ok = g[1][i].ok = 1 ;
		f[1][i].len = g[1][i].len = 1 ;
		f[1][i].s[0] = g[1][i].s[0] = i + '0' ;
	}

	for (int i = 2 ; i <= n ; ++i)
		for (int j = 0 ; j <= s ; ++j) {
			f[i][j].ok = g[i][j].ok = 0 ;

			for (int k = 0 ; k <= 9 ; ++k) {
				if (j - k < 0) break ;

				f[i][j] = min(f[i][j] , f[i - 1][j - k] * 10 + k) ;
				g[i][j] = max(g[i][j] , g[i - 1][j - k] * 10 + k) ;
			}
		}

	///

	if (!f[n][s].ok) printf("-1") ;
	else for (int i = f[n][s].len - 1 ; i >= 0 ; --i) printf("%c" , f[n][s].s[i]) ;
	printf(" ") ;
	if (!g[n][s].ok) printf("-1") ;
	else for (int i = g[n][s].len - 1 ; i >= 0 ; --i) printf("%c" , g[n][s].s[i]) ;
	printf("\n") ;

	return 0 ;
}