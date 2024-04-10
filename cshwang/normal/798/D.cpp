#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 ;

struct data {
	int a , b , idx ;
}t[MAX_N] ;

int n , m , ans[MAX_N] ;

bool cmp(data x , data y) {return x.a > y.a ;}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) t[i].idx = i ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &t[i].a) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &t[i].b) ;

	///

	std::sort(t + 1 , t + 1 + n , cmp) ;

	t[n + 1].b = -1 ;
	m = 0 ; ans[m++] = t[1].idx ;
	for (int i = 2 ; i <= n ; i += 2)
		if (t[i].b > t[i + 1].b) ans[m++] = t[i].idx ;
		else ans[m++] = t[i + 1].idx ;

	printf("%d\n" , m) ;
	for (int i = 0 ; i < m ; ++i) printf("%d " , ans[i]) ;
	printf("\n") ;

	return 0 ;
}