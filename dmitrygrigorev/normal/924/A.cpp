#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5;
int arr[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector <string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector <vector <int> > whom(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				whom[j].push_back(i);
			}
		}
	}
	sort(whom.begin(), whom.end());
	whom.resize(unique(whom.begin(), whom.end()) - whom.begin());

	vector <int> cnt(n, 0);
	for (auto e : whom) {
		for (auto t : e) {
			if (cnt[t]) {
				cout << "No\n";
				return 0;
			}
			cnt[t]++;
		}
	}

	cout << "Yes\n";


	return 0;
}