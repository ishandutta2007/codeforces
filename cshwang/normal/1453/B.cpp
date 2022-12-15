#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

ll ans ;
int T , n , a[MAX_N] , b[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		///

		ll tot = 0 ;
		for (int i = 2 ; i <= n ; ++i) {
			b[i] = a[i] - a[i - 1] ;
			tot += abs(b[i]) ;
		}

		ll ans = tot - abs(b[n]) ;
		ans = std::min(ans , tot - abs(b[2])) ;
		for (int i = 2 ; i < n ; ++i) {
			ll nw = a[i + 1] - a[i - 1] ;
			ans = std::min(ans , tot - abs(b[i + 1]) - abs(b[i]) + abs(nw)) ;
		}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}