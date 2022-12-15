#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , n , k ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (; k > 3 ; --k , --n) printf("1 ") ;

		int ty = n % 4 ;
		if (!ty) printf("%d %d %d\n" , n >> 1 , n >> 2 , n >> 2) ;
		else if (ty == 2) printf("%d %d %d\n" , 2 , (n - 2) >> 1 , (n - 2) >> 1) ;
		else printf("%d %d %d\n" , 1 , n >> 1 , n >> 1) ;
	}

	return 0 ;
}