#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , n , k ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		int nw = 0 ;
		for (int i = 0 ; i < n ; ++i , nw = (nw + 1) % 3) printf("%c" , 'a' + nw) ;
		printf("\n") ;
	}

	return 0 ;
}