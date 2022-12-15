#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 , INF = 0x3f3f3f3f ;

struct data {
	int num ;
	data *left , *right ;
}a[MAX_N] ;

std::map<int , bool> ok ;

int n ;
bool fa[MAX_N] ;

void dfs(data *p , int L , int R) {
	if (!p) return ;
	if (L <= p->num && p->num <= R) ok[p->num] = 1 ;

	dfs(p->left , L , std::min(R , p->num)) ;
	dfs(p->right , std::max(L , p->num) , R) ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		int t , l , r ; scanf("%d %d %d" , &t , &l , &r) ;

		a[i].num = t ;
		if (l > 0) fa[l] = 1 , a[i].left = &a[l] ;
		if (r > 0) fa[r] = 1 , a[i].right = &a[r] ;
	}

	///

	for (int i = 1 ; i <= n ; ++i)
		if (!fa[i]) dfs(&a[i] , -INF , INF) ;

	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) if (!ok[a[i].num]) ++ans ;
	printf("%d\n" , ans) ;

	return 0 ;
}