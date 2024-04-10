/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int mn = INT_MAX;
	for (char k = 'a'; k <= 'z'; k++) {
		string t;
		vector <int> v;
		int x = 0, y = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == k) {
				x++;
				y++;
			} else {
				t += s[i];
				v.push_back(x);
				x = 0;
			}
		}
		v.push_back(x);
		string g = t;
		reverse(g.begin(), g.end());
		if (t != g)
			continue;
		for (int i = 0; i < (int)(v.size() + 1) / 2; i++) {
			y -= min(v[i], v[(int)v.size() - i - 1]) * (v.size() % 2 && i == (int)(v.size() - 1) / 2 ? 1 : 2);
		}
		mn = min(mn, y);
	}
	cout << (mn == INT_MAX ? -1 : mn) << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}