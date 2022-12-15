#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n , ans ;
char st[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	scanf("%s" , st) ;

	///

	ans = n ;
	for (int i = 0 ; i < n - 1 ;)
		if (st[i] != st[i + 1]) {--ans ; i += 2 ;}
		else ++i ;
	
	printf("%d\n" , ans) ;

	return 0 ;
}