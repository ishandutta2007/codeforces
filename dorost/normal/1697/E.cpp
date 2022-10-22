/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 205, M = 998244353;
vector <vector <int>> v;
int dp[N][N][N];
pair <int, int> d[N][N];
int fac[N];
int x[N], y[N], n;

int dis(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

bool ok(vector <int> wef) {
	int x = -1;
	for (int i = 0; i < (int)wef.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (wef[i] == wef[j])
				return false;
			if (x == -1) {
				x = dis(wef[i], wef[j]);
			} else {
				if (x != dis(wef[i], wef[j]))
					return false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		bool f = true;
		for (int j = 0; j < wef.size(); j++)
			if (wef[j] == i)
				f = false;
		if (!f)
			continue;
		for (int j = 0; j < (int)wef.size(); j++) {
			if (dis(i, wef[j]) <= x) {
				return false;
			}
		}
	}
	return true;
}

int tav(int x, int b) {
	ll ans = 1;
	while (b) {
		if (b & 1) 
			ans = (ans * x) % M;
		b >>= 1;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			d[i][j] = {-1, i};
		}
		for (int j = i + 1; j < n; j++) {
			d[i][j] = make_pair(abs(x[i] - x[j]) + abs(y[i] - y[j]), j);
		}
		sort(d[i], d[i] + n);
		vector <int> wef = {i};
		for (int j = i + 1; j < n; j++) {
			wef.push_back(d[i][j].S);
			if (ok(wef)) {
				v.push_back(wef);
			}
		}
	}
	if ((int)v.size() == 0) {
		cout << fac[n] << '\n';
		return 0;
	}
	for (int i = 0; i <= (int)v.size(); i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < (int)v.size(); k++) {
				if (j == 0 && i == 0) {
					dp[i][j][k] = 1;
				} else if (i == 0 || j == 0) {
					dp[i][j][k] = 0;
				} else {
					if (k != 0)
						dp[i][j][k] = dp[i][j][k - 1];
					int x = (int)v[k].size();
					if (k == 0) {
						if (i == 1 && j == x) {
							dp[i][j][k] = 1;
						} else {
							dp[i][j][k] = 0;
						}
					} else {
						if (i >= 1 && j >= x)
							dp[i][j][k] += dp[i - 1][j - x][k - 1];
					}
				}
				dp[i][j][k] %= M;
			}
		}
	}
	int ans = 0;
	for (int a = 0; a <= (int)v.size(); a++) {
		for (int b = a; b <= n; b++) {
			int wef = dp[a][b][(int)v.size() - 1];
			int cnt = n - b + a;
			wef *= C(n, cnt);
			wef %= M;
			wef *= fac[cnt];
			wef %= M;
			ans += wef;
			ans %= M;
		}
	}
	cout << ans << '\n';
}