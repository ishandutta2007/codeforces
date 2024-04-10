/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 104;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n * 2; i++) {
		cin >> a[i];
	}
	sort(a, a + n * 2);
	int x = 0, y = n * 2 - 1;
	for (int i = 0; i < n; i++) {
		cout << a[y] << ' '  << a[x] << ' ';
		y--;
		x++;
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}