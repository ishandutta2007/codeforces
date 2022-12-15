#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e3 + 10 ;

ll f[MAX_N] ;
int T , n , tag[MAX_N] , s[MAX_N] ;

inline int abs(int x) {return x > 0 ? x : -x ;}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &tag[i]) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &s[i]) ;
		for (int i = 1 ; i <= n ; ++i) f[i] = 0 ;

		///

		ll ans = 0 ;
		for (int i = 2 ; i <= n ; ++i)
			for (int j = i - 1 ; j ; --j) {
				if (tag[i] == tag[j]) continue ;

				int v = abs(s[i] - s[j]) ;
				ll p1 = f[j] + v , p2 = f[i] + v ;
				f[i] = std::max(f[i] , p1) ;
				f[j] = std::max(f[j] , p2) ;

				ans = std::max(ans , std::max(f[i] , f[j])) ;
			}

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}