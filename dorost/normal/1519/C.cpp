/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int u[N], s[N], c[N], sum[N];
vector <int> v[N];

bool cmp(vector <int> a, vector <int> b) {
	return a.size() < b.size();
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		c[i] = 0;
		sum[i] = 0;
		v[i].clear();
	}
	for (int i = 0; i < n; i++) {
		cin >> u[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		v[u[i]].push_back(s[i]);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
		for (int j = 1; j < v[i].size(); j++) {
			v[i][j] += v[i][j - 1];
		}
	}
	sort(v, v + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 0)
			continue;
		c[v[i].size()]++;
	}
	for (int i = n - 1; i >= 1; i--) {
		c[i] += c[i + 1];
	}
	int ans = 0;
	reverse(v, v + n + 1);
	for (int i = 1; i <= n; i++) {
		ans = 0;
		for (int j = 0; j < c[i]; j++) {
			int x = v[j].size();
			x = x / i * i;
			ans += v[j][x - 1];
		}
		cout << ans << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}