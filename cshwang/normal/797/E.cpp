#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 ;

struct Query {
	int p , k , idx , ans ;
}que[MAX_N] ;

int n , m , block , a[MAX_N] , f[MAX_N] ;

bool cmp1(Query x , Query y) {return x.k < y.k ;}
bool cmp2(Query x , Query y) {return x.idx < y.idx ;}

int getans(int p , int k) {
	int t = 0 ;
	for (; p <= n ; p = p + a[p] + k , ++t) ;

	return t ;
}

void dp(int k) {
	for (int i = n ; i ; --i) {
		int np = i + a[i] + k ;
		if (np > n) f[i] = 1 ;
		else f[i] = f[np] + 1 ;
	}
}

int main() {
	scanf("%d" , &n) ; block = (int)sqrt(n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	scanf("%d" , &m) ;
	for (int i = 0 ; i < m ; ++i) scanf("%d %d" , &que[i].p , &que[i].k) , que[i].idx = i ;

	///

	std::sort(que + 0 , que + m , cmp1) ;

	int last = -1 ;
	for (int i = 0 ; i < m ; ++i) {
		Query *pt = &que[i] ;
		if (pt->k > block) pt->ans = getans(pt->p , pt->k) ;
		else {
			if (last != pt->k) dp(pt->k) , last = pt->k ;
			pt->ans = f[pt->p] ;
		}
	}

	std::sort(que + 0 , que + m , cmp2) ;

	for (int i = 0 ; i < m ; ++i) printf("%d\n" , que[i].ans) ;

	return 0 ;
}