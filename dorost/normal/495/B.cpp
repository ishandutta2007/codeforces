/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b;
	cin >> a >> b;
	if (a < b) 
		cout << 0;
	if (a == b)
		cout << "infinity";
	if (a <= b)
		return;
	int x = a - b, ans = 0;
	vector <int> v;
	for (int i = 1; i * i <= x; i++) {
		if (x % i)
			continue;
		v.push_back(i);
		if (i * i != x) {
			v.push_back(x / i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > b)
			ans++;
	}
	cout << ans;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}