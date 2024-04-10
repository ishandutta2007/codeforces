#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		vector<int> a(n + 1);
		vector<vector<int>> b(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[a[i]].push_back(i);
		}
		vector<int> ans(n + 1, n + 1);
		for (int i = 1; i <= n; i++) {
			int last = 0, len = 0;
			for (int x : b[i]) {
				len = max(len, x - last);
				last = x;
			}
			len = max(len, n + 1 - last);
			if (len <= n) {
				ans[len] = min(ans[len], i);
			}
		}
		for (int i = 1; i <= n; i++) {
			ans[i] = min(ans[i], ans[i - 1]);
		}
		for (int i = 1; i <= n; i++) {
			if (ans[i] == n + 1) {
				ans[i] = -1;
			}
			cout << ans[i] << " \n"[i == n];
		}
	}
	return 0;
}