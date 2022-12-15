#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int n ;

int main() {
	scanf("%d" , &n) ;

	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= n ; ++j) {
			int k = i^j ;
			if (k < 1 || k > n) continue ;

			if (i + j > k && i + k > j && j + k > i) ++ans ;
		}

	printf("%d\n" , ans / 6) ;

	return 0 ;
}