#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int T , n , m , lef[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 0 ; i < n ; ++i) {
			int a ; scanf("%d" , &a) ;
			++lef[a % m] ;
		}

		///

		int ans = lef[0] ? 1 : 0 ;
		for (int i = 1 ; i < m ; ++i) {
			int j = m - i , p1 = lef[i] , p2 = lef[j] ;
			if (p1 > p2) std::swap(p1 , p2) ;

			if (i > j) break ;
			else if (!p1) {ans += p2 ; continue ;}
			else if (i == j) {++ans ; continue ;}

			p2 -= (p1 + 1) ; ++ans ;
			if (p2 >= 0) ans += p2 ;
		}
		printf("%d\n" , ans) ;

		for (int i = 0 ; i < m ; ++i) lef[i] = 0 ;
	}

	return 0 ;
}