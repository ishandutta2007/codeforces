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
		int n, m; cin >> n >> m;
		int flag = false;
		for (int i = 0; i < n; i++) {
			int a[4];
			for (int j = 0; j < 4; j++) {
				cin >> a[j];
			}
			if (a[1] == a[2]) {
				flag = true;
			}
		}
		if (flag && (~m & 1)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}