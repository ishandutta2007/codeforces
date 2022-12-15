#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 500 + 10 , INF = 0x3f3f3f3f ;

bool f[MAX_N] ;
int T , n , x , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &x) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , f[i] = 0 ;

		///

		f[n + 1] = 1 ;
		a[0] = -1 ; a[n + 1] = INF ;
		for (int i = n ; i ; --i)
			if (a[i] <= a[i + 1]) f[i] = 1 ;
			else break ;

		if (f[1]) {printf("0\n") ; continue ;}

		///

		int ans = 0 , k = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			if (x < a[i]) {std::swap(x , a[i]) ; ++k ;}
			if (a[i] >= a[i - 1] && a[i] <= a[i + 1] && f[i + 1]) {ans = k ; break ;}
			else if (a[i - 1] > a[i]) break ;
		}

		if (!ans) printf("-1\n") ;
		else printf("%d\n" , ans) ;
	}

	return 0 ;
}