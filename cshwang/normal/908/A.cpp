#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 50 + 10 ;

char s[MAX_N] ;

int main() {
	scanf("%s" , s) ;
	int len = strlen(s) , ans = 0 ;

	for (int i = 0 ; i < len ; ++i) {
		char c = s[i] ;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++ans ;
		else if ('0' <= c && c <= '9' && c != '0' && c != '2' && c != '4' && c != '6' && c != '8') ++ans ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}