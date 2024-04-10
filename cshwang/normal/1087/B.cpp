#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int n , k , ans ;

int check(int p) {
	int q = n / p ;
	if (q >= k) return -1 ;

	return p * k + q ;
}

int main() {
	scanf("%d %d" , &n , &k) ;

	ans = -1 ;
	for (int i = 1 ; i <= n ; ++i)
		if (!(n % i)) {
			int tmp = check(i) ;
			
			if (ans == -1) ans = tmp ;
			else ans = std::min(ans , tmp) ;
		}

	printf("%d\n" , ans) ;

	return 0 ;
}