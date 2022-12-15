#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e5 + 10 ;

int n , k , a[MAX_N] , cnt[MAX_N] ;

bool cmp(int x , int y) {return x > y ;}

int main() {
	scanf("%d %d" , &n , &k) ; ++k ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	std::sort(a + 1 , a + 1 + n , cmp) ;
	ll s = 0 ; int p = 0 ;
	for (; p <= n && s >= 0 ;) s += a[++p] ;

	///

	ll ans = 0 ; int nw = 0 ; --p ;
	for (int i = n ; i > p ; --i , nw = (nw + 1) % k) ans += (ll)a[i] * (cnt[nw]++) ;
	for (int i = p ; i ; --i) ans += (ll)a[i] * (cnt[0]++) ;

	printf("%lld\n" , ans) ;

	return 0 ;
}