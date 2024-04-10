#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n , ma , g ;

int gcd(int x , int y) {return y ? gcd(y , x % y) : x ;}

int main() {
	scanf("%d" , &n) ; g = ma = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int a ; scanf("%d" , &a) ;
		g = gcd(a , g) ; ma = std::max(ma , a) ;
	}

	///

	n = ma / g - n ;
	if (n & 1) printf("Alice\n") ;
	else printf("Bob\n") ;

	return 0 ;
}