#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int neg = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		neg += a[i] < 0;
	}

	int prev = -2e9;
	for (int i = 0; i < n; ++i) {
		int cur = abs(a[i]) * (i < neg ? -1 : 1);
		if(cur < prev) {
			cout << "NO\n";
			return;
		}
		prev = cur;
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}