#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e16 ;
const int MAX_N = 1e5 + 10 ;

ll f[2][MAX_N] , ans ;
int n , p , k , L , R , a[MAX_N] , cnt[MAX_N] ;

void add(int t , int ad) {
	ans -= ((ll)cnt[t] * (cnt[t] - 1)) >> 1 ;
	cnt[t] += ad ;
	ans += ((ll)cnt[t] * (cnt[t] - 1)) >> 1 ;
}

void modify(int nx , int ny) {
	for (; nx < L ;) add(a[--L] , 1) ;
	for (; R < ny ;) add(a[++R] , 1) ;
	for (; L < nx ;) add(a[L++] , -1) ;
	for (; ny < R ;) add(a[R--] , -1) ;
}

void work(int px , int py , int x , int y) {
	if (x > y) return ;

	int mid = (x + y) >> 1 ;
	ll res = INF , pl = -1 ;

	for (int i = px ; i <= py ; ++i) {
		if (i > mid) break ;

		modify(i , mid) ;
		ll tmp = f[p^1][i - 1] + ans ;
		if (tmp < res) res = tmp , pl = i ;
	}
	f[p][mid] = res ;

	work(px , pl , x , mid - 1) ; work(pl , py , mid + 1 , y) ;
}

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	f[0][0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) f[0][i] = INF ;

	p = 1 ; L = 1 ; R = 0 ;
	for (int j = 1 ; j <= k ; ++j , p ^= 1)
		work(1 , n , 1 , n) ;

	printf("%lld\n" , f[p^1][n]) ;

	return 0 ;
}