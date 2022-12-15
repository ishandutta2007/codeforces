#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 50 + 5 , MAX_M = 1e5 + 10 , mod = 998244353 ;

bool ap[MAX_M] ;
int tl[MAX_M] , tr[MAX_M] , f[MAX_M] , g[MAX_M] ;
int n , m , tot , l[MAX_N] , r[MAX_N] , pri[MAX_M] , mu[MAX_M] ;

void init() {
	mu[1] = 1 ;
	for (int i = 2 ; i <= m ; ++i) {
		if (!ap[i]) {pri[tot++] = i ; mu[i] = mod - 1 ;}

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * pri[j] ;
			if (tmp > m) break ;
			ap[tmp] = 1 ;

			if (!(i % pri[j])) {mu[tmp] = 0 ; break ;}
			else mu[tmp] = mod - mu[i] ;
		}
	}
}

inline int cal(int x , int y) {
	if (!x) return g[y] ;
	else return g[y] - g[x - 1] ;
}

int work(int x) {
	int inf = m / x ;
	for (int i = 1 ; i <= n ; ++i) {
		tl[i] = (l[i] + x - 1) / x ; tr[i] = r[i] / x ;
		if (tl[i] > tr[i]) return 0 ;
	}

	int p = 0 ;
	for (int i = 0 ; i <= inf ; ++i) f[i] = 0 ;
	for (int i = tl[1] ; i <= tr[1] ; ++i) f[i] = 1 ;

	for (int i = 2 ; i <= n ; ++i) {
		g[0] = f[0] ;
		for (int j = 1 ; j <= inf ; ++j) g[j] = (f[j] + g[j - 1]) % mod ;

		for (int j = 0 ; j <= inf ; ++j) {
			int pl = j - tr[i] , pr = j - tl[i] ;

			if (pr < 0) {f[j] = 0 ; continue ;}
			
			pl = std::max(pl , 0) ; pr = std::max(pr , 0) ;
			f[j] = cal(pl , pr) ;
		}
	}

	int res = 0 ;
	for (int i = 1 ; i <= inf ; ++i) (res += f[i]) %= mod ;

	return res ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d %d" , &l[i] , &r[i]) ;

	///

	init() ; int res = 0 ;
	for (int i = 1 ; i <= m ; ++i)
		if (mu[i]) (res += (ll)mu[i] * work(i) % mod) %= mod ;
	printf("%d\n" , res) ;

	return 0 ;
}