/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int ans(int cnt0, vector <int> v) {
	if (v.size() == 1)
		return v[0];
	if (v.size() == 0)
		return 0;
	vector <int> w;
	if (cnt0) {
		w.push_back(v[0]);
	}
	for (int i = 1; i < (int)v.size(); i++) {
		w.push_back(v[i] - v[i - 1]);
	}
	sort(w.begin(), w.end());
	if (cnt0)
		cnt0--;
	vector <int> l;
	for (int i = 0; i < (int)w.size(); i++) {
		if (w[i] == 0)
			cnt0++;
		else
			l.push_back(w[i]);
	}
	return ans(cnt0, l);
}

void solve() {
	int n;
	cin >> n;
	int cnt0 = 0;
	vector <int> v;
	for (int i = 0; i < n; i++) { 
		int x;
		cin >> x;
		if (x == 0)
			cnt0++;
		else
			v.push_back(x);
	}
	cout << ans(cnt0, v) << ' ';
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