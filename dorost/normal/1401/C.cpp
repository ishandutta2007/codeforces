/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102345;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int x = b[0];
	int g = -1;
	bool f = true;
	int b2 = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i])
			continue;
		if (a[i] % x != 0)
			f = false;
	}
	cout << (f ? "YES\n" : "NO\n");
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}