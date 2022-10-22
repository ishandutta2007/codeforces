/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012, M = 31;
int a[N], n;
vector <int> g[N];
bool vis[N];

void dfs(int v) {
	vis[v] = true;
	for (auto u : g[v]) {
		if (!vis[u]) {
			dfs(u);
		}
	}
}

bool test() {
	for (int i = 0; i <= n; i++)
		g[i].clear(), vis[i] = false;
	int wef = 0;
	for (int j = 0; j < 30; j++) {
		vector <int> v;
		for (int i = 0; i < n; i++) {
			if ((a[i] >> j) & 1) {
				v.push_back(i);
			}
		}
		for (int i = 0; i < (int)v.size() - 1; i++) {
			g[v[i]].push_back(v[i + 1]);
			g[v[i + 1]].push_back(v[i]);
		}
	}
	dfs(0);
	bool f = true;
	for (int i = 0; i < n; i++) {
		f &= vis[i];
	}
	return f;
}

void solve() {
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			a[i] = 1;
			ans++;
		}
	}
	if (test()) {
		cout << ans << '\n';
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		a[i]--;
		if (a[i] != 0) {
			if (test()) {
				cout << ans + 1 << '\n';
				for (int i = 0; i < n; i++) {
					cout << a[i] << ' ';
				}
				cout << '\n';
				return;
			}
		}
		a[i] += 2;
		if (test()) {
			cout << ans + 1 << '\n';
			for (int i = 0; i < n; i++) {
				cout << a[i] << ' ';
			}
			cout << '\n';
			return;
		}
		a[i]--;
	}
	cout << ans + 2 << '\n';
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, __builtin_ctz(a[i]));
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (__builtin_ctz(a[i]) == mx) {
			if (cnt == 0) {
				a[i]--;
			} else if (cnt == 1) {
				a[i]++;
			} 
			cnt++;
		}
	}
	assert(test());
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--)
		solve();
}