#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

int T , n , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		///

		int l , r ;
		for (l = 1 ; l <= n ; ++l) if (a[l] != l) break ;
		for (r = n ; r ; --r) if (a[r] != r) break ;

		if (l > r) printf("0\n") ;
		else {
			int ans = 1 ;
			for (int i = l ; i <= r ; ++i) if (a[i] == i) {++ans ; break ;}

			printf("%d\n" , ans) ;
		}
	}

	return 0 ;
}