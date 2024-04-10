#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d" , __FUNCTION__ , __LINE__) ;

int T , a , b , c ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d %d" , &a , &b , &c) ;
		int s = a + b + c , k = s / 9 ;

		if (s % 9) printf("NO\n") ;
		else if (a < k || b < k || c < k) printf("NO\n") ;
		else printf("YES\n") ;
	}

	return 0 ;
}