#include <bits/stdc++.h>

const int MAX_N = (1 << 10) + 10 ;

int T , n , a[MAX_N] , f[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

		///

		int tS = (1 << n) ;
		for (int i = 1 ; i < tS ; ++i) {
			f[i] = 0 ;
			for (int j = 0 ; j < n ; ++j)
				if ((1 << j) & i) f[i] += a[j] ;
		}

		bool ok = 0 ;
		for (int i = 1 ; i < tS ; ++i)
			for (int j = 1 ; j < tS ; ++j)
				if (!(i & j) && (abs(f[i]) == abs(f[j]))) ok = 1 ;

		for (int i = 0 ; i < n ; ++i) if (!a[i]) ok = 1 ;

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}