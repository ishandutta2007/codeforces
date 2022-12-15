#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int n , cnt[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		int a ; scanf("%d" , &a) ;
		++cnt[a] ;
	}

	///

	bool ok = 0 ;
	for (int i = 1 ; i <= 1e5 && !ok ; ++i)
		if (cnt[i] & 1) ok = 1 ;

	if (ok) printf("Conan\n") ;
	else printf("Agasa\n") ;

	return 0 ;
}