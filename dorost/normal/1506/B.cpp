/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	int n, k, ans = 0;
	cin >> n >> k >> s;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*')
			v.push_back(i);
	}
	v.push_back(10000);
	for (int i = 0; i < v.size() - 2; i++) {
		int x;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] > v[i] + k) {
				x = j - 1;
				break;
			}
		}
		i = x - 1;
		ans++;
	}
	cout << ans + 1 << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}