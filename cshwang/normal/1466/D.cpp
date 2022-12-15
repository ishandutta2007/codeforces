#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct data {int w , lk ;}a[MAX_N] ;

int T , n ;
ll ans , res[MAX_N] ;

bool cmp(data a , data b) {return a.w < b.w ;}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ; ans = 0 ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i].w) ;
		for (int i = 1 ; i < n ; ++i) {
			int x , y ; scanf("%d %d" , &x , &y) ;
			ans += a[x].w + a[y].w ; ++a[x].lk ; ++a[y].lk ;
		}

		///

		for (int i = 1 ; i <= n ; ++i) --a[i].lk ;
		std::sort(a + 1 , a + 1 + n , cmp) ;

		res[n - 1] = ans ; int p = 1 ;
		for (int i = n - 2 ; i ; --i) {
			for (; !a[p].lk ; ++p) ;
			--a[p].lk ; ans -= a[p].w ;
			res[i] = ans ;
		}

		for (int i = 1 ; i < n ; ++i) printf("%lld " , res[i]) ;
		printf("\n") ;
	}

	return 0 ;
}