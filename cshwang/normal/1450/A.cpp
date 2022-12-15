#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 200 + 10 ;

int T , n ;
char s[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %s" , &n , s) ;
		std::sort(s + 0 , s + n) ;
		for (int i = 0 ; i < n ; ++i) printf("%c" , s[i]) ;
		printf("\n") ;
	}

	return 0 ;
}