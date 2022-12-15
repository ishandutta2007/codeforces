#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T ;
ll n , k ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%lld %lld" , &n , &k) ;

		ll ans = 0 ;
		for (; n ;) {
			ll ad = n - n / k * k ;

			if (!ad) {n /= k ; ++ans ;}
			else {ans += n - n / k * k ; n = n / k * k ;}
		}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}