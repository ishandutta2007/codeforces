#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , n , m ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (m = 1 ; (m << 1) <= n ; m <<= 1) ;

		printf("%d\n" , m - 1) ;
	}

	return 0 ;
}