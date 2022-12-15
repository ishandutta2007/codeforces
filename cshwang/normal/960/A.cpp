#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e3 + 10 ;

int len ;
char s[MAX_N] ;

int main() {
	scanf("%s" , s) ;
	len = strlen(s) ;

	char nc = 'a' ; bool ok = 1 ;
	int s1 = 0 , s2 = 0 , s3 = 0 ;

	for (int i = 0 ; i < len && ok ; ++i) {
		if (nc > s[i]) ok = 0 ;
		else {
			nc = s[i] ;
			if (nc == 'a') ++s1 ;
			else if (nc == 'b') ++s2 ;
			else if (nc == 'c') ++s3 ;
		}
	}

	if (!ok || !s1 || !s2 || !s3) printf("NO\n") ;
	else {
		if (s3 == s1 || s3 == s2) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}