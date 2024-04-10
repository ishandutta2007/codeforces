/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << "1 1" << '\n' << -a[0] << '\n';
		cout << "1 1" << '\n' << 0 << '\n';
		cout << "1 1" << '\n' << 0 << '\n';
		return;
	}
	if (n == 2) {
		cout << "1 1" << '\n' << -a[0] << '\n';
		cout << "2 2" << '\n' << -a[1] << '\n';
		cout << "1 1" << '\n' << 0 << '\n';
		return;
	}
	if (n == 3) {
		cout << "1 1" << '\n' << -a[0] << '\n';
		cout << "2 2" << '\n' << -a[1] << '\n';
		cout << "3 3" << '\n' << -a[2] << '\n';
		return;
	}
	cout << "1 1" << '\n' << -a[0] << '\n';
	a[0] = 0;
	cout << "2 " << n << '\n';
	for (int i = 1; i < n; i++) {
		int x = 0;
		x = a[i] % n;
		x *= (n - 1);
		a[i] += x;
		cout << x << ' ';
	}
	cout << "\n1 " << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << -a[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}