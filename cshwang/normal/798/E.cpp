#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 5e5 + 10 ;

struct data {
	int idx , num ;
}tree[MAX_N << 2] ;

bool ap[MAX_N] ;
int n , ti , a[MAX_N] , b[MAX_N] , ans[MAX_N] ;

data cmp(data x , data y) {
	if (x.num > y.num) return x ;
	else return y ;
}

void build(int t , int x , int y) {
	if (x == y) {
		tree[t] = (data){x , b[x]} ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;

	tree[t] = cmp(tree[t << 1] , tree[t << 1 | 1]) ;
}

void update(int t , int x , int y , int f) {
	if (f < x || y < f) return ;
	if (x == f && y == f) {
		tree[t].num = 0 ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	update(t << 1 , x , mid , f) ; update(t << 1 | 1 , mid + 1 , y , f) ;

	tree[t] = cmp(tree[t << 1] , tree[t << 1 | 1]) ;
}

data find(int t , int x , int y , int fx , int fy) {
	if (fx <= x && y <= fy) return tree[t] ;
	if (y < fx || fy < x) return (data){-1 , 0} ;

	int mid = (x + y) >> 1 ;
	data s1 = find(t << 1 , x , mid , fx , fy) ,
		 s2 = find(t << 1 | 1 , mid + 1 , y , fx , fy) ;

	return cmp(s1 , s2) ;
}

void dfs(int x) {
	ap[x] = 1 ;
	update(1 , 1 , n , x) ;

	if (b[x] <= n && !ap[b[x]]) dfs(b[x]) ;
	if (a[x] == 1) {ans[x] = ++ti ; return ;}

	data d = find(1 , 1 , n , 1 , a[x] - 1) ;
	for (; d.num > x ; d = find(1 , 1 , n , 1 , a[x] - 1)) dfs(d.idx) ;

	ans[x] = ++ti ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 1 ; i <= n ; ++i) b[i] = n + 1 ;
	for (int i = 1 ; i <= n ; ++i)
		if (a[i] != -1) b[a[i]] = i ;
		else a[i] = n + 1 ;

	///

	build(1 , 1 , n) ;
	for (int i = 1 ; i <= n ; ++i)
		if (!ap[i]) dfs(i) ;

	for (int i = 1 ; i <= n ; ++i) printf("%d " , ans[i]) ;
	printf("\n") ;

	return 0 ;
}