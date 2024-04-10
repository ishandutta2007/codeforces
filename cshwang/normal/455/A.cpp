#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

ll last , ans , f[MAX_N] ;
int n , maxa , cnt[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		int a ; scanf("%d" , &a) ;
		maxa = std::max(maxa , a) ; ++cnt[a] ;
	}

	///

	last = 0 ; f[1] = ans = cnt[1] ;

	for (int i = 2 ; i <= maxa ; ++i) {
		f[i] = last + (ll)cnt[i] * i;

		last = std::max(last , f[i - 1]) ;
		ans = std::max(ans , f[i]) ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}