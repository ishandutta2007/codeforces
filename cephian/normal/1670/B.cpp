#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	string s;
	int k;
	bool special[26] = {};
	cin >> n >> s >> k;
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		special[c - 'a'] = true;
	}
	int mx = 0;
	int last = 0;
	for (int i = 1; i < n; ++i) {
		if (special[s[i] - 'a']) {
			mx = max(mx, i - last);
			last = i;
		}
	}
	cout << mx << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}