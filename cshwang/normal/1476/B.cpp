#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n , k ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		ll sum ;
		scanf("%d %d" , &n , &k) ;
		scanf("%lld" , &sum) ;

		///

		ll ans = 0 , inc ;
		for (int i = 1 ; i < n ; ++i) {
			ll x ; scanf("%lld" , &x) ;
			if (x * 100 > k * sum) {
				inc = (x * 100 + k - 1) / k - sum ;
				ans += inc ; sum += inc ;
			}
			sum += x ;
		}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}