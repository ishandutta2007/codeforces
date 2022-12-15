#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

struct data {int mi , ma ;}pl[MAX_N] , le[MAX_N] , ri[MAX_N] ;

int n ;

data count(data p , int x) {
	if (!p.mi) return (data){x , x} ;
	else return (data){std::min(p.mi , x) , std::max(p.ma , x)} ;
}

data cmp(data p , data q) {
	if (!p.mi) return q ;
	else if (!q.mi) return p ;
	else return (data){std::min(p.mi , q.mi) , std::max(p.ma , q.ma)} ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		int a ; scanf("%d" , &a) ;

		pl[a] = count(pl[a] , i) ;
	}
	for (int i = 1 ; i <= n ; ++i) le[i] = cmp(le[i - 1] , pl[i]) ;
	for (int i = n ; i ; --i) ri[i] = cmp(ri[i + 1] , pl[i]) ;

	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (!pl[i].mi) continue ;

		data tmp = cmp(le[i - 1] , ri[i + 1]) ;
		ans = std::max(ans , std::max(abs(pl[i].mi - tmp.ma) , abs(pl[i].ma - tmp.mi))) ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}