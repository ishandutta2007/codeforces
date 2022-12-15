#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int q ;
ll a , b , m , l[MAX_N] , r[MAX_N] ;

ll qpow(ll a , ll t) {
	ll s = 1 , tmp = a ;
	for (; t ; t >>= 1 , tmp = tmp * tmp)
		if (t & 1) s = s * tmp ;

	return s ;
}

int main() {
	scanf("%d" , &q) ;
	for (; q-- ;) {
		scanf("%lld %lld %lld" , &a , &b , &m) ;
		if (a > b) {printf("-1\n") ; continue ;}

		int o = 1 ;
		ll s = a ; l[1] = a ;
		for (; s + 1 <= b ;) s += (l[++o] = s + 1) ;

		///

		--m ;
		if (!m && l[o] != b) {printf("-1\n") ; continue ;}

		for (int i = 1 ; i <= o ; ++i) r[i] = 0 ;

		ll cj = b - l[o] ;
		for (int i = 2 ; i <= o && cj ; ++i) {
			ll ad = std::max(o - i - 1 , 0) , t ;

			ad = qpow(2 , ad) ; t = std::min(cj / ad , m) ;
			r[i] += t ; cj -= t * ad ;
		}

		if (cj > 0) {printf("-1\n") ; continue ;}

		s = l[1] ;
		for (int i = 2 ; i <= o ; ++i) s += (l[i] = s + r[i] + 1) ;

		printf("%d " , o) ;
		for (int i = 1 ; i <= o ; ++i) printf("%lld " , l[i]) ;
		printf("\n") ;
	}

	return 0 ;
}