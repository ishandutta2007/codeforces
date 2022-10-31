#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, k; string s, t;
		cin >> n >> k >> s;
		t = s;
		for (int i = 0; i < k - 1; i++) {
			t[i << 1] = '(';
			t[i << 1 | 1] = ')';
		}
		int l = n / 2 - k + 1;
		for (int i = 0; i < l; i++) {
			t[n - l * 2 + i] = '(';
			t[n - i - 1] = ')';
		}
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				int j = i;
				for (; t[i] != s[j]; j++);
				reverse(s.begin() + i, s.begin() + j + 1);
				ans.emplace_back(i, j + 1);
			}
		}
		cout << ans.size() << "\n";
		for (auto p : ans) cout << p.first + 1 << " " << p.second << "\n";
	}
	return 0;
}