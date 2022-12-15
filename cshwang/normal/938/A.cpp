#include <stdio.h>
#include <stdlib.h>

#define DBEUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int n ;
char s[MAX_N] ;

bool ok(int x) {
	if (s[x] == 'a') return 1 ;
	else if (s[x] == 'e') return 1 ;
	else if (s[x] == 'i') return 1 ;
	else if (s[x] == 'o') return 1 ;
	else if (s[x] == 'u') return 1 ;
	else if (s[x] == 'y') return 1 ;
	else return 0 ;
}

int check() {
	for (int i = 0 ; i < n - 1 ; ++i)
		if (ok(i) && ok(i + 1)) return i + 1 ;

	return -1 ;
}

void del(int x) {
	--n ;
	for (int i = x ; i < n ; ++i) s[i] = s[i + 1] ;
}

int main() {
	scanf("%d" , &n) ;
	scanf("%s" , s) ;

	///

	for (; ;) {
		int p = check() ;
		if (p == -1) break ;

		del(p) ;
	}

	for (int i = 0 ; i < n ; ++i) printf("%c" , s[i]) ;
	printf("\n") ;

	return 0 ;
}