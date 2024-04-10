#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
 
#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;
 
const int MAX_N = 2e5 + 10 ;
 
std::vector<int> eg[MAX_N] ;
 
ll f[MAX_N] , g[MAX_N] ;
int n , a[MAX_N] , son[MAX_N] ;
 
void work(int x) {
	int m = eg[x].size() ;
	ll s = 0 , mf = 0 ;
	if (!m) {f[x] = a[x] ; g[x] = 0 ; son[x] = 1 ; return ;}
 
	son[x] = 0 ;
	for (int i = 0 ; i < m ; ++i) {
		int nx = eg[x][i] ;
		work(nx) ;
		son[x] += son[nx] ; mf = std::max(mf , f[nx]) ;
	}
	for (int i = 0 ; i < m ; ++i) {
		int nx = eg[x][i] ;
		s += g[nx] ; s += son[nx] * (mf - f[nx]) ;
	}
 
	///
 
	int tot = son[x] ;
	ll lef = a[x] - s ;
	if (lef <= 0) {f[x] = mf ; g[x] = -lef ;}
	else {
		ll ad = lef / tot ;
		if (lef % tot) {++ad ; g[x] = tot - lef % tot ;}
		else g[x] = 0 ;
		f[x] = mf + ad ;
	}
}
 
int main() {
	scanf("%d" , &n) ;
	for (int i = 2 ; i <= n ; ++i) {
		int t ; scanf("%d" , &t) ;
		eg[t].push_back(i) ;
	}
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
 
	///
 
	work(1) ;
	printf("%lld\n" , f[1]) ;
 
	return 0 ;
}