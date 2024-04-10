#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> children(n + 1);
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		children[p].push_back(i);
	}
	children[0].push_back(1);
	vector<int> order;
	for (int i = 0; i <= n; ++i) {
		if(children[i].size())
			order.push_back(i);
	}
	sort(order.begin(), order.end(), [&](int i, int j) -> bool {
		return children[i].size() < children[j].size();
	});
	set<pair<int, int>> pq;
	int steps = 0;
	while (!pq.empty() || !order.empty()) {
		++steps;
		if (order.empty()) {
			pq.erase(*pq.rbegin());
		} else {
			int look = order.back();
			order.pop_back();
			for (int i = 1; i < children[look].size(); ++i) {
				pq.emplace(i + steps, children[look][i]);
			}
		}
		// pull from pq
		while(!pq.empty() && pq.begin()->first == steps) {
			pq.erase(pq.begin());
		}
	}
	cout << steps << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}