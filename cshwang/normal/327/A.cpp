#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n , ans , sum , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;

	sum = 0 ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , sum += a[i] ;

	///

	for (int i = 1 ; i <= n ; ++i) {
		int tmp = 0 ;
		for (int j = i ; j <= n ; ++j) {
			tmp += a[j] ? -1 : 1 ;
			ans = std::max(ans , tmp + sum) ;
		}
	}

	printf("%d\n" , ans) ;

	return 0 ;
}