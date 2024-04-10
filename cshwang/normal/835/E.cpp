#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int n , x , y , tot , pl , df , st[MAX_N] ;

int ask(int n) {
	printf("? %d " , n) ;
	for (int i = 1 ; i <= n ; ++i) printf("%d " , st[i]) ;
	printf("\n") ;

	fflush(stdout) ;

	int res ; scanf("%d" , &res) ;
	return res ;
}

int find() {
	int L = 0 , R = tot + 1 ;

	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 , t = ask(mid) ;

		if (t == (x ^ y) || t == y) R = mid ;
		else L = mid ;
	}

	return st[R] ;
}

int main() {
	scanf("%d %d %d" , &n , &x , &y) ;
	for (int i = 0 ; i <= 9 ; ++i) {
		if ((1 << i) > n) break ;

		tot = 0 ;
		for (int j = 1 ; j <= n ; ++j) if (j & (1 << i)) st[++tot] = j ;

		int t = ask(tot) ;
		if (t == (x ^ y) || t == y) {pl = i ; df |= (1 << i) ;}
	}

	///

	tot = 0 ;
	for (int i = 1 ; i <= n ; ++i) if (i & (1 << pl)) st[++tot] = i ;

	int p1 = find() , p2 = p1 ^ df ;
	if (p1 > p2) std::swap(p1 , p2) ;

	printf("! %d %d\n" , p1 , p2) ;

	return 0 ;
}