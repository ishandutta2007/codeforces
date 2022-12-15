#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e6 + 10 ;

bool ap[MAX_N] ;
int n , tot , prime[MAX_N] , ans[MAX_N] ;

void init() {
	int K = 2e6 ;
	for (int i = 2 ; i <= K ; ++i) {
		if (!ap[i]) prime[tot++] = i ;

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * prime[j] ;
			if (tmp > K) break ;

			ap[tmp] = 1 ;
			if (!(i % prime[j])) break ;
		}
	}
}

int main() {
	init() ;
	scanf("%d" , &n) ;

	///

	for (int i = 1 ; i <= n ; ++i) ans[i] = i ;
	for (int i = 0 ; i <= tot ; ++i) {
		if ((prime[i] << 1) > n) break ;
		for (int j = (prime[i] << 1) ; j <= n ; j += prime[i])
			ans[j] = std::min(ans[j] , j - prime[i] + 1) ;
	}

	///

	int res = n ;
	for (int i = n - 1 ; i ; --i) ans[i] = std::min(ans[i] , ans[i + 1]) ;

	for (int i = 1 ; i * i <= n ; ++i) {
		if (n % i) continue ;

		int k = n / i , tmp ;

		if (!ap[i]) {
			tmp = (k - 1) * i + 1 ;
			if (tmp < n && k > 1) res = std::min(res , ans[tmp]) ;
		}
		if (!ap[k]) {
			tmp = k * (i - 1) + 1 ;
			if (tmp < n && i > 1) res = std::min(res , ans[tmp]) ;
		}
	}

	printf("%d\n" , res) ;

	return 0 ;
}