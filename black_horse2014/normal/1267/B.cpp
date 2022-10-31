#include <bits/stdc++.h>

#ifdef LOCAL
#include "E:\\Competitive-Programming\\Template\\Standard Template Codes\\debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.length();
	vector<pair<char, int>> a;
	for (int i = 0, j; i < n; i = j) {
		for (j = i; j < n && s[i] == s[j]; j++);
		a.emplace_back(s[i], j - i);
	}
	int ans = 0;
	if (a.size() & 1) {
		if (a[a.size() / 2].second >= 2) {
			ans = a[a.size() / 2].second + 1;
			for (int k = 0; k < a.size() / 2; k++) {
				if (a[k].first == a[a.size() - 1 - k].first && a[k].second + a[a.size() - 1 - k].second >= 3) {
					continue;
				}
				ans *= 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}