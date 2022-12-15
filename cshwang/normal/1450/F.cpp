#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int T , n , a[MAX_N] , cnt[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) cnt[i] = 0 ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , ++cnt[a[i]] ;

		int m = (n + 1) >> 1 ; bool ok = 1 ;
		for (int i = 1 ; i <= n && ok ; ++i) if (cnt[i] > m) ok = 0 ;
		if (!ok) {printf("-1\n") ; continue ;}

		///

		for (int i = 1 ; i <= n ; ++i) cnt[i] = 0 ;
		int prt = 1 ; ++cnt[a[1]] ; ++cnt[a[n]] ;
		for (int i = 2 ; i <= n ; ++i)
			if (a[i] == a[i - 1]) ++cnt[a[i - 1]] , ++cnt[a[i]] , ++prt ;
		for (int i = 1 ; i <= n ; ++i) prt = std::max(prt , cnt[i] - 1) ;

		printf("%d\n" , prt - 1) ;
	}

	return 0 ;
}