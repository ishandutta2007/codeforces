#include <stdio.h>
#include <stdlib.h>

#define ull unsigned long long

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int k ;
ull n , m ;

int main() {
	scanf("%I64d %I64d" , &n , &m) ;
	if (m == 1) {
		printf("%I64d\n" , n) ;

		return 0 ;
	}

	///

	for (k = 0 ; n ; n >>= 1 , ++k) ;
	printf("%I64d\n" , ((ull)1 << k) - 1) ;

	return 0 ;
}