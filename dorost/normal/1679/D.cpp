/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
vector <int> g[N];
int d[N];
int u[N], v[N], a[N], dp[N], n, m;
ll k;

bool is_valid(int x) {
	for (int i = 0; i < N; i++) {
		g[i].clear();
		d[i] = 0;
		dp[i] = 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x)
			cnt++;
	}
	for (int i = 0; i < m; i++) {
		if (a[u[i]] <= x && a[v[i]] <= x) {
			g[u[i]].push_back(v[i]);
			d[v[i]]++;
		}
	}
	vector <int> topol;
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (a[i] > x)
			continue;
		if (d[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		topol.push_back(x);
		for (int y : g[x]) {
			d[y]--;
			if (d[y] == 0)
				q.push(y);
		}
	}
	if (topol.size() < cnt) {
		return true;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		dp[topol[i]] = 1;
		for (int j : g[topol[i]]) {
			dp[topol[i]] = max(dp[topol[i]], dp[j] + 1);
		}
		if (dp[topol[i]] >= k)
			return true;
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int l = 0, r = 1012345678;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> u[i] >> v[i];
	if (!is_valid(r)) {
		cout << -1 << '\n';
		return 0;
	}
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';
}