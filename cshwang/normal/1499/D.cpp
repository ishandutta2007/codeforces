#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 20 + 5 , MAX_M = 2e7 + 10 ;

bool ap[MAX_M] ;
int T , n , c , d , x , tot , pw[MAX_N] , f[MAX_M] , pri[MAX_M] ;

void init() {
	pw[0] = 1 ;
	for (int i = 1 ; i <= 20 ; ++i) pw[i] = pw[i - 1] << 1 ;

	///

	int n = 2e7 ; f[1] = 0 ;
	for (int i = 2 ; i <= n ; ++i) {
		if (!ap[i]) {f[i] = 1 ; pri[tot++] = i ;}

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * pri[j] ;
			if (tmp > n) break ;
			ap[tmp] = 1 ;

			if (i % pri[j]) f[tmp] = f[i] + 1 ;
			else {f[tmp] = f[i] ; break ;}
		}
	}
}

int work(int k) {
	int tmp = x / k + d ;
	if (tmp % c) return 0 ;
	tmp /= c ;

	return pw[f[tmp]] ;
}

int main() {
	init() ;

	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d %d" , &c , &d , &x) ;

		int ans = 0 ;
		for (int i = 1 ; i * i <= x ; ++i) {
			if (x % i) continue ;
			ans += work(i) ;
			if (x / i != i) ans += work(x / i) ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}