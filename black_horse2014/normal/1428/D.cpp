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
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> left2, left3;
	vector<pair<int, int>> res;
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			continue;
		}
		if (a[i] == 1) {
			if (left2.size()) {
				res.emplace_back(left2.back(), i);
				left2.pop_back();
			} else if (left3.size()) {
				res.emplace_back(left3.back(), i);
				left3.pop_back();
				res.emplace_back(cur++, i);
			} else {
				res.emplace_back(cur++, i);
			}
		} else if (a[i] == 2) {
			if (left3.size()) {
				res.emplace_back(left3.back(), i);
				left3.pop_back();
			}
			res.emplace_back(cur, i);
			left2.push_back(cur++);
		} else {
			if (left3.size()) {
				res.emplace_back(left3.back(), i);
				left3.pop_back();
			}
			res.emplace_back(cur, i);
			left3.push_back(cur++);
		}
	}
	if (left2.size() || left3.size()) {
		cout << "-1\n";
	} else {
		cout << res.size() << "\n";
		for (auto it : res) {
			cout << it.first << ' ' << it.second << "\n";
		}
	}
	return 0;
}