#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

int T , n , k , L , R , h[MAX_N] ;

bool merge(int &L , int &R , int aL , int aR) {
	if (R < aL || aR < L) return 0 ;

	L = std::max(L , aL) ; R = std::min(R , aR) ;
	return 1 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &h[i]) ;

		///

		L = R = h[1] ; bool ok = 1 ;
		for (int i = 2 ; i <= n && ok ; ++i) {
			int aL , aR ;
			if (i < n) aL = h[i] , aR = h[i] + k - 1 ;
			else aL = aR = h[i] ;

			L -= (k - 1) ; R += (k - 1) ;
			ok &= merge(L , R , aL , aR) ;
		}

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}