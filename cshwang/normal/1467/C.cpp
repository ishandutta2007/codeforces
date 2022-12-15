#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

int n[3] ;
ll s[3] , mia[3] , a[MAX_N] ;

int main() {
	for (int i = 0 ; i < 3 ; ++i) scanf("%d" , &n[i]) ;
	for (int i = 0 ; i < 3 ; ++i) {
		ll t = 0 , mi = -1 ;
		for (int j = 0 ; j < n[i] ; ++j) {
			scanf("%lld" , &a[j]) ;
			t += a[j] ;

			if (mi == -1) mi = a[j] ;
			else mi = std::min(mi , a[j]) ;
		}

		s[i] = t ; mia[i] = mi ;
	}

	///

	std::sort(s + 0 , s + 3) ;
	std::sort(mia + 0 , mia + 3) ;

	ll res = s[0] + s[1] + s[2] , tmp = std::min(s[0] , mia[0] + mia[1]) ;
	printf("%lld\n" , res - (tmp << 1)) ;

	return 0 ;
}