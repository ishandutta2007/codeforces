#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 10 + 5 ;

int n , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

	///

	bool ok = 1 ;
	for (int i = 1 ; i < n && ok ; ++i) if (a[i - 1] - a[i] >= 2) ok = 0 ;

	if (ok) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}