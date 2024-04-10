#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int n , m , k1 , k2 , a[MAX_N] , b[MAX_N] , c[MAX_N] ;

ll sq(int x) {return (ll)x * x ;}

bool cmp(int a , int b) {return a > b ;}

int main() {
	scanf("%d %d %d" , &n , &k1 , &k2) ; m = k1 + k2 ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &b[i]) ;
	for (int i = 0 ; i < n ; ++i) c[i] = abs(a[i] - b[i]) ;

	///

	for (int i = 0 ; i < m ; ++i) {
		std::sort(c + 0 , c + n , cmp) ;
		if (!c[0]) ++c[0] ;
		else --c[0] ;
	}

	ll sum = 0 ;
	for (int i = 0 ; i < n ; ++i) sum += sq(c[i]) ;

	printf("%lld\n" , sum) ;

	return 0 ;
}