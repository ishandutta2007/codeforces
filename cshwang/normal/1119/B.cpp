#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int n , h , a[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &h) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	int res = 0 ;
	for (int k = 1 ; k <= n ; ++k) {
		std::sort(a + 1 , a + k + 1) ;

		ll tot = 0 ;
		for (int i = k % 2 ? 1 : 2 ; i <= k ; i += 2) tot += a[i] ;

		if (tot <= h) res = k ;
	}

	printf("%d\n" , res) ;

	return 0 ;
}