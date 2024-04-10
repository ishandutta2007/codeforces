#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e15 ;
const int MAX_N = 1e5 + 10 ;

struct data {ll t ; int x ;}a[MAX_N] ;

int T , n ;

bool cmp(data a , data b) {return a.t < b.t ;}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%lld %d" , &a[i].t , &a[i].x) ;
		std::sort(a + 1 , a + 1 + n , cmp) ;

		///

		ll ed = 0 ;
		int ex = 0 , ad = 0 , ans = 0 ;
		a[n + 1].t = INF ;
		for (int i = 1 ; i <= n ; ++i) {
			data *p = &a[i] ;
			if (ed <= p->t) {
				if (ex < p->x) ad = 1 ;
				else ad = -1 ;

				int nt = abs(ex - p->x) ;
				ex = p->x ;
				ed = p->t + nt ;

				if (ed <= a[i + 1].t) ++ans ;
			}
			else {
				int r1 = ex - (ed - p->t) * ad ,
					r2 = ex - (ed - std::min(ed , a[i + 1].t)) * ad ;
				
				if (ad < 0) {
					if (r2 <= p->x && p->x <= r1) ++ans ;
				}
				else {
					if (r1 <= p->x && p->x <= r2) ++ans ;
				}
			}
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}