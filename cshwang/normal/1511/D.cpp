#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int n , k ;

bool print(int x) {
	printf("%c" , 'a' + x) ;
	--n ;

	if (n) return 0 ;
	else return 1 ;
}

void work() {
	for (; ;)
		for (int i = 0 ; i < k ; ++i) {
			if (print(i)) return ;
			for (int j = i + 1 ; j < k ; ++j) {
				if (print(i)) return ;
				if (print(j)) return ;
			}
		}
}

int main() {
	scanf("%d %d" , &n , &k) ;
	work() ;

	return 0 ;
}