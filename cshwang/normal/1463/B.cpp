#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 50 + 5 , INF = 1e9 ;

int T , n , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		///

		for (int i = 1 ; i <= n ; ++i) {
			int t = 1 ;
			for (; t < a[i] ; t <<= 1) ;

			if (t == 1) printf("%d " , t) ;
			else if (t > INF) printf("%d " , t >> 1) ;
			else {
				int t2 = t >> 1 ;
				if (abs(t2 - a[i]) < abs(t - a[i])) printf("%d " , t2) ;
				else printf("%d " , t) ;
			}
		}
		printf("\n") ;
	}

	return 0 ;
}