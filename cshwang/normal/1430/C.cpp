#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int t , n ;

int main() {
	scanf("%d" , &t) ;
	for (; t-- ;) {
		scanf("%d" , &n) ;
		
		printf("2\n") ;

		if (n == 2) printf("1 2\n") ;
		else {
			printf("%d %d\n%d %d\n" , n - 2 , n , n - 1 , n - 1) ;

			for (int i = n - 3 ; i ; --i) printf("%d %d\n" , i , i + 2) ;
		}
	}

	return 0 ;
}