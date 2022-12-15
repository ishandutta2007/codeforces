#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int T , n , a[MAX_N] , b[MAX_N] , l[MAX_N] ;

ll cal(ll x , ll y) {
	if (x < y) return y - x + 1 ;
	else return x - y + 1 ;
}

ll count(ll len , ll x , ll y) {
	ll tmp = cal(x , y) ;
	return len - tmp + 2 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &l[i]) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &b[i]) ;

		///

		ll ans = 0 , tmp = cal(a[2] , b[2]) ;
		for (int i = 2 ; i < n ; ++i) {
			ans = std::max(ans , tmp + l[i]) ;
			if (a[i + 1] == b[i + 1]) {
				tmp += l[i] ;
				ans = std::max(ans , tmp) ;
				tmp = 1 ;
			}
			else {
				tmp += count(l[i] , a[i + 1] , b[i + 1]) ;
				tmp = std::max(tmp , cal(a[i + 1] , b[i + 1])) ;
			}
		}
		ans = std::max(ans , tmp + l[n]) ;

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}