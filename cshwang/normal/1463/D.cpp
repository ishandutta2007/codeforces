#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 4e5 + 10 ;
int T , n , a[MAX_N] , b[MAX_N] ;

bool check(int x) {
	int c = 0 , nw = 0 ;
	for (int i = (n << 1) ; i ; --i) {
		if (nw == x) return 1 ;
		if (b[i] == 1) continue ;
		++nw ;
		if (a[x + 1 - nw] > i) return 0 ;
	}

	return 1 ;
}

bool check1(int x) {
	int c = 0 , nw = n + 1 , p = 0 ;
	for (int i = 1 ; i <= (n << 1) ; ++i) {
		if (p == x) return 1 ;
		if (b[i] == 1) continue ;
		--nw ; ++p ;
		if (a[n + 1 - (x + 1 - (n + 1 - nw))] < i) return 0 ;
	}
	return 1 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= (n << 1) ; ++i) b[i] = 0 ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , b[a[i]] = 1 ;
		std::sort(a + 1 , a + 1 + n) ;

		int l = 1 , r = n , L = 0 ;
		for (; l <= r ;) {
			int mid = (l + r) >> 1 ;
			if (check(mid) == 1) L = mid , l = mid + 1 ;
			else r = mid - 1 ;
		}
		l = 1 ; r = n ;

		int R = 0 ;
		for (; l <= r ;) {
			int mid = (l + r) >> 1 ;
			if (check1(mid) == 1) R = mid , l = mid + 1 ;
			else r = mid - 1 ;
		}
		R = n - R;
		printf("%d\n", std::max(0 , L - R + 1)) ;
	}
}