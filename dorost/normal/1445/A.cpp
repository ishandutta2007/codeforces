/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1005;
int a[N], b[N];

void solve() {
	int n, x;
	cin >> n >> x;
	bool f = true;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] + a[n - i - 1] > x)
			f = false;
	}
	cout << (f ? "Yes" : "No") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}