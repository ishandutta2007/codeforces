#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , n , k ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;

		int ans ;
		if (n > k) {
			if (n % k) ans = 2 ;
			else ans = 1 ;
		}
		else {
			ans = k / n ;
			if (k % n) ++ans ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}