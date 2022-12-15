#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

int n ;
ll k , x[MAX_N] ;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}

int main() {
	int T ; scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %lld" , &n , &k) ;
		for (int i = 0 ; i < n ; ++i) scanf("%lld" , &x[i]) ;
		std::sort(x + 0 , x + n) ;

		///

		bool ok = 0 ;
		for (int i = 1 ; i < n ; ++i) x[i] -= x[0] ;
		if (k == x[0]) ok = 1 ;

		ll d = x[1] ;
		for (int i = 1 ; i < n ; ++i) d = gcd(d , x[i]) ;
		if (d && !((k - x[0]) % d)) ok = 1 ;

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}