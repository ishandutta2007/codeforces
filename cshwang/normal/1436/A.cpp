#include <stdio.h>
#include <stdlib.h> 

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int t , n , m ;

int main() {
	scanf("%d" , &t) ;
	for (; t-- ;) {
		scanf("%d %d" , &n , &m) ;

		int s = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int a ; scanf("%d" , &a) ;
			s += a ;
		}

		if (s == m) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}