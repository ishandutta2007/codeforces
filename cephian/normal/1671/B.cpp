#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ok(const vector<int> &a, int start) {
	for (int i = 0; i < a.size(); ++i) {
		if (abs(a[i] - (start + i)) > 1)
			return false;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (ok(a, a[0] - 1) || ok(a, a[0]) || ok(a, a[0] + 1)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}