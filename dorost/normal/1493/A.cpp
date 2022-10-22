/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> v;
	for (int i = ((k + 1) / 2); i < (k); i++) {
		v.push_back(i);
	}
	for (int i = k + 1; i <= n; i++) {
		v.push_back(i);
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << ' ';
	cout << '\n';
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