#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int len ;
char s[MAX_N] ;

int main() {
	scanf("%s" , s) ;
	len = strlen(s) ;

	for (int i = 0 ; i < len ; ++i) printf("%c" , s[i]) ;
	for (int i = len - 1 ; i >= 0 ; --i) printf("%c" , s[i]) ;

	printf("\n") ;

	return 0 ;
}