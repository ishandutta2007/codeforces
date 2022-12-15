#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , n ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		int k = 0 , s = 0 ;
		scanf("%d" , &n) ;
		for (; s < n ; s += (++k)) ;

		if (s - n != 1) printf("%d\n" , k) ;
		else printf("%d\n" , k + 1) ;
	}

	return 0 ;
}