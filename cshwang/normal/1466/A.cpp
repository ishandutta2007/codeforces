#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int N = 50 , MAX_N = 50 + 5 ;

bool ap[MAX_N] ;
int T , n , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		for (int i = 1 ; i <= N ; ++i) ap[i] = 0 ;
		for (int i = 1 ; i <= n ; ++i)
			for (int j = i + 1 ; j <= n ; ++j) ap[a[j] - a[i]] = 1 ;

		int ans = 0 ;
		for (int i = 1 ; i <= N ; ++i) if (ap[i]) ++ans ;
		printf("%d\n" , ans) ;
	}

	return 0 ;
}