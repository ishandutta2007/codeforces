/* 	* In the name of GOD 
	* Ftr max vhwxyhkvxl ux pbma rhn :)) */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2005;
int a[N], n;

bool check(int x) {
	int b = 0, num = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		b ^= a[i];
		if (b == x) {
			num++;
			b = 0;
			mx = i;
		} 
	}
	int sum = 0;
	for (int i = mx + 1; i < n; i++)
		sum += a[i];
	return (num > 1 && sum == 0);
}

void solve() {
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x = x ^ a[i];
	}
	if (x == 0) {
		cout << "YES\n";
		return;
	}
	cout << (check(x) ? "YES\n" : "NO\n");
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