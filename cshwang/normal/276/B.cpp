#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

char st[MAX_N] ;
int n , cnt['z' + 10] ;

int main() {
	scanf("%s" , st) ;
	n = strlen(st) ;

	///

	for (int i = 0 ; i < n ; ++i) ++cnt[st[i]] ;

	int sum = 0 , od = 0 ;
	for (int i = 'a' ; i <= 'z' ; ++i) {
		cnt[i] &= 1 ;
		sum ^= cnt[i] ; od |= cnt[i] ;
	}

	if (sum || !od) printf("First\n") ;
	else printf("Second\n") ;

	return 0 ;
}