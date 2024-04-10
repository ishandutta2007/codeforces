#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 14 + 5 , MAX_S = (1 << 14) + 10 , mod = 1e9 + 7 ;

std::vector<int> lst[MAX_S] ;

int n , a[MAX_N] , cnt[MAX_S] , f[MAX_S] , g[MAX_N][MAX_S] , rg[MAX_S][MAX_N] , h[MAX_S] , pl[MAX_S] ;

inline int lowbit(int x) {return x & (-x) ;}

int qpow(int a , int t) {
	int s = 1 ;
	for (; t ; a = (ll)a * a % mod , t >>= 1)
		if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

int beats(int x , int y) {
	int fm = a[x] + a[y] ;

	return (ll)qpow(fm , mod - 2) * a[x] % mod ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 0 ; i < n ; ++i) pl[1 << i] = i ;

	///

	int tS = (1 << n) - 1 ;
	for (int i = 0 ; i < n ; ++i)
		for (int S = 0 ; S <= tS ; ++S) {
			if ((1 << i) & S) continue ;

			g[i][S] = rg[S][i] = 1 ;
			for (int j = 0 ; j < n ; ++j)
				if ((1 << j) & S) {
					g[i][S] = (ll)g[i][S] * beats(i , j) % mod ;
					rg[S][i] = (ll)rg[S][i] * beats(j , i) % mod ;
				}
			rg[S][i] = qpow(rg[S][i] , mod - 2) ;
		}

	f[0] = 1 ;
	for (int S = 1 ; S <= tS ; ++S) {
		for (int nS = S ; nS ; nS = (nS - 1) & S) lst[S].push_back(nS) ;
		std::reverse(lst[S].begin() , lst[S].end()) ;
	}

	cnt[0] = 0 ;
	for (int S = 1 ; S <= tS ; ++S) cnt[S] = cnt[S - lowbit(S)] + 1 ;

	///

	f[0] = 0 ;
	for (int S = 1 ; S <= tS ; ++S) {
		f[S] = 0 ; h[0] = 1 ;
		for (auto &nS : lst[S]) {
			int pre = nS - lowbit(nS) , p = pl[lowbit(nS)] , lef = S - nS ;
			h[nS] = (ll)h[pre] * rg[pre][p] % mod * g[p][lef] % mod ;

			if (nS < S) f[S] = (f[S] + (ll)f[nS] % mod * h[nS] % mod) % mod ;
		}

		f[S] = (1 - f[S] + mod) % mod ;
	}

	int res = 0 ;
	for (int S = 1 ; S <= tS ; ++S)
		res = (res + (ll)f[S] % mod * h[S] % mod * cnt[S] % mod) % mod ;
	printf("%d\n" , res) ;

	return 0 ;
}