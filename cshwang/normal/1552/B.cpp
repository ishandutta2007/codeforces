#include <bits/stdc++.h>

const int MAX_N = 5e4 + 10 ;

struct data {
	int r[5] ;

	friend bool operator < (data &a , data &b) {
		int cnt = 0 ;
		for (int i = 0 ; i < 5 ; ++i) if (a.r[i] < b.r[i]) ++cnt ;
		
		return cnt < 3 ;
	}
}a[MAX_N] ;

int T , n ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 0 ; j < 5 ; ++j) scanf("%d" , &a[i].r[j]) ;

		///

		int p = 1 ;
		for (int i = 2 ; i <= n ; ++i) if (a[p] < a[i]) p = i ;

		bool ok = 1 ;
		for (int i = 1 ; i <= n ; ++i) {
			if (i == p) continue ;
			if (a[p] < a[i]) ok = 0 ;
		}

		if (ok) printf("%d\n" , p) ;
		else printf("-1\n") ;
	}

	return 0 ;
}