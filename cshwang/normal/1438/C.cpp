#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n , m ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 0 ; i < n ; ++i , printf("\n"))
			for (int j = 0 ; j < m ; ++j) {
				int a ; scanf("%d" , &a) ;
				if (((i + j) & 1) == (a & 1)) ++a ;
				printf("%d " , a) ;
			}
	}

	return 0 ;
}