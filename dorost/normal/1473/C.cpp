/*  * In the name of GOD 
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
	for (int i = 0; i < k; i++) 
		v.push_back(i + 1);
	reverse(v.begin() + k - (n - k + 1), v.end());
	for (auto x : v) {
		cout << x << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}