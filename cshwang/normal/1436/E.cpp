#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 , lgN = 20 + 5 , INF = 0x3f3f3f3f ;

struct Chair {
	int num ;
	Chair *left , *right ;

	void init() {
		int num = 0 ;
		left = right = NULL ;
	}
	void update() {
		num = INF ;
		if (left) num = std::min(left->num , num) ;
		if (right) num = std::min(right->num , num) ;
		if (num == INF) num = 0 ;
	}
}tree[MAX_N * lgN] ;

std::vector<int> pl[MAX_N] ;

Chair *root[MAX_N] ;
int n , cur , maxa , a[MAX_N] ;

void build(Chair *&rt , int x , int y) {
	rt = &tree[cur++] ; rt->init() ;
	if (x == y) return ;

	int mid = (x + y) >> 1 ;
	build(rt->left , x , mid) ;
	build(rt->right , mid + 1 , y) ;
}

void change(Chair *ort , Chair *&rt , int x , int y , int f , int a) {
	rt = &tree[cur++] ;
	*rt = *ort ;

	if (x == f && y == f) {
		rt->num = a ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	if (mid < f) change(ort->right , rt->right , mid + 1 , y , f , a) ;
	else change(ort->left , rt->left , x , mid , f , a) ;

	rt->update() ;
}

int getans(Chair *rt , int x , int y , int f) {
	if (x == y) return x ;

	int mid = (x + y) >> 1 ;
	if (rt->left->num >= f) return getans(rt->right , mid + 1 , y , f) ;
	else return getans(rt->left , x , mid , f) ;
}

inline int work(int x , int y) {
	if (x > y) return 0 ;
	return getans(root[y] , 1 , maxa , x) ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%d" , &a[i]) ; maxa = std::max(maxa , a[i]) ;
		pl[a[i]].push_back(i) ;
	}
	++maxa ;

	///

	build(root[0] , 1 , maxa) ;
	for (int i = 1 ; i <= n ; ++i) change(root[i - 1] , root[i] , 1 , maxa , a[i] , i) ;

	///
	
	int ans = 0 ;
	for (int i = 1 ; i <= n + 2 ; ++i) {
		int m = pl[i].size() ;
		if (!m) {
			if (work(1 , n) == i) continue ;
			ans = i ; break ;
		}

		bool ok = 1 ;
		if (work(1 , pl[i][0] - 1) == i) ok = 0 ;
		if (work(pl[i][m - 1] + 1 , n) == i) ok = 0 ;
		for (int j = 0 ; j < m - 1 && ok ; ++j) {
			int l = pl[i][j] , r = pl[i][j + 1] ;
			if (work(l + 1 , r - 1) == i) ok = 0 ;
		}

		if (ok) {ans = i ; break ;}
	}

	printf("%d\n" , ans) ;

	return 0 ;
}