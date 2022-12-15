#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

struct data {int num , x ;} ;

std::vector<data> num ;

bool ud[MAX_N][MAX_N] ;
int T , n , m , nw[MAX_N] , ans[MAX_N][MAX_N] ;

bool cmp(data a , data b) {return a.num < b.num ;}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		num.clear() ;

		scanf("%d %d" , &n , &m) ;
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= m ; ++j) {
				int t ; scanf("%d" , &t) ;
				nw[i] = 1 ; ud[i][j] = 0 ; num.push_back((data){t , i}) ;
			}

		///

		int tot = num.size() ;
		std::sort(num.begin() , num.end() , cmp) ;
		for (int i = 0 ; i < m ; ++i) {
			data *p = &num[i] ;
			ans[p->x][i + 1] = p->num ; ud[p->x][i + 1] = 1 ;
		}
		for (int i = m ; i < tot ; ++i) {
			data *p = &num[i] ;
			for (; ud[p->x][nw[p->x]] ; ++nw[p->x]) ;
			ans[p->x][nw[p->x]] = p->num ; ud[p->x][nw[p->x]] = 1 ;
		}

		for (int i = 1 ; i <= n ; ++i , printf("\n"))
			for (int j = 1 ; j <= m ; ++j) printf("%d " , ans[i][j]) ;
	}

	return 0 ;
}