#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int x , d , n ;

int getn(int x) {
	int s = 0 ;

	for (int i = 30 ; i ; --i) {
		int a = (1 << i) - 1 ;
		for (; x >= a ; x -= a) s += i ;
	}

	return s ;
}

void print(int x , ll num) {
	for (; x-- ;) printf("%lld " , num) ;
}

int main() {
	scanf("%d %d" , &x , &d) ;

	n = getn(x) ;
	printf("%d\n" , n) ;

	ll num = 1 ;
	for (int i = 30 ; i ; --i) {
		int a = (1 << i) - 1 ;
		for (; x >= a ; x -= a) print(i , num) , num += d ;
	}
	printf("\n") ;

	return 0 ;
}