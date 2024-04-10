#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T ;
char s[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {scanf("%s" , s) ; printf("%d\n" , strlen(s)) ;}

	return 0 ;
}