#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = (ll)1e19 ;

ll ans ;
int T , n , x , y ;

int gcd(int x , int y) {return y ? gcd(y , x % y) : x ;}

void check(int a) {
	int b = n - a ;
	if (!a || !b) return ;

	ll tmp = (ll)a * b / gcd(a , b) ;

	if (tmp < ans) ans = tmp , x = a , y = b ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		ans = INF ;

		scanf("%d" , &n) ;
		check(n / 2) ; check(n / 2 + 1) ;

		for (int i = 1 ; i * i <= n ; ++i) {
			if (n % i) continue ;

			check(i) ; check(n / i) ;
		}

		printf("%d %d\n" , x , y) ;
	}

	return 0 ;
}