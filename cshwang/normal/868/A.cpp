#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 100 + 10 ;

int n ;
bool ok[2] ;
char pw[5] , s[5] ;

int main() {
	scanf("%s" , pw) ;
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s) ;
		if (s[1] == pw[0]) ok[0] = 1 ;
		if (s[0] == pw[1]) ok[1] = 1 ;
		if (s[0] == pw[0] && s[1] == pw[1]) ok[0] = ok[1] = 1 ;
	}

	if (ok[0] && ok[1]) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}