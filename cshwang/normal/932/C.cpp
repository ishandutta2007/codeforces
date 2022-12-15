#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll x , y ;
int n , A , B , d ;

int exgcd(int A , int B , ll &x , ll &y) {
	if (!B) {x = 1 ; y = 0 ; return A ;}
	else {
		int d = exgcd(B , A % B , y , x) ;
		y -= (A / B) * x ;

		return d ;
	}
}

void prit(int p , int L) {
	for (int i = p + 1 ; i < p + L ; ++i) printf("%d " , i) ;
	printf("%d " , p) ;
}

void work() {
	int i = 1 ;
	for (int t = 0 ; t < x ; i += A , ++t) prit(i , A) ;
	for (int t = 0 ; t < y ; i += B , ++t) prit(i , B) ;

	printf("\n") ;
}

int main() {
	scanf("%d %d %d" , &n , &A , &B) ;
	d = exgcd(A , B , x , y) ;

	if (n % d) printf("-1\n") ;
	else {
		x *= (n / d) ; y *= (n / d) ;
		ll ad = B / d , bd = A / d ;

		if (x < 0 && y < 0) printf("-1\n") ;
		else if (x >= 0 && y < 0) {
			ll at = x / ad ;
			x  -= at * ad ; y += at * bd ;

			if (x >= 0 && y >= 0) work() ;
			else printf("-1\n") ;
		}
		else if (x < 0 && y >= 0) {
			ll at = y / bd ;
			y -= bd * at ; x += ad * at ;

			if (x >= 0 && y >= 0) work() ;
			else printf("-1\n") ;
		}
		else work() ;
	}

	return 0 ;
}