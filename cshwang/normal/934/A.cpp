#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 50 + 5 ;

int n , m ;
ll a[MAX_N] , b[MAX_N] ;

bool cmp(ll x , ll y) {return x > y ;}

ll check(int x) {
	ll ans ;
	if (x == 1) ans = a[2] * b[1] ;
	else ans = a[1] * b[1] ;

	for (int i = 1 ; i <= n ; ++i) {
		if (i == x) continue ;
		for (int j = 1 ; j <= m ; ++j) {
			ll tmp = a[i] * b[j] ;
			ans = std::max(ans , tmp) ;
		}
	}

	return ans ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%I64d" , &a[i]) ;
	for (int i = 1 ; i <= m ; ++i) scanf("%I64d" , &b[i]) ;

	ll ans = check(1) ;
	for (int i = 2 ; i <= n ; ++i) ans = std::min(ans , check(i)) ;

	printf("%I64d\n" , ans) ;

	return 0 ;
}