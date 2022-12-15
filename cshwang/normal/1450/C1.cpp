#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 300 + 10 ;

char s[MAX_N] ;
int T , n , a[MAX_N][MAX_N] ;

int check(int x) {
	int res = 0 ;
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j) {
			int nw = i + j ;
			if (nw % 3 != x) continue ;

			res += a[i][j] ;
		}

	return res ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		int tot = 0 ;
		scanf("%d" , &n) ;
		for (int i = 0 ; i < n ; ++i) {
			scanf("%s" , s) ;
			for (int j = 0 ; j < n ; ++j)
				if (s[j] == 'X') a[i][j] = 1 , ++tot ;
				else a[i][j] = 0 ;
		}

		///

		int ans = 0 ;
		for (int i = 0 ; i < 3 ; ++i)
			if (check(i) <= tot / 3) {ans = i ; break ;}

		for (int i = 0 ; i < n ; ++i , printf("\n"))
			for (int j = 0 ; j < n ; ++j) {
				int nw = i + j ;
				if (nw % 3 == ans && a[i][j]) printf("O") ;
				else if (a[i][j]) printf("X") ;
				else printf(".") ;
			}
	}

	return 0 ;
}