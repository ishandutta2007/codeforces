#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e5 + 10 , mod = 1e9 + 7 ;

int n , m , fa[MAX_N] , ans[MAX_N] ;

inline int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

int main() {
	scanf("%d %d" , &m , &n) ;
	for (int i = 1 ; i <= n + 1 ; ++i) fa[i] = -1 ;

	int tot = 0 ;
	for (int i = 1 ; i <= m ; ++i) {
		int tmp[2] = {n + 1 , n + 1} , k ;
		scanf("%d" , &k) ;

		for (int j = 0 ; j < k ; ++j) scanf("%d" , &tmp[j]) ;
		int fx = findset(tmp[0]) , fy = findset(tmp[1]) ;
		if (fx != fy) {
			ans[tot++] = i ;
			fa[fx] = fy ;
		}
	}

	///

	int res = 1 ;
	for (int i = 0 ; i < tot ; ++i) (res <<= 1) %= mod ;
	printf("%d %d\n" , res , tot) ;
	for (int i = 0 ; i < tot ; ++i) printf("%d " , ans[i]) ;
	printf("\n") ;

	return 0 ;
}