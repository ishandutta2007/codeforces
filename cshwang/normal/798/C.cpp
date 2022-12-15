#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10 ;

int n , ans , a[MAX_N] ;

int gcd(int x , int y) {return y ? gcd(y , x % y) : x ;}

int main() {
	int d = 0 ;
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d" , &a[i]) ;
		d = gcd(a[i] , d) ; a[i] %= 2 ;
	}

	printf("YES\n") ;
	if (d > 1) {
		printf("0\n") ;

		return 0 ;
	}

	///

	ans = 0 ;
	for (int i = 0 ; i < n - 1 ; ++i) if (a[i] & a[i + 1]) a[i] = a[i + 1] = 0 , ++ans ;
	for (int i = 0 ; i < n - 1 ; ++i) if (a[i] ^ a[i + 1]) a[i] = a[i + 1] = 0 , ans += 2 ;

	printf("%d\n" , ans) ;

	return 0 ;
}