#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	int loc1 = -1;
	for (int i = 0; i < n; ++i) {
		if (c[i] == 1) {
			loc1 = i;
			break;
		}
	}
	if (loc1 == -1) {
		cout << "NO" << endl;
		return;
	}
	int prev = 1;
	for (int i = 1; i < n; ++i) {
		int now = c[(loc1 + i) % n];
		if (now <= 1 || now > prev + 1) {
			cout << "NO" << endl;
			return;
		}
		prev = now;
	}
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}