#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

bool ap[MAX_N] ;
int T , n , x[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &x[i]) ;
		std::sort(x + 1 , x + 1 + n) ;

		///

		int m = (n << 1) + 1 , ans = 0 ;
		for (int i = 1 ; i <= m ; ++i) ap[i] = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int nw = x[i] ;
			if (!ap[nw]) {ap[nw] = 1 ; ++ans ;}
			else {
				++nw ;
				if (!ap[nw]) {ap[nw] = 1 ; ++ans ;}
			}
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}