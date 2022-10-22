/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 27;
int cnt[M];

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string t;
	vector <string> v;
	t += s[0];
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1])
			v.push_back(t), t = "";
		t += s[i];
	}
	v.push_back(t);
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].size();
		cnt[(int)(v[i][0] - 'a')] += x / k;
//		cerr << (v[i][0]) << ' ' << x / k << '\n';
	}
	cout << *max_element(cnt, cnt + M);
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}