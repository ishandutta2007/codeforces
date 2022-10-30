#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		vector<pair<pair<int, int>, int>> ans;
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
		}
		if (sum % n) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = n; i >= 2; i--) {
			if (a[1] >= (i - a[i] % i) % i) {
				int tmp = (i - a[i] % i) % i;
				if (tmp) {
					ans.push_back(make_pair(make_pair(1, i), tmp));
				}
				a[i] += tmp;
				assert(a[i] % i == 0);
				ans.push_back(make_pair(make_pair(i, 1), a[i] / i));
				a[1] += a[i];
				a[i] = 0;
				continue;
			}
			int ret = a[i] / i;
			a[i] -= ret * i;
			a[1] += ret * i;
			if (ret) {
				ans.push_back(make_pair(make_pair(i, 1), ret));
			}
		}
		set<pair<int, int>> s;
		for (int i = 2; i <= n; i++) 
			if (a[i]) {
				s.emplace(i - a[i], i);
			}
		while (!s.empty()) {
			auto it = s.begin();
			if (a[1] < it->first) {
				break;
			}
			int id = it->second;
			ans.push_back(make_pair(make_pair(1, id), it->first));
			ans.push_back(make_pair(make_pair(id, 1), 1));
			a[1] += id - it->first;
			a[id] = 0;
			s.erase(it);
		}
		bool f = 1;
		for (int i = 2; i <= n; i++) {
			if (sum / n < a[i]) {
				f = 0;
				break;
			}
			if (sum / n - a[i]) {
				ans.push_back(make_pair(make_pair(1, i), sum / n - a[i]));
			}
		}
		if (!f) {
			cout << -1 << '\n';
			continue;
		}
		cout << ans.size() << '\n';
		for (auto it : ans) {
			cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
		}
	}
	return 0;
}