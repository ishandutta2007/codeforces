/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1023;
int a[N];

void solve() {
	int n;
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			x++;
		else
			y++;
	}
	if (x >= n / 2) {
		cout << n / 2 << '\n';
		for (int i = 0; i < n / 2; i++)
			cout << 0 << ' ';
		cout << '\n';
	}else {
		cout << y / 2 * 2 << '\n';
		for (int i = 0; i < y / 2 * 2; i++)
			cout << 1 << ' ';
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