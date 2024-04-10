#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int INF = 0x3f3f3f3f ;

int n , t , wt , res ;

int main() {
	scanf("%d %d" , &n , &t) ;

	wt = INF ; res = -1 ;
	for (int i = 1 ; i <= n ; ++i) {
		int a , b ; scanf("%d %d" , &a , &b) ;

		for (; a < t ; a += b) ;
		if (a - t < wt) {wt = a - t ; res = i ;}
	}

	printf("%d\n" , res) ;

	return 0 ;
}