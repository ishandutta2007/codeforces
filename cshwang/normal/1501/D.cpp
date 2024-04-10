#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 ;

ll k , tf ;
bool ap[MAX_N] ;
int n , m , tot , a[MAX_N] , b[MAX_N] , pl[MAX_N] , f[MAX_N] , cir[MAX_N] ;

int main() {
	scanf("%d %d %lld" , &n , &m , &k) ;
	if (n < m) {
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &b[i]) , pl[b[i]] = i ;
		for (int i = 1 ; i <= m ; ++i) scanf("%d" , &a[i]) ;
		std::swap(n , m) ;
	}
	else {
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		for (int i = 1 ; i <= m ; ++i) scanf("%d" , &b[i]) , pl[b[i]] = i ;
	}

	///

	int t = n << 1 ;
	for (int i = n + 1 ; i <= t ; ++i) a[i] = a[i - n] ;
	for (int i = 1 ; i <= n ; ++i) f[i] = m ;
	for (int i = 1 ; i <= t ; ++i) {
		int tmp = a[i] ;
		if (!pl[tmp]) continue ;

		tmp = i - pl[tmp] + 1 ;
		if (tmp >= 1 && tmp <= n) --f[tmp] ;
	}

	///

	for (int nw = 1 ; !ap[nw] ;) {
		cir[++tot] = nw ; tf += f[nw] ;
		ap[nw] = 1 ; nw = (nw + m - 1) % n + 1 ;
	}

	ll ans = 0 ;
	if (k && !(k % tf)) {
		ans = (k / tf - 1) * tot * m ;
		k = tf ;
	}
	else {
		ans = (k / tf) * tot * m ;
		k %= tf ;
	}

	///

	int pl = 1 ;
	for (; k > f[cir[pl]] ;) {
		k -= f[cir[pl]] ;
		ans += m ; ++pl ;
	}

	for (int i = 1 ; i <= m && k ; ++i) {
		++ans ;
		if (b[i] != a[cir[pl] + i - 1]) --k ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}