#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct data {int x , y ;}f[MAX_N] ;

int n , ans ;
char s[MAX_N] ;

int check(int a) {
	return f[a].x > f[a].y ;
}

int main() {
	scanf("%d" , &n) ;
	scanf("%s" , s) ;

	f[0] = (data){0 , 0} ;
	for (int i = 1 ; i <= n ; ++i) {
		char c = s[i - 1] ;
		f[i] = f[i - 1] ;

		if (c == 'U') ++f[i].y ;
		else ++f[i].x ;

		if (i == 1) continue ;
		if (f[i - 1].x != f[i - 1].y) continue ;

		if (check(i - 2) ^ check(i)) ++ans ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}