#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

char s[MAX_N] ;
int T , n , f[MAX_N] , g[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d%s" , &n , s) ;
		for (int i = n ; i ; --i) s[i] = s[i - 1] ;

		f[1] = 1 ;
		for (int i = 2 ; i <= n ; ++i)
			if (s[i] == s[i - 1]) f[i] = 1 ;
			else f[i] = f[i - 1] + 1 ;
		g[n] = 1 ;
		for (int i = n - 1 ; i ; --i)
			if (s[i] == s[i + 1]) g[i] = 1 ;
			else g[i] = g[i + 1] + 1 ;

		for (int i = 0 ; i <= n ; ++i) {
			int j = i + 1 , ans = 0 ;

			if (i && s[i] == 'L') ans += f[i] ;
			if (j <= n && s[j] == 'R') ans += g[j] ;
			printf("%d " , ans + 1) ;
		}
		printf("\n") ;
	}

	return 0 ;
}