#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 15 + 10 ;

int n , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

	bool ans = 0 ;
	for (int S = 0 ; S < (1 << n) ; ++S) {
		int s = 0 ;
		for (int i = 0 ; i < n ; ++i)
			if ((1 << i) & S) s += a[i] ;
			else s -= a[i] ;

		if (!(abs(s) % 360)) ans = 1 ;
	}

	if (ans) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}