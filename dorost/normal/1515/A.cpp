/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
int a[N];

void solve() {
	int n, x;
	cin >> n >> x;
	int sum = 0, in = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (sum == x) {
			in = i;
		}
	}
	if (in == n - 1) {
		cout << "NO\n";
	} else {
		if (in != -1)
			swap(a[in], a[in + 1]);
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
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