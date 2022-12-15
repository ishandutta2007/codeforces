#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int a , b , c ;

int trans(int x) {
	if (x == 0) return 0 ;
	else if (x < 0) return -1 ;
	else return 1 ;
}

int main() {
	scanf("%d %d %d" , &a , &b , &c) ;
	a -= b ;

	int p1 = trans(a - c) , p2 = trans(a + c) ;

	if (p1 != p2) printf("?\n") ;
	else if (p1 < 0) printf("-\n") ;
	else if (p1 > 0) printf("+\n") ;
	else printf("0\n") ;

	return 0 ;
}