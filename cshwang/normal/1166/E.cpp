#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e4 + 10 , MAX_M = 50 + 5 ;

int m , n ;
int a[MAX_M][MAX_N] ;

bool sta(int x , int y , int op) {
	bool ok = 1 ;
	for (int i = 0 ; i < n ; ++i) {
		int p = a[x][i] , q = a[y][i] ^ 1 ;
		p ^= op ; q ^= op ;

		if (p < q) ok = 0 ;
	}

	return ok ;
}

int main() {
	scanf("%d %d" , &m , &n) ;
	for (int i = 0 ; i < m ; ++i) {
		int o ; scanf("%d" , &o) ;
		for (int j = 0 ; j < o ; ++j) {
			int t ; scanf("%d" , &t) ;
			a[i][t] = 1 ;
		}
	}

	///

	bool ok = 1 ;
	for (int i = 0 ; i < m ; ++i)
		for (int j = 0 ; j < m ; ++j)
			if (i != j && (sta(i , j , 0) || sta(i , j , 1))) ok = 0 ;

	if (ok) printf("possible\n") ;
	else printf("impossible\n") ;

	return 0 ;
}