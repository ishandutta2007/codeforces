#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 , K = 1e6 ;

int Q , sum[MAX_N][10] ;

int div(int x) {
	int s = 1 ;
	for (; x ; x /= 10)
		if (x % 10) s *= (x % 10) ;
	
	return s ;
}

int check(int x) {
	int a = div(x) ;

	if (a < 10) return a ;
	else return check(a) ;
}

int main() {
	sum[0][0] = 1 ;
	for (int i = 1 ; i <= K ; ++i) {
		for (int j = 0 ; j < 10 ; ++j) sum[i][j] = sum[i - 1][j] ;

		int g = check(i) ;
		++sum[i][g] ;
	}

	///

	scanf("%d" , &Q) ;
	for (int i = 0 ; i < Q ; ++i) {
		int l , r , k ;
		scanf("%d %d %d" , &l , &r , &k) ;

		printf("%d\n" , sum[r][k] - sum[l - 1][k]) ;
	}

	return 0 ;
}