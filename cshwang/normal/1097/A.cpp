#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

bool ans ;
char a[5] , b[5] ;

int main() {
	scanf("%s" , a) ;

	ans = 0 ;
	for (int i = 0 ; i < 5 ; ++i) {
		scanf("%s" , b) ;

		if (a[0] == b[0] || a[1] == b[1]) ans = 1 ;
	}

	if (ans) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}