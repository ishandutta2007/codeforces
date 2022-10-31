#include <bits/stdc++.h>

#ifdef LOCAL
#include "E:\\Competitive-Programming\\Template\\Standard Template Codes\\debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a, b; cin >> n >> m >> a >> b;
	if (a >= m || b >= n) {
		return cout << "No\n", 0;
	}
	vector<int> x(a), y(b);
	for (int i = 0; i < a; i++) {
		cin >> x[i];
		x[i]--;
	}
	for (int i = 0; i < b; i++) {
		cin >> y[i];
		y[i]--;
	}
	vector<int> deg(n + m);
	set<int> A, B;
	for (int i = 0; i < m - 1 - a; i++) {
		x.push_back(0);
	}
	for (int i = 0; i < n - 1 - b; i++) {
		y.push_back(n);
	}
	for (int i = 0; i < m - 1; i++) {
		deg[x[i]]++;
	}
	for (int i = 0; i < n - 1; i++) {
		deg[y[i]]++;
	}
	set<pair<int, int>> S;
	for (int i = 0; i < n + m; i++) {
		S.emplace(deg[i], i);
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	vector<pair<int, int>> ans;
	for (int i = 0; i < n + m - 2; i++) {
		auto t = *S.begin();
		S.erase(S.begin());
		int u = t.second;
		assert(t.first == 0);
		if (u < n) {
			int v = y.back(); y.pop_back();
			S.erase({deg[v], v});
			ans.emplace_back(u, v);
			deg[v]--;
			S.emplace(deg[v], v);
		} else {
			int v = x.back(); x.pop_back();
			S.erase({deg[v], v});
			ans.emplace_back(u, v);
			deg[v]--;
			S.emplace(deg[v], v);
		}
	}
	int u = S.begin()->second;
	int v = (--S.end())->second;
	ans.emplace_back(u, v);
	cout << "Yes\n";
	for (auto t : ans) {
		cout << t.first + 1 << ' ' << t.second + 1 << '\n';
	}
	return 0;
}