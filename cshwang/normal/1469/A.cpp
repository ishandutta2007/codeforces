#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

char s[MAX_N] ;
int T , n , c1 , c2 ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%s" , s) ;
		n = strlen(s) ;

		int tot = 0 , lef = 0 ;
		for (int i = 0 ; i < n ; ++i)
			if (s[i] == '(') ++tot ;
			else if (s[i] == ')') --tot ;
			else ++lef ;

		///

		int c1 = (lef + tot) >> 1 , c2 = (lef - tot) >> 1 ;
		if (c1 < 0 || c2 < 0 || ((lef ^ tot) & 1)) {printf("NO\n") ; continue ;}

		bool ok = 1 ;
		tot = 0 ;
		for (int i = 0 ; i < n ; ++i) {
			if (s[i] == '(') ++tot ;
			else if (s[i] == ')') --tot ;
			else {
				if (c1) ++tot , --c1 ;
				else --tot , --c2 ;
			}

			if (tot < 0) ok = 0 ;
		}

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}