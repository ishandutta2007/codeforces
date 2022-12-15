#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int x , y ;

int main() {
	scanf("%d %d" , &x , &y) ;

	x -= (y - 1) ;

	if (y < 1) printf("No\n") ;
	else if (x < 0) printf("No\n") ;
	else if (!(y - 1) && x) printf("No\n") ;
	else if (x % 2) printf("No\n") ;
	else printf("Yes\n") ;

	return 0 ;
}