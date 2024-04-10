/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> es;
	forn(i, m) {
		int id, l, r;
		cin >> id >> l >> r, id--;
		es.push_back({l, 0, id});
		es.push_back({r, 1, id});
	}
	sort(all(es));
	
	vector<vector<int>> g(n);
	auto add_edge = [&](int a, int b) {
		if (a > b) swap(a, b);
		if (a != b && 0 <= a && b < n) g[a].push_back(b);
	};

	multiset<int> rows = {-1, n};
	for (auto [x, type, row] : es) {
		auto add = [&]() {
			auto it = rows.lower_bound(row);
			add_edge(row, *it);
			add_edge(row, *--it);
		};
		if (type == 0)
			add(), rows.insert(row);
		else
			rows.erase(rows.find(row)), add();
	};

	vector<pair<int, int>> dp(n, {1, -1});
	forn(i, n)
		for (int j : g[i])
			dp[j] = max(dp[j], {dp[i].first + 1, i});

	auto ma = max_element(all(dp));
	vector<int> was(n);
	for (int row = ma - dp.begin(); row != -1; row = dp[row].second)
		was[row] = 1;

	cout << n - ma->first << "\n";
	forn(row, n)
		if (!was[row])
			cout << row + 1 << " ";
}