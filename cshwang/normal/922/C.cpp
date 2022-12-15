#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll n , k ;

int main() {
	scanf("%I64d %I64d" , &n , &k) ;

	++n ;
	ll t = 1 ;
	for (; !(n % t) ;) ++t ;
	--t ;

	if (k <= t) printf("Yes\n") ;
	else printf("No\n") ;

	return 0 ;
}