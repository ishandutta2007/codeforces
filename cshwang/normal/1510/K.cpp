#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e3 + 10 ;

int n , a[MAX_N] , b[MAX_N] , c[MAX_N] ;

bool check(int *a) {
	for (int i = 1 ; i <= n ; ++i)
		if (i != a[i]) return 0 ;
	return 1 ;
}

void oper0(int *a) {
	for (int i = 1 ; i <= n ; i += 2) std::swap(a[i] , a[i + 1]) ;
}

void oper1(int *a) {
	int m = n >> 1 ;
	for (int i = 1 ; i <= m ; ++i) std::swap(a[i] , a[i + m]) ;
}

int main() {
	scanf("%d" , &n) ; n <<= 1 ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	if (check(a)) {printf("0\n") ; return 0 ;}

	///

	for (int i = 1 ; i <= n ; ++i) b[i] = a[i] , c[i] = a[i] ;

	int ans = -1 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (i & 1) oper1(b) , oper0(c) ;
		else oper0(b) , oper1(c) ;

		if (check(b) || check(c)) {ans = i ; break ;}
	}
	printf("%d\n" , ans) ;

	return 0 ;
}