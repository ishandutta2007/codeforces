#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

char s[MAX_N] ;
int t , n , m , tot , len[MAX_N] , pl[MAX_N] ;

void deca() {
	int p = pl[tot] ;
	--len[p] ;

	if (len[p] == 2) --tot ;
}

void update(int x) {
	for (; tot ;) {
		int p = pl[tot] ;
		if (p < x) --tot ;
		else return ;
	}
}

int main() {
	scanf("%d" , &t) ;
	for (; t-- ;) {
		scanf("%d" , &n) ;
		scanf("%s" , s) ;

		///

		m = 0 ;
		int cnt = 1 ; char c = s[0] ;
		for (int i = 1 ; i < n ; ++i)
			if (s[i] != c) {len[m++] = cnt ; c = s[i] ; cnt = 1 ;}
			else ++cnt ;
		len[m++] = cnt ;

		///

		tot = 0 ;
		for (int i = m - 1 ; i >= 0 ; --i) if (len[i] > 2) pl[++tot] = i ;

		int ans = 0 ;
		for (int i = 0 ; i < m ; ++i) {
			if (!len[i]) continue ;
			if (len[i] == 1) {
				update(i) ;
				if (tot) {deca() ; ++ans ;}
				else {--len[i + 1] ; ++ans ;}
			}
			else ++ans ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}