/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	for (int i = 0; i < n; i++)
		a[i][i] = 166;
	for (int i = 0; i < n - 1; i++) {
		a[i][i + 1] = 1;
	}
	a[n - 1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
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