/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool f = false;
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != a[0])
			f = true;
	}
	if (!f) {
		cout << "NO" << '\n';
		return;
	}
	root = 0;
	int ne = -1;
	cout << "YES" << '\n';
	for (int i = 0; i < n; i++) {
		if (a[i] != a[root]) 
			cout << root + 1 << ' ' << i + 1 << '\n', ne = i;
	}
	assert(ne != -1);
	for (int i = 0; i < n; i++) {
		if (a[root] == a[i] && i != root)
			cout << ne + 1 << ' ' << i + 1 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}