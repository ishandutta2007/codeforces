/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ps[N];
vector <int> g[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n + 10; i++)
		g[i].clear(), ps[i] = 0, a[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x - a[i];
	}
	ps[0] = 0;
	for (int i = 0; i < n; i++)
		ps[i + 1] = ps[i] + a[i];
	queue <pair <int, int>> yal;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		if (ps[l] == ps[r] && ps[l] == 0)
			yal.push({l, r});
		g[l].push_back(r);
		g[r].push_back(l);
	}
	if (ps[n] != 0) {
		cout << "NO\n";
		return;
	}
	set <int> one, zero;
	for (int i = 0; i <= n; i++) {
		if (ps[i] == 0)
			zero.insert(i);
		else
			one.insert(i);
	}
	while (!yal.empty() && !one.empty()) {
		pair <int, int> p = (yal.front());
		yal.pop();
		int l = p.F;
		int r = p.S;
		auto x = one.lower_bound(l);
		auto y = one.lower_bound(r);
		vector <int> v;
		for (auto i = x; i != y; i++) {
			int w = (*i);
			assert(w > l && w < r); 
			v.push_back(w);
			zero.insert(w);
			for (int y : g[w]) {
				if (zero.count(y)) {
					yal.push(minmax(w, y));
				}
			}
		}
		for (int i : v)
			one.erase(i);
	}
	cout << (one.empty() ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}