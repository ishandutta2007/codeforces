#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e3 + 10 ;

int T , n , a[MAX_N] ;

bool check(int x) {
	int t = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		t += a[i] ;
		if (t > x) return 0 ;
		else if (t == x) t = 0 ;
	}

	return 1 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		int tot = 0 ;
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , tot += a[i] ;

		///

		int ans = 0 ;
		for (int i = n ; i ; --i) {
			if (tot % i) continue ;
			if (check(tot / i)) {ans = n - i ; break ;}
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}