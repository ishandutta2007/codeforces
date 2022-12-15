#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e3 + 10 ;

int T , n , ans[10] ;
char s[MAX_N][MAX_N] , tmp[MAX_N][MAX_N] ;

int work(int a) {
	char c = a + '0' ;
	int mi = -1 , ma = -1 ;
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j)
			if (s[i][j] == c) {
				if (mi == -1) mi = i , ma = i ;
				else ma = i ;
			}

	if (mi == -1) return 0 ;

	///

	int ans = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int p1 = -1 , p2 = -1 ;
		for (int j = 0 ; j < n ; ++j)
			if (s[i][j] == c) {
				if (p1 == -1) p1 = j , p2 = j ;
				else p2 = j ;
			}

		ans = std::max(ans , (p2 - p1) * std::max(n - 1 - i , i - 0)) ;
		if (p1 != -1) ans = std::max(ans , (n - 1 - p1) * std::max(ma - i , i - mi)) ;
		if (p2 != -1) ans = std::max(ans , p2 * std::max(ma - i , i - mi)) ;
	}

	return ans ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 0 ; i < n ; ++i) {getchar() ; scanf("%s" , s[i]) ;}

		///

		for (int i = 0 ; i < 10 ; ++i) ans[i] = work(i) ;
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j) tmp[i][j] = s[j][i] ;
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j) s[i][j] = tmp[i][j] ;
		for (int i = 0 ; i < 10 ; ++i) ans[i] = std::max(ans[i] , work(i)) ;

		///

		for (int i = 0 ; i < 10 ; ++i) printf("%d " , ans[i]) ;
		printf("\n") ;
	}

	return 0 ;
}