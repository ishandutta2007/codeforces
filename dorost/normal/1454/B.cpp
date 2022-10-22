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
	int n, x;
	cin >> n;
	for (int i = 0; i <= n; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x] = (a[x] == 0 ? i + 1 : -1);
	}
	for (int i = 0; i <= n; i++)
		if (a[i] > 0) {
			cout << a[i] << '\n';
			return;
		}
	cout << -1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}