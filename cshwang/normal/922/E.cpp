#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long 
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e12 ;
const int MAX_N = 1e3 + 10 , MAX_B = 1e4 + 10 ;

ll f[MAX_N][MAX_B] ;
int n , W , B , X , sum , c[MAX_N] , cost[MAX_N] ;

int main() {
	scanf("%d %d %d %d" , &n , &W , &B , &X) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &c[i]) , sum += c[i] ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &cost[i]) ;

	///

	for (int i = 0 ; i <= c[0] ; ++i) {
		ll tc = cost[0] ;

		if (tc * i <= W) f[0][i] = W - tc * i ;
		else f[0][i] = -INF ;
	}
	for (int i = c[0] + 1 ; i <= sum ; ++i) f[0][i] = -INF ;

	///

	for (int i = 1 ; i < n ; ++i)
		for (int j = 0 ; j <= sum ; ++j) {
			ll res = -INF ;
			int uk = std::min(j , c[i]) ;

			for (int k = 0 ; k <= uk ; ++k) {
				ll uma = W + (ll)(j - k) * B , tmp = std::min(f[i - 1][j - k] + X , uma) ;
				tmp -= (ll)k * cost[i] ;

				if (tmp < 0) tmp = -INF ;
				res = std::max(res , tmp) ;
			}

			f[i][j] = res ;
		}

	int ans = sum ;
	for (; ans >= 0 ; --ans)
		if (f[n - 1][ans] >= 0) break ;
	printf("%d\n" , ans) ;

	return 0 ;
}