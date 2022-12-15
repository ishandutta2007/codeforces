#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

ll ans ;
int n , m , L , R , a[MAX_N] , que[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	L = 1 ; R = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		for (; L <= R ;)
			if ((a[que[L]] << 1) > a[i]) {
				ans += a[i] / 2 ;

				a[que[L]] -= a[i] / 2 ;
				a[i] %= 2 ; break ;
			}
			else {
				ans += a[que[L]] ;

				a[i] -= a[que[L]] << 1 ;
				a[que[L]] = 0 ; ++L ;
			}

		ans += a[i] / 3 ;
		a[i] %= 3 ;

		if (a[i]) que[++R] = i ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}