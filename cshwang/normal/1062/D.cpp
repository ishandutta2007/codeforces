#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

ll val[MAX_N] ;
int n , fa[MAX_N] ;

int findset(int x) {
	return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;
}

int main() {
	scanf("%d" , &n) ;

	///

	for (int i = 1 ; i <= n ; ++i) fa[i] = -1 ;
	for (int i = 2 ; i <= n ; ++i)
		for (int j = (i << 1) ; j <= n ; j += i) {
			int fi = findset(i) , fj = findset(j) ;
			if (fi != fj) fa[fj] = fi , val[fi] += val[fj] ;

			val[fi] += (j / i) << 2 ;
		}

	///

	ll ans = 0 ;
	for (int i = 2 ; i <= n ; ++i)
		if (fa[i] == -1) ans = std::max(ans , val[i]) ;
	printf("%lld\n" , ans) ;

	return 0 ;
}