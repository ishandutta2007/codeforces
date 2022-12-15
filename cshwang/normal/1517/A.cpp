#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll n ;
int T ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%lld" , &n) ;
		if (n % 2050) printf("-1\n") ;
		else {
			ll sum = 0 ;
			n /= 2050 ;

			for (; n ; n /= 10) sum += n % 10 ;
			printf("%lld\n" , sum) ;
		}
	}

	return 0 ;
}