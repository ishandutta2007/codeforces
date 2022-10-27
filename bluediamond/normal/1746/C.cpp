#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> av(n), dif(n);
		for (int i = 0; i < n; i++) {
			cin >> av[i];
		}
		dif[0] = av[0];
		for (int i = 1; i < n; i++) {
			dif[i] = av[i] - av[i - 1];
		}
		vector<pair<int, int>> need;
		for (int i = 0; i < n; i++) {
			need.push_back({ -dif[i], i });
		}
		sort(need.begin(), need.end());
		int p = 0;
		for (int x = 1; x <= n; x++) {
			while (p < (int)need.size() && need[p].first <= 0) {
				p++;
			}
			if (p < (int)need.size()) {
				need[p].first -= x;
				cout << need[p].second + 1 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		cout << "\n";
		while (p < (int)need.size() && need[p].second <= 0) {
			p++;
		}
	}
	return 0;
}