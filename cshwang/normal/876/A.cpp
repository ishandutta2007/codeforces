#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n , a , b , c , m , sm ;

int main() {
	scanf("%d %d %d %d" , &n , &a , &b , &c) ;
	m = std::min(a , std::min(b , c)) ;
	if (n == 1) printf("0\n") ;
	else if (m == a || m == b) printf("%d\n" , (n - 1) * m) ;
	else {
		if (a < b) sm = a ;
		else sm = b ;
		if (n > 2) printf("%d\n" , sm + (n - 2) * m) ;
		else printf("%d\n" , sm) ;
	}

	return 0 ;
}