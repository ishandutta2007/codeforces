#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

int T , n , k , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

		///

		std::sort(a + 0 , a + n) ;

		int ans = a[n - 1] - a[0] + 1 , pl = -1 ;
		for (int i = 0 ; i < n - k ; ++i) {
			int j = i + k , x = (a[i] + a[j]) / 2 , res = a[j] - x ;

			if (res < ans) ans = res , pl = x ;
		}

		printf("%d\n" , pl) ;
	}

	return 0 ;
}