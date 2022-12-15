#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int T , x ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &x) ;
		if (x > 45) {printf("-1\n") ; continue ;}

		ll nw = 1 , num = 9 , ans = 0 ;
		for (; x > 9 || (x > 0 && x >= num) ;) ans += num * nw , x -= (num--) , nw *= 10 ;
		ans += x * nw ;

		printf("%lld\n" , ans) ;
	}

	return 0 ;
}