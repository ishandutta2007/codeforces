/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool f = false;
	for (int i = 0; i < n; i++) {
		if (a[i] != a[0])
			 f = true;
	}
	cout << (f ? 1 : n) << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}