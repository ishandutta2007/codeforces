#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e4 + 10 ;

int n ;
bool ok ;
char s[5] = {'a' , 'e' , 'i' , 'o' , 'u'} ;

void print(int n , int m) {
	for (int i = 0 ; i < n ; ++i) {
		int p = i % 5 ;
		for (int j = 0 ; j < m ; ++j , (++p) %= 5) printf("%c" , s[p]) ;
	}

	printf("\n") ;
}

int main() {
	scanf("%d" , &n) ;
	
	ok = 0 ;
	for (int i = 2 ; i * i <= n && !ok ; ++i) {
		if (n % i) continue ;
		int j = n / i ;

		if (i >= 5 && j >= 5) {ok = 1 ; print(i , j) ;}
	}

	if (!ok) printf("-1\n") ;

	return 0 ;
}