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
		vector<vector<int>> a(3, vector<int>(n));
		for (int j : {0, 1, 2}) {
			for (int i = 0; i < n; i++) {
				cin >> a[j][i];
			}
		}
		vector<int> ans(n);
		ans[0] = a[0][0];
		for (int i = 1; i < n; i++) {
			for (int j : {0, 1, 2}) {
				if (a[j][i] == ans[i - 1]) {
					continue;
				}
				if (i == n - 1 && a[j][i] == ans[0]) {
					continue;
				}
				ans[i] = a[j][i];
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}