/* 	* In the name of GOD  */

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 401234;
vector <int> adj[N];
int h[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	vector <int> v, v2;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() <= 1) {
			v2.push_back(i);
		}
		h[i] = adj[i].size();
	}
	set <int> hazf;
	for (int i = 0; i < k; i++) {
		sort(v2.begin(), v2.end());
		v2.erase(unique(v2.begin(), v2.end()), v2.end());
		v = v2;
		if (!v.size()) {
		    break;
		}
		for (auto x : v) {
			hazf.insert(x);
			for (auto y : adj[x]) {
				h[y]--;
			}
		}
		v2.clear();
		for (int i = 0; i < v.size(); i++) {
			for (auto x : adj[v[i]]) {
				if (!hazf.count(x) && h[x] <= 1)
					v2.push_back(x);
			}
		}
	}
	cout << n - hazf.size() << ' ';
	for (int i = 0; i < n; i++)
		adj[i].clear();
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}