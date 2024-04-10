/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234, K = 41, M = 998244353;
int ps[K][N], fac[N];
int t[N], a[N], l[N], r[N], u[K], v[K];
bool f[N];

int tav(int x, int n) {
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

int C(int k, int n) {
	if (k > n || k < 0)
		return 0;
	ll ans = fac[n];
	ans *= inv(fac[k]);
	ans %= M;
	ans *= inv(fac[n - k]);
	ans %= M;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = (fac[i - 1] * i) % M;
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		t[l[i]]++;
		t[r[i] + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + t[i];
	}
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= n; j++) {
			ps[i][j] = (ps[i][j - 1] + C(j - i, a[j] - i)) % M;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
	}
	int ans = 0, cnt = 0;
	for (int i = 0; i < (1 << m); i++) {
		set <int> st;
		int L = 1, R = n;
		cnt = 0;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				st.insert(u[j]);
				st.insert(v[j]);
				if (!f[u[j]])
					cnt++;
				f[u[j]] = true;
				if (!f[v[j]])
					cnt++;
				f[v[j]] = true;
				L = max(L, l[u[j] - 1]);
				R = min(R, r[u[j] - 1]);
				L = max(L, l[v[j] - 1]);
				R = min(R, r[v[j] - 1]);
			}
		}
		for (int j = 0; j < m; j++) {
			f[v[j]] = false;
			f[u[j]] = false;
		}
		if (R < L)
			continue;
		int k = (int)st.size();
		ans += (__builtin_popcount(i) & 1 ? -1 : 1) * (ps[k][R] - ps[k][L - 1]);
		ans %= M;
		ans += M;
		ans %= M;
	}
	cout << ans;
}