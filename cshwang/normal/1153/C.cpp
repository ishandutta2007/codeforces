#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

char s[MAX_N] ;
int n , cnt[2] ;

int main() {
	scanf("%d %s" , &n , s) ;

	///

	if (n % 2) {printf(":(\n") ; return 0 ;}
	for (int i = 0 ; i < n ; ++i)
		if (s[i] == '(') ++cnt[0] ;
		else if (s[i] == ')') ++cnt[1] ;

	cnt[0] = (n >> 1) - cnt[0] ; cnt[1] = (n >> 1) - cnt[1] ;
	if (cnt[0] < 0 || cnt[1] < 0) {printf(":(\n") ; return 0 ;}

	for (int i = 0 ; i < n ; ++i)
		if (s[i] == '?') {
			if (cnt[0]) s[i] = '(' , --cnt[0] ;
			else s[i] = ')' ;
		}

	bool ok = 1 ; int sum = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		if (s[i] == '(') ++sum ;
		else --sum ;

		if (sum < 0) ok = 0 ;
		else if (!sum && i != n - 1) ok = 0 ;
	}

	if (ok) for (int i = 0 ; i < n ; ++i) printf("%c" , s[i]) ;
	else printf(":(") ;
	printf("\n") ;

	return 0 ;
}