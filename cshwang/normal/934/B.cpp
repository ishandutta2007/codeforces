#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int k ;

int main() {
	scanf("%d" , &k) ;
	if (k > 36) printf("-1\n") ;
	else {
		for (int i = 0 ; i < k / 2 ; ++i) printf("8") ;
		if (k % 2) printf("4\n") ;
		else printf("\n") ;
	}

	return 0 ;
}