#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int n , ans ;

int main() {
	scanf("%d" , &n) ;

	int last = 0 , s = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int a ; scanf("%d" , &a) ;

		if (a >= last) ++s , ans = std::max(ans , s) ;
		else s = 1 ;

		last = a ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}