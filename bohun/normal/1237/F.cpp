#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int nax = 3601;
const int mod = 998244353;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = (ll) c * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return c;
}

int h, w, n;
int row[nax], col[nax];
int a, b, c, d;
int fac[nax];
int odw[nax];
int dp[nax][nax][2];

int Newton(int x, int y) {
	if(x < y || x < 0)
		return 0;
	int res = fac[x];
	res = (ll) res * odw[y] % mod;
	res = (ll) res * odw[x - y] % mod;
	return res;
}

int main() {
	fac[0] = odw[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = (ll) fac[i - 1] * i % mod;
		odw[i] = pt(fac[i], mod - 2);
	}	
	scanf("%d %d %d", &h, &w, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		row[a] = row[c] = 1;
		col[b] = col[d] = 1;
	}
	int Row = 0;
	int Col = 0;
	for(int i = 1; i <= h; ++i)
		Row += !row[i];
	for(int i = 1; i <= w; ++i)
		Col += !col[i];
	dp[0][0][0] = dp[0][0][1] = 1;
	row[0] = col[0] = 1;
	for(int i = 1; i <= h; ++i)
		for(int j = 0; j <= h; ++j) {
			dp[i][j][0] = dp[i - 1][j][0];
			if(j > 0 && !row[i] && !row[i - 1])
				dp[i][j][0] = (dp[i][j][0] + dp[i - 2][j - 1][0]) % mod;
		}
	for(int i = 1; i <= w; ++i) 
		for(int j = 0; j <= w; ++j) {
			dp[i][j][1] = dp[i - 1][j][1];
			if(j > 0 && !col[i] && !col[i - 1])
				dp[i][j][1] = (dp[i][j][1] + dp[i - 2][j - 1][1]) % mod;
		}
	ll ans = 0;
	for(int i = 0; i <= h; ++i)
		for(int j = 0; j <= w; ++j) {
			ll dodaj = 1;
			dodaj = (ll) dodaj * fac[i] % mod;
			dodaj = (ll) dodaj * fac[j] % mod;
			dodaj = (ll) dodaj * Newton(Col - 2 * i, j) % mod;
			dodaj = (ll) dodaj * Newton(Row - 2 * j, i) % mod;
			dodaj = (ll) dodaj * dp[h][j][0] % mod;
			dodaj = (ll) dodaj * dp[w][i][1] % mod;
			ans += dodaj;
			ans %= mod;
		}
	printf("%lld\n", ans);
	
	
	
	
	return 0;
}