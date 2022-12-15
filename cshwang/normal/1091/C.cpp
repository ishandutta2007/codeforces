#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int n , cnt ;
ll ans[MAX_N] ;

void add(int x) {
	int step = n / x ;
	ans[cnt++] = (ll)(n - x + 2) * step / 2 ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i * i <= n ; ++i) {
		if (n % i) continue ;
		add(i) ; if (i != n / i) add(n / i) ;
	}

	std::sort(ans + 0 , ans + cnt) ;
	for (int i = 0 ; i < cnt ; ++i) printf("%lld " , ans[i]) ;
	printf("\n") ;

	return 0 ;
}