#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int y , b , r ;

int main() {
	scanf("%d %d %d" , &y , &b , &r) ; --b ; r -= 2 ;

	int ny = std::min(y , std::min(b , r)) ;
	printf("%d\n" , ny * 3 + 3) ;

	return 0 ;
}