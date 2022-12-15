#include <stdio.h>
#include <stdlib.h>

int s , v1 , v2 , t1 , t2 , r1 , r2 ;

int main() {
	scanf("%d %d %d %d %d" , &s , &v1 , &v2 , &t1 , &t2) ;
	r1 = s * v1 + t1 * 2 ;
	r2 = s * v2 + t2 * 2 ;

	if (r1 > r2) printf("Second\n") ;
	else if (r1 < r2) printf("First\n") ;
	else printf("Friendship\n") ;

	return 0 ;
}