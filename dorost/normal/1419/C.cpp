/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];

void solve() {
	int n, x, num = 0, sum = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] == x)
			num++;
	}
	if (num == n) {
		cout << 0 << ' ';
		return;
	}
	if (num > 0) {
		cout << 1 << ' ';
		return;
	}
	if (sum % n == 0 && sum / n == x) {
		cout << 1 << ' ';
		return;
	}
	cout << 2 << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}