#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int n , s ;

int main() {
	scanf("%d" , &n) ; s = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		int a ; scanf("%d" , &a) ;
		s ^= a ;
	}

	///

	if (!(n & 1) && s) {printf("NO\n") ; return 0 ;}
	else if (!(n & 1)) --n ;

	printf("YES\n%d\n" , n - 1) ;
	for (int i = 1 ; i < n ; i += 2) printf("%d %d %d\n" , i , i + 1 , i + 2) ;
	for (int i = 1 ; i < n ; i += 2) printf("%d %d %d\n" , i , i + 1 , n) ;

	return 0 ;
}