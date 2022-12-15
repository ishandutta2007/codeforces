#include <map>
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

std::map<int , ll> sum ;

ll f[MAX_N] ;
int T , n , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		ll ans = 0 ;
		sum.clear() ; f[0] = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int x = a[i] ;
			if (!sum.count(x)) sum[x] = 0 ;

			f[i] = f[i - 1] + sum[x] ;
			sum[x] += i ; ans += f[i] ;
		}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}