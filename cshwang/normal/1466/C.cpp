#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int T , n ;
char s[MAX_N] ;
bool ap[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%s" , s) ; n = strlen(s) ;

		///

		for (int i = 0 ; i < n ; ++i) ap[i] = 0 ;

		int ans = 0 ;
		if (s[0] == s[1]) {++ans ; ap[1] = 1 ;}
		for (int i = 2 ; i < n ; ++i)
			if (s[i - 1] == s[i] && !ap[i - 1]) {++ans ; ap[i] = 1 ;}
			else if (s[i - 2] == s[i] && !ap[i - 2]) {++ans ; ap[i] = 1 ;}
		printf("%d\n" , ans) ;
	}

	return 0 ;
}