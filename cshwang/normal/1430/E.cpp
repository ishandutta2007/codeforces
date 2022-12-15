#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 , MAX_M = 26 + 5 ;

bool ap[MAX_N] ;
char s[MAX_N] , rs[MAX_N] ;
int n , tre[MAX_N] , tot[MAX_M] , pl[MAX_M][MAX_N] ;

inline int lowbit(int x) {return x & (-x) ;}

void add(int x) {
	for (; x <= n ; x += lowbit(x)) ++tre[x] ;
}

int sum(int x) {
	int s = 0 ;
	for (; x ; x -= lowbit(x)) s += tre[x] ;

	return s ;
}

int getans(int c , int p) {
	for (; ap[pl[c][tot[c]]] ;) --tot[c] ;

	int np = pl[c][tot[c]] ;
	ap[np] = 1 ;

	int of = sum(n) - sum(np) ;
	add(np) ; np += of ;

	return np - p ;
}

int main() {
	scanf("%d" , &n) ;
	scanf("%s" , s) ;

	///

	for (int i = n ; i ; --i) s[i] = s[i - 1] ;
	for (int i = 1 ; i <= n ; ++i) rs[i] = s[n - i + 1] ;
	for (int i = n ; i ; --i) {
		int c = s[i] - 'a' ;
		pl[c][++tot[c]] = i ;
	}

	///

	int p = 1 ;
	ll ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		int c = rs[i] - 'a' ;
		for (; ap[p] ;) ++p ;

		if (s[p] == rs[i]) ap[p] = 1 ;
		else ans += getans(c , i) ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}