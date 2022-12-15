#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 , mod = 998244353 ;

int n , tot , x[MAX_N] , y[MAX_N] , s[MAX_N] , sum[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d %d %d" , &x[i] , &y[i] , &s[i]) ;

	///

	int res = (x[n] + 1) % mod ;
	for (int i = 1 ; i <= n ; ++i) {
		sum[i] = sum[i - 1] ;

		int pl = std::lower_bound(x + 1 , x + 1 + n , y[i]) - x ,
			tmp = (sum[i] - sum[pl - 1] + mod) % mod , len = (x[i] - y[i]) % mod ;

		(tmp += len) %= mod ;
		(sum[i] += tmp) %= mod ;

		if (s[i]) (res += tmp) %= mod ;
	}

	printf("%d\n" , res) ;

	return 0 ;
}