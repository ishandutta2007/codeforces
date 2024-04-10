#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 ;

int k , len ;
char s[MAX_N] ;

int main() {
	scanf("%d" , &k) ;
	scanf("%s" , s) ; len = strlen(s) ;

	///

	std::sort(s + 0 , s + len) ;
	int sum = 0 ;
	for (int i = 0 ; i < len ; ++i) sum += s[i] - '0' ;
	int i ;
	for (i = 0 ; i < len && sum < k ; ++i) {
		sum += '9' - s[i] ;
	}
	printf("%d\n" , i) ;

	return 0 ;
}