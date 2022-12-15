#include <bits/stdc++.h>

const int MAX_N = 1e4 + 10 ;

struct data {int x , y ;}ans[MAX_N] ;

bool ap[MAX_N] ;
int n , k , a[MAX_N] , pl[MAX_N] , pre[MAX_N] , cnt[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= n * k ; ++i) {
		scanf("%d" , &a[i]) ;
		pre[i] = pl[a[i]] ; pl[a[i]] = i ;
	}

	///

	int inf = (n + (k - 2)) / (k - 1) ;
	for (int i = 1 ; i <= n * k ; ++i)
		if (pre[i] && !ap[a[i]]) {
			int x = pre[i] , y = i , res = cnt[x] ;
			for (int j = x ; j <= y ; ++j) res = std::max(res , cnt[j]) ;

			if (res >= inf) continue ;

			ans[a[i]] = (data){x , y} ;
			for (int j = x ; j <= y ; ++j) ++cnt[j] ;

			ap[a[i]] = 1 ;
		}

	for (int i = 1 ; i <= n ; ++i) printf("%d %d\n" , ans[i].x , ans[i].y) ;

	return 0 ;
}