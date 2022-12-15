#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e3 + 10 ;

ll n ;
int T , tot , ans[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%lld" , &n) ;

		if (n & 1) printf("-1\n") ;
		else {
			n >>= 1 ;
			int cnt = 0 ; tot = 0 ;
			if (n & 1) {--n ; cnt = 1 ; ans[tot++] = 1 ;}

			for (int i = 1 ; (1LL << i) <= n ; ++i)
				if (n & (1LL << i)) {ans[tot++] = 1 ; ans[tot++] = i ; cnt += 1 + i ;}

			printf("%d\n" , cnt) ;
			for (int i = 0 ; i < tot ; ++i) {
				printf("1 ") ;
				for (int j = 1 ; j < ans[i] ; ++j) printf("0 ") ;
			}
			printf("\n") ;
		}
	}

	return 0 ;
}