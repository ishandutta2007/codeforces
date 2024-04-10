/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int u[N], v[N], p[N];
bool ans[N];
vector <int> g[N];
bool vis[N];

void dfs(int x) {
	vis[x] = true;
	for (auto y : g[x]) {
		if (vis[y])
			continue;
		ans[y] = !ans[x];
		dfs(y);
	}
}

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
		g[i].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> u[i] >> v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	ans[1] = 0;
	set <int> ok;
	vector <int> v, w;
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (ans[i]) 
			v.push_back(i);
		else
			w.push_back(i);
	}
	if (v.size() > w.size())
		swap(v, w);
	int kk = v.size();
	int i = 0;
	while (kk) {
		if (kk % 2)
			ok.insert(i);
		kk /= 2;
		i++;
	}
	for (int i = 1; i <= n; i++) {
		kk = i;
		int j = 0;
		while (kk) {
			kk /= 2;
			j++;
		}
		if (ok.count(j - 1)) {
			p[v.back() - 1] = i;
			v.pop_back();
		} else {
			p[w.back() - 1] = i;
			w.pop_back();
		}
	}
	for (int i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}