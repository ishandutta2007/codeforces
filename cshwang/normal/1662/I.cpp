#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 , INF = 0x7FFFFFFF ;

int n , m ;
ll sum[MAX_N] , p[MAX_N] , x[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%lld" , &p[i]) ;
	for (int i = 1 ; i <= m ; ++i) scanf("%lld" , &x[i]) ;
	for (int i = 1 ; i <= n ; ++i) sum[i] = sum[i - 1] + p[i] ;
	std::sort(x + 1 , x + m + 1) ;

	///

	ll ans = 0 ; int idx = 0 ;
	x[0] = -INF ; x[m + 1] = INF ;
	for (int i = 1 ; i <= n ; ++i) {
		ll nw = (i - 1) * 100 ;
		for (; x[idx + 1] <= nw ; ++idx) ;
		if (x[idx] == nw) continue ;

		ll loc = nw + (nw - x[idx]) , nxt = x[idx + 1] , j ;
		if (loc > nxt) j = (nxt - 1) / 100 + 1 ;
		else {
			j = (loc + nxt - 1) / 2 ;
			j = j / 100 + 1 ;
		}
		j = std::min(j , (ll)n) ;
		ans = std::max(ans , sum[j] - sum[i - 1]) ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}