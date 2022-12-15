#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ull unsigned long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

std::map<ull , bool> ap ;

const int MAX_N = 1e3 + 10 , MAX_L = 500 + 10 ;

char s[MAX_L] ;
int n , m , fn , fm , sh , base ;

ull gethash() {
	ull h = 0 ;
	int len = strlen(s) ;
	for (int i = 0 ; i < len ; ++i) h = h * base + s[i] - 'a' ;

	return h ;
}

int main() {
	srand(19260817) ; base = 27 + rand() % 32767 ;

	///

	scanf("%d %d" , &n , &m) ; fn = n ; fm = m ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s) ; 

		ull tmp = gethash() ;
		ap[tmp] = 1 ;
	}
	for (int i = 0 ; i < m ; ++i) {
		scanf("%s" , s) ; 

		ull tmp = gethash() ;
		if (ap[tmp]) {++sh ; --fn ; --fm ;}
	}

	///

	fn += (sh + 1) >> 1 ; fm += sh >> 1 ;

	if (fn > fm) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}