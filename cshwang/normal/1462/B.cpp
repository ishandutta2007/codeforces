#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 200 + 5 ;
const char num[4] = {'2' , '0' , '2' , '0'} ;

int T , n ;
char s[MAX_N] ;

bool check(int x , int y) {
	int nw = 0 ;
	for (int i = 0 ; i < x ; ++i) if (s[i] != num[nw++]) return 0 ;
	for (int i = y + 1 ; i < n ; ++i) if (s[i] != num[nw++]) return 0 ;

	return 1 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		scanf("%s" , s) ;

		///

		int nl = n - 4 ; bool ok = 0 ;
		for (int i = 0 ; i < n && !ok ; ++i) {
			int j = i + nl - 1 ;
			if (j > n) continue ;

			if (check(i , j)) ok = 1 ;
		}

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}