#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i].first;
	for(int i = 0; i < n; ++i)
		cin >> v[i].second;
	sort(v.begin(), v.end());
	for(auto p : v) {
		if(p.first <= k)
			k += p.second;
	}
	cout << k << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}