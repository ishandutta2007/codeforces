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
	int n; cin >> n;
	vector<pair<int, int>> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i].first;
		d[i].second = i;
	}
	vector<pair<int, int>> ans;
	function<void(vector<pair<int, int>> &)> solve = [&](vector<pair<int, int>> &deg) {
		sort(deg.begin(), deg.end());
		int n = deg.size();
		if (!n) {
			return;
		}
		if (n == 1) {
			if (deg[0].first != 0) {
				cout << "-1\n";
				exit(0);
			}
			return;
		}
		int sum = 0;
		for (auto t : deg) {
			sum += t.first;
		}
		if (sum < 2 * (n - 1)) {
			cout << "-1\n";
			exit(0);
		}
		if (sum & 1) {
			cout << "-1\n";
			exit(0);
		}
		if (sum > ((n - 1) + (n - 1) / 2) * 2) {
			cout << "-1\n";
			exit(0);
		}
		if (deg[0].first == 1) {
			int pos = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (deg[i].first > 1 && deg[i].first % 2 == 1) {
					pos = i;
					break;
				}
			}
			ans.emplace_back(deg[0].second, deg[pos].second);
			deg[0].first--;
			deg[pos].first--;
			vector<pair<int, int>> ndeg;
			for (int i = 0; i < n; i++) {
				if (deg[i].first) {
					ndeg.push_back(deg[i]);
				}
			}
			solve(ndeg);
			return;
		} else {
			int odd = 0;
			for (auto t : deg) {
				if (t.first % 2 == 1) {
					odd++;
				}
			}
			if (sum > ((n - 1) + (n - 1 - odd / 2) / 2) * 2) {
				cout << "-1\n";
				exit(0);
			}
			if (deg[n - 1].first == 2) {
				for (int i = 0; i < n; i++) {
					ans.emplace_back(deg[i].second, deg[(i + 1) % n].second);
				}
				return;
			}
			assert(deg[1].first == 2);
			int u = deg[0].second;
			int v = deg[1].second;
			int w = deg[n - 1].second;
			ans.emplace_back(u, v);
			ans.emplace_back(u, w);
			ans.emplace_back(v, w);
			deg[n - 1].first -= 2;
			deg[0].first = deg[1].first = 0;
			vector<pair<int, int>> ndeg;
			for (int i = 0; i < n; i++) {
				if (deg[i].first) {
					ndeg.push_back(deg[i]);
				}
			}
			solve(ndeg);
		}
	};
	solve(d);
	cout << ans.size() << '\n';
	for (auto t : ans) {
		cout << 2 << ' ' << t.first + 1 << ' ' << t.second + 1 << '\n';
	}
	return 0;
}