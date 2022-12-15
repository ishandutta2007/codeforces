#include <stdio.h>
#include <stdlib.h>

#define db double
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct data {int n ; db p ;}b[MAX_N] ;

db p[MAX_N] ;
int T , n , m , a[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) , p[i] = 0 ;
		for (int i = 0 ; i < m ; ++i) scanf("%d %lf" , &b[i].n , &b[i].p) ;

		///

		int pt = n + 1 ;
		for (; pt > 1 && a[pt - 1] == pt - 1 ; --pt) ;
		--pt ;

		if (!pt) {printf("%0.7lf\n" , 1.0) ; continue ;}

		db nw = 1 , ans = 0 ;
		for (int i = 0 ; i < m ; ++i) {
			if (b[i].n < pt) continue ;
			if (b[i].n >= pt) ans += nw * b[i].p ;
			nw *= (1 - b[i].p) ;
		}

		printf("%0.7lf\n" , ans) ;
	}

	return 0 ;
}