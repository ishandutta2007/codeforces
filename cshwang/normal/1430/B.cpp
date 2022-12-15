#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

ll a[MAX_N] ;
int t , n , k ;

bool cmp(int x , int y) {return x > y ;}

int main() {
	scanf("%d" , &t) ;
	for (; t-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%lld" , &a[i]) ;

		///

		std::sort(a + 1 , a + 1 + n , cmp) ;
		ll ans = 0 ;
		for (int i = 1 ; i <= k + 1 ; ++i) ans += a[i] ;

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}