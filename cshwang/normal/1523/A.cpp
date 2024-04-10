#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

std::vector<int> pl ;

int T , n , m ;
char s[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		pl.clear() ;

		scanf("%d %d %s" , &n , &m , s) ;
		for (int i = 0 ; i < n ; ++i) if (s[i] == '1') pl.push_back(i) ;

		///

		int t = pl.size() ;
		if (t) {
			int st = pl[0] - 1 ;
			for (int i = 0 ; st >= 0 && i < m ; ++i , --st) s[st] = '1' ;

			st = pl[t - 1] + 1 ;
			for (int i = 0 ; st < n && i < m ; ++i , ++st) s[st] = '1' ;
		}

		for (int i = 1 ; i < t ; ++i) {
			int p1 = pl[i - 1] , p2 = pl[i] , len = (p2 - p1 - 1) >> 1 ;

			len = std::min(len , m) ;
			for (int i = 1 ; i <= len ; ++i) s[p1 + i] = s[p2 - i] = '1' ;
		}

		for (int i = 0 ; i < n ; ++i) printf("%c" , s[i]) ;
		printf("\n") ;
	}

	return 0 ;
}