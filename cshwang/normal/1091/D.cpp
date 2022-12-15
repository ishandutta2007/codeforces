#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 , mod = 998244353 ;

int n , jc[MAX_N] , P[MAX_N] ;

int main() {
	scanf("%d" , &n) ;

	jc[0] = 1 ;
	for (int i = 1 ; i <= n ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
	P[0] = 1 ;
	for (int i = 1 ; i <= n ; ++i) P[i] = (ll)P[i - 1] * (n - i + 1) % mod ;

	///

	int ans = 1 ;
	for (int i = 0 ; i <= n ; ++i) {
		int tmp = ((ll)jc[n - i] + mod - 1) * P[i] % mod ;
		(ans += tmp) %= mod ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}