#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int n , ans ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i)
		if (!((n - i) % i)) ++ans ;

	printf("%d\n" , ans) ;

	return 0 ;
}