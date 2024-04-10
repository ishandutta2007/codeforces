#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	map<pair<int, bool>, vector<int>> col;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			int a;
			cin >> a;
			col[make_pair(a, 0)].push_back(j);
			col[make_pair(a, 1)].push_back(i);
		}
	}
	ll ans = 0;
	for(auto& x : col) {
		vector<int>& v = x.second;
		sort(v.begin(), v.end());

		ll rolling_sum = 0;
		for(int i = 1; i < v.size(); ++i) {
			rolling_sum += (v[i]-v[i-1])*i;
			ans += rolling_sum;
		}
	}
	cout << ans << '\n';
}