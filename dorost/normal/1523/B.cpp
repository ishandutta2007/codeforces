/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << n * 3 << '\n';
	for (int i = 0; i < n; i += 2) {
		cout << '2' << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << '1' << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << '2' << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << '2' << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << '1' << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << '2' << ' ' << i + 1 << ' ' << i + 2 << '\n';
	}
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