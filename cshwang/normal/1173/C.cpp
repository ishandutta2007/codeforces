#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

bool ap[MAX_N] ;
int n , a[MAX_N] , b[MAX_N] ;

bool check() {
	int p = -1 ;
	for (int i = 1 ; i <= n ; ++i) if (b[i] == 1) {p = i ; break ;}

	if (p == -1) return 0 ;

	bool ok = 1 ;
	for (int i = p + 1 ; i <= n ; ++i) if (b[i] - b[i - 1] != 1) ok = 0 ;

	return ok ;
}

int bf() {
	int p = 1 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (!b[i]) continue ;

		p = std::max(p , i - b[i] + 2) ; 
	}

	return p - 1 + n ;
}

int calc() {
	int nw = b[n] + 1 , p = 1 ;
	for (int i = 1 ; i <= n ; ++i) ap[a[i]] = 1 ;

	int ans = 0 ;
	for (; nw <= n ; ++nw) {
		if (!ap[nw]) return bf() ;

		++ans ; ap[b[p++]] = 1 ;
	}

	return ans ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &b[i]) ;

	///

	int ans = 0 ;
	if (check()) ans = calc() ;
	else ans = bf() ;

	printf("%d\n" , ans) ;

	return 0 ;
}