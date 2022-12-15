#include <bits/stdc++.h>

const int MAX_N = 10 + 5 , INF = 1e6 ;

int T , n , val[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= 10 ; ++i) val[i] = -INF ;
		for (; n-- ;) {
			int x , y ; scanf("%d %d" , &x , &y) ;
			val[y] = std::max(val[y] , x) ;
		}

		int ans = 0 ;
		for (int i = 1 ; i <= 10 ; ++i) ans += val[i] ;
		if (ans < 0) printf("MOREPROBLEMS\n") ;
		else printf("%d\n" , ans) ;
	}

	return 0 ;
}