#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

char s[15] ;
bool yc[MAX_N] ;
ll nw , ans , INF ;
int n , a , tot , sta[MAX_N] ;

int main() {
	scanf("%d" , &n) ; nw = 1 ;
	INF = (1LL << 32) ;

	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s) ;

		if (s[0] == 'a') {
			ans += nw ;

			if (ans >= INF || yc[tot]) {ans = INF ; break ;}
		}
		else if (s[0] == 'f') {
			scanf("%d" , &a) ;

			sta[++tot] = a ; yc[tot] = 0 ;
			if (nw * a >= INF || yc[tot - 1]) yc[tot] = 1 ;
			else nw *= a ;
		}
		else if (s[0] == 'e') {
			if (!yc[tot]) nw /= sta[tot] ;
			--tot ;
		}
	}

	if (ans >= INF) printf("OVERFLOW!!!\n") ;
	else printf("%lld\n" , ans) ;

	return 0 ;
}