#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int T , n ;
char s[MAX_N] ;

int work(int x , int y) {
	int *p = &x ;
	if (n & 1 && s[n >> 1] == '0') {
		++x ; p = &y ; s[n >> 1] = '1' ;
	}

	for (int i = 0 ; i < n ; ++i) if (s[i] == '0') (*p) += 2 ;

	return y - x ;
}

int main() {
	int T ; scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %s" , &n , s) ;

		int ans = work(0 , 0) ;
		if (ans > 0) printf("ALICE\n") ;
		else if (ans == 0) printf("DRAW\n") ;
		else printf("BOB\n") ;
	}

	return 0 ;
}