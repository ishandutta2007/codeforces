#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, l, k; cin >> n >> l >> k;
	string s; cin >> s;
	vector<int> cnt(26);
	for (char c: s) {
		cnt[c - 'a']++;
	}

	k--;
	int L = 0, R = k;
	vector<string> ans(n);
	for (int i = 0; i < l; i++) {
		int petr = 0;
		for (int j = L; j <= R; j++) {
			while (petr < 26 && cnt[petr] == 0) petr++;

			cnt[petr]--;
			ans[j].push_back('a' + petr);
		}

		char c = ans[k].back();
		while (ans[L].back() != c) L++;
		while (ans[R].back() != c) R--;
	}

	int petr = 0;
	for (int i = 0; i < n; i++) {
		while (ans[i].size() < l) {
			while (petr < 26 && cnt[petr] == 0) petr++;
			ans[i].push_back('a' + petr);
			cnt[petr]--;
		}
	}

	sort(ans.begin(), ans.end());
	for (string s: ans) cout << s << '\n';

	return 0;
}