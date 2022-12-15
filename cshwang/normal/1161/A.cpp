#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 , INF = 0x3f3f3f3f ;

int n , k , a[MAX_N] , lef[MAX_N] , rig[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= k ; ++i) scanf("%d" , &a[i]) ;

	for (int i = 1 ; i <= n ; ++i) lef[i] = INF , rig[i] = 0 ;
	for (int i = 1 ; i <= k ; ++i) if (lef[a[i]] == INF) lef[a[i]] = i ;
	for (int i = k ; i ; --i) if (!rig[a[i]]) rig[a[i]] = i ;

	///

	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = -1 ; j <= 1 ; ++j) {
			int ni = i + j ;
			if (ni < 1 || ni > n) continue ;

			if (lef[i] > rig[ni]) ++ans ;
		}
	printf("%d\n" , ans) ;

	return 0 ;
}