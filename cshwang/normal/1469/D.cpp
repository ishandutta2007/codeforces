#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

struct data {int x , y ;}op[MAX_N] ;

int T , n , m ;

void work(int n) {
	for (int i = 3 ; i < n ; ++i) op[m++] = (data){i , i + 1} ;
	for (int t = n ; t > 1 ;) {
		t = (t + 1) >> 1 ;
		op[m++] = (data){n , 2} ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ; m = 0 ;

		///

		if (n <= 16) work(n) ;
		else {
			for (int i = 17 ; i < n ; ++i) op[m++] = (data){i , i + 1} ;
			for (int t = n ; t > 1 ;) {
				t = (t + 15) >> 4 ;
				op[m++] = (data){n , 16} ;
			}
			work(16) ;
		}

		printf("%d\n" , m) ;
		for (int i = 0 ; i < m ; ++i) printf("%d %d\n" , op[i].x , op[i].y) ;
	}

	return 0 ;
}