#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int T , n , a[MAX_N] ;

void print(int x , int y) {
	printf("1 %d %d\n" , x , y) ;
	printf("2 %d %d\n" , x , y) ;
	printf("1 %d %d\n" , x , y) ;
	printf("1 %d %d\n" , x , y) ;
	printf("2 %d %d\n" , x , y) ;
	printf("1 %d %d\n" , x , y) ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		
		///

		printf("%d\n" , n * 3) ;
		for (int i = 1 ; i <= n ; i += 2) print(i , i + 1) ;
	}

	return 0 ;
}