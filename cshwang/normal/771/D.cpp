#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 75 + 10 , INF = 0x3f3f3f3f ;

char s[MAX_N] ;
int n , tv , tk , tx , f[MAX_N][MAX_N][MAX_N][2] ;

void check(int p , int &v , int &k , int &x) {
	if (s[p] == 'V') ++v ;
	else if (s[p] == 'K') ++k ;
	else ++x ;
}

void trans(int v , int k , int x , int op) {
	int sv , sk , sx , cv , ck , cx ;
	sv = sk = sx = 0 ;
	
	if (k + 1 <= tk && !op) {
		cv = ck = cx = 0 ;
		for (int i = 0 ; i < n ; ++i) {
			check(i , cv , ck , cx) ;

			if (cv > v && s[i] == 'V') ++sk ;
			if (cx > x && s[i] == 'X') ++sk ;
			if (ck == k + 1) break ;
		}

		f[v][k + 1][x][0] = std::min(f[v][k][x][op] + sk , f[v][k + 1][x][0]) ;
	}

	if (v + 1 <= tv) {
		cv = ck = cx = 0 ;
		for (int i = 0 ; i < n ; ++i) {
			check(i , cv , ck , cx) ;

			if (ck > k && s[i] == 'K') ++sv ;
			if (cx > x && s[i] == 'X') ++sv ;
			if (cv == v + 1) break ;
		}

		f[v + 1][k][x][1] = std::min(f[v][k][x][op] + sv , f[v + 1][k][x][1]) ;
	}

	if (x + 1 <= tx) {
		cv = ck = cx = 0 ;
		for (int i = 0 ; i < n ; ++i) {
			check(i , cv , ck , cx) ;

			if (ck > k && s[i] == 'K') ++sx ;
			if (cv > v && s[i] == 'V') ++sx ;
			if (cx == x + 1) break ;
		}

		f[v][k][x + 1][0] = std::min(f[v][k][x][op] + sx , f[v][k][x + 1][0]) ;
	}
}

int main() {
	scanf("%d" , &n) ;
	scanf("%s" , s) ;

	///
	
	for (int i = 0 ; i < n ; ++i) {
		check(i , tv , tk , tx) ;
		if (s[i] != 'V' && s[i] != 'K') s[i] = 'X' ;
	}
	for (int v = 0 ; v <= tv ; ++v)
		for (int k = 0 ; k <= tk ; ++k)
			for (int x = 0 ; x <= tx ; ++x)
				f[v][k][x][0] = f[v][k][x][1] = INF ;

	///
	
	f[0][0][0][0] = 0 ;
	for (int i = 0 ; i <= n ; ++i)
		for (int v = 0 ; v <= std::min(i , tv) ; ++v)
			for (int k = 0 ; k <= std::min(i - v , tk) ; ++k) {
				int x = i - v - k ;
				if (v > tv || k > tk || x > tx) continue ;

				for (int op = 0 ; op < 2 ; ++op)
					if (f[v][k][x][op] < INF) trans(v , k , x , op) ;
			}

	printf("%d\n" , std::min(f[tv][tk][tx][0] , f[tv][tk][tx][1])) ;

	return 0 ;
}