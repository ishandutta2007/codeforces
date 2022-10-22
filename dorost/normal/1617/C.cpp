/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];
bool c[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		c[i] = false;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > n || c[a[i]])
			v.push_back(a[i]);
		else
			c[a[i]] = true;
	}
	sort(v.begin(), v.end());
	bool f = true;
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == false) {
			if (i >= (v[x] + 1) / 2) 
				f = false;
			x++;
		}
	}
	cout << (f ? (int)v.size() : -1) << '\n';
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