#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	const int n = s.size();
	for (int i = 0; i < n; ++i) {
		bool l = (i == 0) || s[i - 1] != s[i];
		bool r = (i == n - 1) || s[i + 1] != s[i];
		if(l && r) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}