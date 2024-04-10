/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		vector <int> v;
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == c)
				v.push_back(i);
		}
		for (int k = 0; k < n; k++) {
			map <char, int> mp;
			for (auto y : v) {
				mp[s[(k + y) % n]]++;
			}
			int l = 0;
			for (auto [v, w] : mp) {
				if (w == 1) {
					l++;
				}
			}
			x = max(x, l);
		}
		ans += x;
	}
	cout << fixed << setprecision(10) << (ld)ans / (ld)n;
}