#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int offset = 25e5 , MAX_N = 5e6 + 10 ;

struct data {int x , y ;}pr[MAX_N] ;

int n , cnt[MAX_N] , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;

	data tmp = (data){0 , 0} ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	bool ok = 0 ;
	for (int i = 1 ; i <= n && !ok ; ++i)
		for (int j = 1 ; j <= n ; ++j) {
			if (i == j) continue ;

			int tmp = a[i] - a[j] + offset ;
			if (cnt[tmp] && i != pr[tmp].x && i != pr[tmp].y && j != pr[tmp].x && j != pr[tmp].y) {
				printf("YES\n%d %d %d %d\n" , pr[tmp].x , j , i , pr[tmp].y) ;
				ok = 1 ; break ;
			}
			else {++cnt[tmp] ; pr[tmp] = (data){i , j} ;}
		}

	if (!ok) printf("NO\n") ;

	return 0 ;
}