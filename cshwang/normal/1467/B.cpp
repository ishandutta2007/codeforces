#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

ll b[MAX_N] ;
int T , n , a[MAX_N] ;

bool check(int x) {
	if (x <= 1 || x >= n) return 0 ;

	return b[x] * b[x + 1] < 0 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		for (int i = 2 ; i <= n ; ++i) b[i] = a[i] - a[i - 1] ;

		///

		int ans = 0 ;
		for (int i = 2 ; i < n ; ++i) if (check(i)) ++ans ;

		int res = ans ;
		for (int i = 2 ; i <= n ; ++i) {
			int tmp = ans ;
			if (check(i - 1)) --tmp ;
			if (check(i)) --tmp ;

			if (i + 1 < n) {
				ll p = a[i + 1] - a[i - 1] ;
				if (p * b[i + 2] >= 0 && check(i + 1)) --tmp ;
				else if (p * b[i + 2] < 0 && !check(i + 1)) ++tmp ;
			}
			res = std::min(res , tmp) ;
		}

		for (int i = 2 ; i <= n ; ++i) {
			int tmp = ans ;
			if (check(i)) --tmp ;
			if (check(i + 1)) --tmp ;

			if (i - 1 > 1) {
				ll p = a[i + 1] - a[i - 1] ;
				if (p * b[i - 1] >= 0 && check(i - 1)) --tmp ;
				else if (p * b[i - 1] < 0 && !check(i - 1)) ++tmp ;
			}
			res = std::min(res , tmp) ;
		}

		printf("%d\n" , res) ;
	}

	return 0 ;
}