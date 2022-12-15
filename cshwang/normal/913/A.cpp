#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int n , m ;

int main() {
	scanf("%d %d" , &n , &m) ;

	int a = 1 ;
	for (int i = 0 ; i < n ; ++i) {
		a <<= 1 ;
		if (a > m) break ;
	}

	printf("%d\n" , m % a) ;

	return 0 ;
}