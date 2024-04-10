#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1000 + 10 ;

int n ;

int main() {
	scanf("%d" , &n) ;

	int x = 1 , y = 1 ;
	for (int i = 2 ; i <= n ; ++i)
		if (i & 1) ++x ;
		else ++y ;

	///

	printf("%d\n" , std::max(x , y)) ;
	x = y = 1 ;

	printf("%d %d\n" , x , y) ;
	for (int i = 2 ; i <= n ; ++i) {
		if (i & 1) ++x ;
		else ++y ;

		printf("%d %d\n" , x , y) ;
	}

	return 0 ;
}