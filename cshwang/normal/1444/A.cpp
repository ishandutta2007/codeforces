#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll p , q ;

int main() {
	int t ; scanf("%d" , &t) ;
	for (; t-- ;) {
		scanf("%lld %lld\n" , &p , &q) ;
		if (p % q) printf("%lld\n" , p) ;
		else {
			ll ans = 0 ;
			for (ll i = 2 ; i * i <= q ; ++i) {
				if (q % i) continue ;

				ll s = 1 , tmp = p ;
				for (; !(q % i) ; q /= i , s *= i) ;
				for (; !(tmp % i) ; tmp /= i) ;
				s /= i ; tmp *= s ;

				ans = std::max(ans , tmp) ;
			}
			if (q > 1) {
				ll s = 1 , tmp = p ;
				for (; !(tmp % q) ; tmp /= q) ;
				ans = std::max(ans , tmp) ;
			}

			printf("%lld\n" , ans) ;
		}
	}

	return 0 ;
}