#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> freq;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++freq[a[i]];
	}
	int most = 0;
	for(const auto& p : freq)
		most = max(most, p.second);

	int ops = 0;
	while(most < n) {
		int amt = min(most, n-most);
		ops += 1 + amt;
		most += amt;
	}
	cout << ops << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}