#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int n ;

int main() {
	scanf("%d" , &n) ;
	printf("%d\n" , n & 1) ;

	return 0 ;
}