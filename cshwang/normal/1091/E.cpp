#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e5 + 10 ;

struct data {
	ll sum ; int cnt ;

	friend data operator +(data x , data y) {return (data){x.sum + y.sum , x.cnt + y.cnt} ;}
}tre[MAX_N << 2] ;

int n , a[MAX_N] ;
bool ans[MAX_N] , ovr[MAX_N] ;
ll sum[MAX_N] , f[MAX_N] , g[MAX_N] , ftre[MAX_N << 2] ;

///

data find(int t , int x , int y , int fx , int fy) {
	if (y < fx || fy < x) return (data){0 , 0} ;
	if (fx <= x && y <= fy) return tre[t] ;

	int mid = (x + y) >> 1 ;
	data s1 = find(t << 1 , x , mid , fx , fy) ,
		 s2 = find(t << 1 | 1 , mid + 1 , y , fx , fy) ;

	return s1 + s2 ;
}

void modify(int t , int x , int y , int f) {
	if (y < f || f < x) return ;
	if (x == f && y == f) {
		tre[t].sum += f ; ++tre[t].cnt ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	modify(t << 1 , x , mid , f) ; modify(t << 1 | 1 , mid + 1 , y , f) ;

	tre[t] = tre[t << 1] + tre[t << 1 | 1] ;
}

///

void add(int t , int x , int y , int f , ll a) {
	if (f < x || y < f) return ;
	if (x == f && y == f) {
		ftre[t] = a ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	add(t << 1 , x , mid , f , a) ; add(t << 1 | 1 , mid + 1 , y , f , a) ;

	ftre[t] = std::min(ftre[t << 1] , ftre[t << 1 | 1]) ;
}

ll query(int t , int x , int y , int fx , int fy) {
	if (y < fx || fy < x) return 0 ;
	if (fx <= x && y <= fy) return ftre[t] ;

	int mid = (x + y) >> 1 ;
	ll s1 = query(t << 1 , x , mid , fx , fy) ,
	   s2 = query(t << 1 | 1 , mid + 1 , y , fx , fy) ;

	return std::min(s1 , s2) ;
}

///

bool cmp(int x , int y) {return x > y ;}

bool check(int pl , int x) {
	if (pl) {
		if (f[pl] - x < 0) return 0 ;
	}
	else {
		ll t = f[1] - 2 ;
		t += a[1] + std::min(1 , a[1]) ;

		if (t - x < 0) return 0 ;
	}

	if (pl < x) return ovr[pl] ;

	ll tmp = query(1 , 0 , n , x , pl) ; bool sta = x ? ovr[x - 1] : 1 ;
	return (tmp + x >= 0) && sta ;
}

///

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	std::sort(a + 1 , a + 1 + n , cmp) ;

	///
	
	sum[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) sum[i] = sum[i - 1] + a[i] ;

	for (int i = n ; i ; --i) {
		data tmp = find(1 , 0 , n , 0 , i + 1) ;

		f[i] = tmp.sum + (ll)(n - i - tmp.cnt) * (i + 1) ;
		f[i] += (ll)i * (i + 1) ; f[i] -= sum[i] ;

		tmp = find(1 , 0 , n , 0 , i) ;
		g[i] = tmp.sum + (ll)(n - i - tmp.cnt) * i ;
		g[i] += (ll)i * (i - 1) ; g[i] -= sum[i] ;

		modify(1 , 0 , n , a[i]) ; add(1 , 0 , n , i , g[i]) ;
	}

	ovr[0] = 1 ;
	for (int i = 1 ; i <= n ; ++i) ovr[i] = ovr[i - 1] && (g[i] + i >= 0) ;

	///

	bool ok = 0 ; ll mf = n ;

	for (int i = 0 ; i <= a[n] ; ++i) {
		if ((sum[n] + i) & 1) continue ;
		if (check(n , i)) ok = 1 , ans[i] = 1 ;
	}

	for (int i = n ; i ; --i) {
		ll L = a[i] , R = i == 1 ? n : a[i - 1] ;
		mf = std::min(mf , f[i]) ; R = std::min(mf , R) ;

		for (int j = L ; j <= R ; ++j) {
			if ((sum[n] + j) & 1) continue ;
			if (check(i - 1 , j)) ok = 1 , ans[j] = 1 ;
		}
	}

	if (!ok) printf("-1") ;
	else for (int i = 0 ; i <= n ; ++i) if (ans[i]) printf("%d " , i) ;
	printf("\n") ;

	return 0 ;
}