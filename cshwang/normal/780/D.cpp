#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_N = 1e3 + 10 , MAX_H = 1e6 + 10 ;

int n , time , count[MAX_H] , ap[MAX_H] , vis[MAX_N] ;
char a[MAX_N][3] , b[MAX_N][3] , ch[MAX_N][3] , s1[MAX_N] , s2[MAX_N] ;

int Hash(char *c) {
	int c1 = c[0] - 'A' , c2 = c[1] - 'A' , c3 = c[2] - 'A' ;

	return c1 + c2 * 26 + c3 * 26 * 26 ;
}

void copy(char *a , char *b) {
	for (int i = 0 ; i < 3 ; ++i) a[i] = b[i] ;
}

bool replace(int h) {
	if (ap[h] == -1) return 1 ;
	else if (vis[ap[h]] == time) return 0 ;

	vis[ap[h]] = 1 ;
	int p = ap[h] , hb = Hash(b[p]) ;
	if (replace(hb)) {
		copy(ch[p] , b[p]) ;
		ap[hb] = p ;
		return 1 ;
	}
	
	return 0 ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s %s" , s1 , s2) ;
		a[i][0] = s1[0] ; a[i][1] = s1[1] ; a[i][2] = s1[2] ;
		b[i][0] = s1[0] ; b[i][1] = s1[1] ; b[i][2] = s2[0] ;

		++count[Hash(a[i])] ;
	}

	///

	memset(ap , -1 , sizeof(ap)) ;

	bool ans = 1 ;
	for (int i = 0 ; i < n && ans ; ++i) {
		int ha = Hash(a[i]) , hb = Hash(b[i]) ;
		if (count[ha] <= 1) continue ;

		if (ap[hb] != -1) {ans = 0 ; break ;}
		copy(ch[i] , b[i]) ;
		ap[hb] = i ;
	}
	for (int i = 0 ; i < n && ans ; ++i) {
		int ha = Hash(a[i]) , hb = Hash(b[i]) ;
		if (count[ha] != 1) continue ;

		if (ap[ha] == -1) {
			copy(ch[i] , a[i]) ;
			ap[ha] = i ;
		}
		else {
			++time ;

			if (replace(hb)) {
				copy(ch[i] , b[i]) ;
				ap[hb] = i ;
			}
			else ans = 0 ;
		}
	}

	if (ans) {
		printf("YES\n") ;

		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < 3 ; ++j) printf("%c" , ch[i][j]) ;
			printf("\n") ;
		}
	}
	else printf("NO\n") ;

	return 0 ;
}