#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 35e3 + 10 , INF = 0x3f3f3f3f ;

std::deque<int> que[MAX_N] ;

int n , k , p , res , L , R , a[MAX_N] , f[2][MAX_N] ;

inline int cal(int x) {return que[x].back() - que[x].front() ;}

void add_f(int x , int p) {
	if (que[x].size()) res -= cal(x) ;
	que[x].push_front(p) ; res += cal(x) ;
}

void add_b(int x , int p) {
	if (que[x].size()) res -= cal(x) ;
	que[x].push_back(p) ; res += cal(x) ;
}

void del_f(int x) {
	res -= cal(x) ; que[x].pop_front() ;
	if (que[x].size()) res += cal(x) ;
}

void del_b(int x) {
	res -= cal(x) ; que[x].pop_back() ;
	if (que[x].size()) res += cal(x) ;
}

void modify(int x , int y) {
	for (; x < L ;) {--L ; add_f(a[L] , L) ;}
	for (; R < y ;) {++R ; add_b(a[R] , R) ;}
	for (; L < x ;) {del_f(a[L]) ; ++L ;}
	for (; y < R ;) {del_b(a[R]) ; --R ;}
}

void work(int x , int y , int px , int py) {
	if (x > y) return ;

	int mid = (x + y) >> 1 , pt = mid , nw = INF , ed = std::min(py , mid) ;

	for (int i = px ; i <= ed ; ++i) {
		modify(i , mid) ;
		int tmp = res + f[p^1][i - 1] ;
		if (tmp < nw) {nw = tmp ; pt = i ;}
	}

	f[p][mid] = nw ;
	work(x , mid - 1 , px , pt) ; work(mid + 1 , y , pt , py) ;
}

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	res = 0 ; L = 1 ; R = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		modify(1 , i) ; f[0][i] = res ;
	}

	///

	p = 1 ;
	for (int i = 2 ; i <= k ; ++i , p ^= 1)
		work(i , n , i , n) ;

	printf("%d\n" , f[p^1][n]) ;

	return 0 ;
}