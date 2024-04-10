/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
int a[N], b[N];

void solve() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (sum > 0) {
		sort(a, a + n);
		reverse(a, a + n);
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	} else {
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}