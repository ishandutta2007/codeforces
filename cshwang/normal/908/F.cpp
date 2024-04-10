#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 , INF = 0x7FFFFFFF ;

struct data {
	int pl , col ;
}pt[MAX_N] ;

ll ans ;
int n , cnt , gre[MAX_N] , tot[2] , tmp[2][MAX_N] ;

int trans(char c) {
	if (c == 'R') return 0 ;
	else if (c == 'B') return 1 ;
	else return 2 ;
}

void add(int x , int y , int ty) {
	tot[ty] = 0 ;
	for (int i = x ; i <= y ; ++i)
		if (pt[i].col == ty) tmp[ty][++tot[ty]] = pt[i].pl ;
}

void work(int x , int y , int L , int R) {
	add(x , y , 0) ; add(x , y , 1) ;

	ll s1 = 0 , s2 = INF ;
	if (L != INF && R != INF) {
		s1 += R - L ;
		if (tot[0] && tot[1]) s2 = ((ll)R - L) << 1 ;
	}

	for (int i = 0 ; i < 2 ; ++i) {
		if (!tot[i]) continue ;

		ll mc = -1 ;
		for (int j = 0 ; j <= tot[i] ; ++j) {
			ll cost , c1 = abs(tmp[i][j] - L) , c2 = abs(tmp[i][j + 1] - R) ;

			if (!j) cost = c2 ;
			else if (j == tot[i]) cost = c1 ;
			else cost = c1 + c2 ;

			if (mc == -1) mc = cost ;
			else mc = std::min(mc , cost) ;
		}

		s1 += mc ;
	}

	ans += std::min(s1 , s2) ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		int p , t ; char c ;
		scanf("%d %c" , &p , &c) ;

		pt[i] = (data){p , trans(c)} ;
		if (c == 'G') gre[++cnt] = i ;
	}

	///

	ans = 0 ;
	if (!cnt) {
		add(1 , n , 0) ; add(1 , n , 1) ;
		for (int i = 0 ; i < 2 ; ++i) if (tot[i]) ans += tmp[i][tot[i]] - tmp[i][1] ;
	}
	else {
		work(1 , gre[1] , INF , pt[gre[1]].pl) ;
		work(gre[cnt] , n , pt[gre[cnt]].pl , INF) ;
		for (int i = 1 ; i < cnt ; ++i) work(gre[i] , gre[i + 1] , pt[gre[i]].pl , pt[gre[i + 1]].pl) ;
	}

	printf("%lld\n" , ans) ;

	return 0 ;
}