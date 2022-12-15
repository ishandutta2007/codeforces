#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1000 + 10 ;

bool use[MAX_N] ;
int n , sum , a[MAX_N] , b[MAX_N] , c[MAX_N] , p[MAX_N] ;

int main() {
	sum = 0 ;
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d" , &b[i]) ;
		if (a[i] != b[i]) p[sum++] = i ;
		else use[b[i]] = 1 , c[i] = b[i] ;
	}

	///
	
	if (sum == 1) {
		int i ;
		for (i = 1 ; i <= n ; ++i) if (!use[i]) break ;
		c[p[0]] = i ;
	}
	else {
		if (use[a[p[0]]] || use[b[p[1]]]) {std::swap(a[p[0]] , b[p[0]]) ; std::swap(a[p[1]] , b[p[1]]) ;}
		c[p[0]] = a[p[0]] ; c[p[1]] = b[p[1]] ;
	}

	for (int i = 0 ; i < n ; ++i) printf("%d " , c[i]) ;
	printf("\n") ;

	return 0 ;
}