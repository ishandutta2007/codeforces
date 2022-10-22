/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 1000 * 1000 * 1000 + 7;
vector <int> g[N], sz[N];
int s[N], fac[N], invf[N];

int tav(ll x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}

int C(int n, int k) {
	if (k > n)
		return 0;
	ll ans = fac[n];
	ans *= invf[k];
	ans %= M;
	ans *= invf[n - k];
	ans %= M;
	return ans;
}

int n, k;

void dfs(int v, int p = -1) {
	s[v] = 1;
	for (int u : g[v]) {
		if (u != p) {
			dfs(u, v);
			s[v] += s[u];
			sz[v].push_back(s[u]);
		}
	}
	if (v != 1) {
		sz[v].push_back(n - s[v]);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = ((ll)fac[i - 1] * i) % M;
	}
	invf[N - 1] = inv(fac[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		invf[i] = ((ll)invf[i + 1] * (i + 1)) % M;
	}
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0;
		for (int j : sz[i]) {
			x -= C(j, k);
			if (x < 0)
				x += M;
		}
		int few = x;
		few += C(n, k);
		if (few >= M)
			few -= M;
		few = ((ll)few * (ll)n) % M;
		ans += few;
		if (ans >= M)
			ans -= M;
		for (int j : sz[i]) {
			int wef = x;
			wef += C(j, k);
			if (wef >= M)
				wef -= M;
			wef += C(n - j, k);
			if (wef >= M)
				wef -= M;
			wef = ((ll)wef * (ll)(n - j)) % M;
			wef = ((ll)wef * (ll)(j)) % M;
			ans += wef;
			if (ans >= M)
				ans -= M;
		}
	}
	cout << ans << '\n';
}