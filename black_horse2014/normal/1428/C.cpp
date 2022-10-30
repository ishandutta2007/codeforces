//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
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
	int ncase;
	for (cin >> ncase; ncase --; ) {
		string s; cin >> s;
		int n = s.size();
		int cntb = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') {
				cntb++;
			}
		}
		int cur = 0;
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'B') {
				cur++;
			}
			else {
				if (cur > 0) {
					cur--;
					cnt++;
				}
			}
		}
		cout << (cntb - cnt) % 2 + (n - cntb - cnt) << '\n';
	}
	return 0;
}