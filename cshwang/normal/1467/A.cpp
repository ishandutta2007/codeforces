#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , n ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		if (n == 1) {printf("9\n") ; continue ;}
		else if (n == 2) {printf("98\n") ; continue ;}
		else {printf("989") ; n -= 3 ;}

		int a = 0 ;
		for (; n-- ;) {
			printf("%d" , a) ;
			if (a == 9) a = -1 ;
			++a ;
		}
		printf("\n") ;
	}

	return 0 ;
}