#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int t , n ;

int main() {
	scanf("%d" , &t) ;
	for (; t-- ; ) {
		scanf("%d" , &n) ;

		bool ok = 1 ;
		for (int i = 0 ; i * 7 <= n && ok ; ++i) {
			int nn = n - i * 7 ;
			for (int j = 0 ; j * 5 <= nn && ok ; ++j) {
				int nnn = nn - j * 5 ;

				if (!(nnn % 3)) {printf("%d %d %d\n" , nnn / 3 , j , i) ; ok = 0 ;}
			}
		}

		if (ok == 1) printf("-1\n") ;
	}

	return 0 ;
}