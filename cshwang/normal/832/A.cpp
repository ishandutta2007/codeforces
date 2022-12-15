#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll n , k ;

int main() {
	scanf("%lld %lld" , &n , &k) ;
	if ((n / k) % 2) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}