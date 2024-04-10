#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n , k , x[MAX_N] , y[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (int i = 0 ; i < n ; ++i) scanf("%d %d" , &x[i] , &y[i]) ;

		///

		int ans = -1 ;
		for (int i = 0 ; i < n ; ++i) {
			bool ck = 1 ;
			for (int j = 0 ; j < n ; ++j) {
				int tmp = abs(x[i] - x[j]) + abs(y[i] - y[j]) ;
				if (tmp > k) ck = 0 ;
			}

			if (ck) ans = 1 ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}