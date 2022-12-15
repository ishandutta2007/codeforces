#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int T , n ;
char a[MAX_N] , s[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d%s" , &n , s) ;
		for (int i = 0 ; i < n ; ++i) {
			char nc = s[i] + 1 ;
			if (!i || nc != s[i - 1]) s[i] = nc , a[i] = '1' ;
			else a[i] = '0' ;
		}
		for (int i = 0 ; i < n ; ++i) printf("%c" , a[i]) ;
		printf("\n") ;
	}

	return 0 ;
}