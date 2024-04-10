#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void flip(char &c) { c = '0' + '1' - c; }

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> a(n);
	if (k & 1) {
		for (int i = 0; i < n; ++i) {
			flip(s[i]);
		}
	}

	for (int i = 0; k > 0 && i < n; ++i) {
		if (s[i] == '0') {
			++a[i];
			flip(s[i]);
			--k;
		}
	}
	if (k > 0) {
		a[n - 1] += k;
		if (k % 2) {
			flip(s[n-1]);
		}
	}
	cout << s << '\n';
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}