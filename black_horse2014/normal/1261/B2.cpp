#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> v, a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.emplace_back(-x, i);
	}
	a = v;
	sort(v.begin(), v.end());
	int m; cin >> m;
	vector<int> Q;
	vector<vector<int>> q(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		q[x].push_back(i);
		Q.push_back(y);
	}
	vector<int> ans(m);
	for (int i = 1; i <= n; i++) {
		s.insert(v[i - 1].second);
		for (int u : q[i]) {
			ans[u] = -a[*s.find_by_order(Q[u] - 1)].first;
		}
	}
	for (int i = 0; i < m; i++) cout << ans[i] << "\n";
	return 0;
}