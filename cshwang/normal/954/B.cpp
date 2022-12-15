#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int n ;
char st[MAX_N] ;

bool cmp(int x , int y , int l) {
	for (int i = 0 ; i < l ; ++i)
		if (st[x + i] != st[y + i]) return 0 ;

	return 1 ;
}

int main() {
	scanf("%d" , &n) ;
	scanf("%s" , st) ;

	///

	int tmp = 1 ;
	for (int L = 2 ; (L << 1) <= n ; ++L)
		if (cmp(0 , L , L)) tmp = std::max(tmp , L) ;

	printf("%d\n" , n - tmp + 1) ;

	return 0 ;
}