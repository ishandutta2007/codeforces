#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 50 + 10 ;

int L , len , op ;
char s[MAX_N] , s1[MAX_N] ;

int main() {
	scanf("%s" , s) ;
	len = strlen(s) ; op = len % 2 ;

	///

	int le = 0 , ri = len - 1 ;
	for (int i = 0 ; i < len ; ++i , op ^= 1)
		if (!op) s1[L++] = s[ri--] ;
		else s1[L++] = s[le++] ;

	for (int i = L - 1 ; i >= 0 ; --i) printf("%c" , s1[i]) ;
	printf("\n") ;

	return 0 ;
}