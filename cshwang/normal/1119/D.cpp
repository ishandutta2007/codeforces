#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define	ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 2e18 ;
const int MAX_N = 1e5 + 10 ;

struct QUERY {
	ll R , idx ;
}qry[MAX_N] ;
struct data {ll num , lef ;}dt[MAX_N] ;

int n , m ;
ll s[MAX_N] , ans[MAX_N] ;

inline ll read() {
	char c = getchar() ;
	ll num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

bool cmp1(QUERY a , QUERY b) {return a.R < b.R ;}
bool cmp2(data a , data b) {return a.lef < b.lef ;}

int main() {
	n = read() ;
	for (int i = 1 ; i <= n ; ++i) s[i] = read() ;
	m = read() ;
	for (int i = 0 ; i < m ; ++i) {
		ll L , R ; L = read() ; R = read() ;

		qry[i] = (QUERY){R - L + 1 , i} ;
	}

	///

	std::sort(s + 1 , s + 1 + n) ;
	std::sort(qry + 0 , qry + m , cmp1) ;

	int t = 1 ; dt[1].num = s[1] ;
	for (int i = 2 ; i <= n ; ++i) if (s[i] != s[i - 1]) dt[++t].num = s[i] ;

	n = t ;
	for (int i = 1 ; i < n ; ++i) dt[i].lef = dt[i + 1].num - dt[i].num ;
	dt[n].lef = INF ;
	std::sort(dt + 1 , dt + n + 1 , cmp2) ;

	///

	int L = 1 ; ll sum = 0 ;
	for (int i = 0 ; i < m ; ++i) {
		QUERY *p = &qry[i] ;
		for (; p->R > dt[L].lef ; ++L) sum += dt[L].lef , --n ;

		ans[p->idx] = sum + n * p->R ;
	}

	for (int i = 0 ; i < m ; ++i) printf("%lld " , ans[i]) ;
	printf("\n") ;

	return 0 ;
}