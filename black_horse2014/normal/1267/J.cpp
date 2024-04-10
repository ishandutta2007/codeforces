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
	
	int ncase; cin >> ncase;
	while (ncase--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<int> cnt(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int m = 0;
		for (int i = 0, j; i < n; i = j) {
			for (j = i; j < n && a[i] == a[j]; j++);
			cnt[m++] = j - i;
		}
		sort(cnt.begin(), cnt.begin() + m);
		for (int i = cnt[0]; i > 0; i--) {
			int ret = 0;
			bool flag = true;
			for (int j = 0; j < m; j++) {
				int to = cnt[j] / i;
				int from = (cnt[j] + i) / (i + 1);
				if (from <= to) {
					ret += from;
				} else {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << ret << "\n";
				break;
			}
		}
	}
	return 0;
}