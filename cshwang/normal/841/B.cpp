#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 ;

int n ;

int main() {
	int sum , od ;
	sum = od = 0 ;

	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		int a ; scanf("%d" , &a) ;
		a &= 1 ; sum ^= a ; od |= a ;
	}

	if (sum || od) printf("First\n") ;
	else printf("Second\n") ;

	return 0 ;
}