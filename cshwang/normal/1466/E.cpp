#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll mod = 1e9 + 7 ;
const int L = 60 , MAX_N = 5e5 + 10 , MAX_L = 60 + 5 ;

ll x[MAX_N] ;
int T , n , cnt[MAX_L][2] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%lld" , &x[i]) ;
		for (int i = 0 ; i < L ; ++i) cnt[i][0] = cnt[i][1] = 0 ;

		///

		for (int i = 1 ; i <= n ; ++i)
			for (int j = 0 ; j < L ; ++j)
				if (x[i] & (1LL << j)) ++cnt[j][1] ;
				else ++cnt[j][0] ;

		ll ans = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			ll p1 = 0 , p2 = 0 ;
			for (int j = 0 ; j < L ; ++j) {
				int nw = x[i] & (1LL << j) ? 1 : 0 , tmp ;

				if (nw == 1) {
					tmp = (1LL << j) % mod * cnt[j][1] % mod ;
					(p1 += tmp) %= mod ;

					tmp = (1LL << j) % mod * n % mod ;
					(p2 += tmp) %= mod ;
				}
				else {
					tmp = (1LL << j) % mod * cnt[j][1] % mod ;
					(p2 += tmp) %= mod ;
				}
			}

			(p1 *= p2) %= mod ;
			(ans += p1) %= mod ;
		}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}