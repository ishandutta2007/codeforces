#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct data{int x , y , pl ;} ;

std::vector<data> pt[MAX_N] ;

bool ok[MAX_N] ;
int T , n , m , ans , cnt[MAX_N] ;

void work(int pl , int ty) {
	if (ty) ++ans ;

	int i ; data *p ;
	int t = pt[pl].size() ;
	for (i = 0 , p = &pt[pl][0] ; i < t ; p = &pt[pl][++i]) {
		if (ok[p->pl]) continue ;
		++ans ; --cnt[p->y] ; ok[p->pl] = 1 ;

		if (cnt[p->y] == 1) work(p->y , 0) ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 1 ; i <= n ; ++i)
			pt[i].clear() , ok[i] = 0 , cnt[i] = 0 ;

		for (int i = 1 ; i <= m ; ++i) {
			int x , y ;
			scanf("%d %d" , &x , &y) ;
			if (x == y) continue ;

			++cnt[x] ; ++cnt[y] ;
			pt[x].push_back((data){x , y , i}) ;
			pt[y].push_back((data){y , x , i}) ;
		}

		///

		ans = 0 ;
		for (int i = 1 ; i <= n ; ++i) if (cnt[i] == 1) work(i , 0) ;
		for (int i = 1 ; i <= n ; ++i) if (cnt[i] > 1) work(i , 1) ;

		printf("%d\n" , ans) ;
	}

	return 0 ;
}