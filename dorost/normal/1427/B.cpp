/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string t;
	t += s[0];
	vector <string> v;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			v.push_back(t);
			t = "";
		}
		t += s[i];
	}
	v.push_back(t);
	vector <pair <int, int>> v2;
	for (int i = 0; i < v.size(); i++) {
		if (v[i][0] == 'W' || i == 0 || i == v.size() - 1)
			continue;
		v2.push_back({v[i].size(), i});
	}
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++) {
		if (k < v2[i].F)
			break;
		k -= v2[i].F;
		for (int j = 0; j < v[v2[i].S].size(); j++) {
			v[v2[i].S][j] = 'W';
		}
	}
	string ss = "";
	for (int i = 0; i < v.size(); i++) {
		ss += v[i];
	}
	for (int i = 1; i < ss.size(); i++) {
		if (k == 0)
			break;
		if (ss[i] == 'W' && ss[i - 1] == 'L') {
			int kk = k;
			for (int j = i - 1; j >= max(0, i - kk); j--) {
				ss[j] = 'W';
				k--;
			}
		}
	}
	for (int i = 0; i < (int)ss.size() - 1; i++) {
		if (k == 0)
			break;
		if (ss[i] == 'W' && ss[i + 1] == 'L') {
			int kk = k;
			for (int j = i + 1; j <= min((int)ss.size() - 1, i + kk); j++) {
				ss[j] = 'W';
				k--;
			}
		}
	}
	if (k) {
//		cout << 'x' << endl;
		for (int i = 0; i < ss.size(); i++) {
			if (ss[i] == 'L' && k > 0) {
				k--;
				ss[i] = 'W';
			}
		}
	}
//	cout << ss << '\n';
	int ans = (ss[0] == 'W');
	for (int i = 1; i < ss.size(); i++) {
		if (ss[i] == 'W') {
			ans += (1 + (ss[i - 1] == 'W'));
		}
	}
	cout << ans << '\n';
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