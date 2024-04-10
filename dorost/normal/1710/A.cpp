/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 102341;
int a[N];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	bool g = (m % 2 == 0);
	int sum = 0;
	bool ans = false;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		int x = a[i] / n;
		if (x <= 1)
			continue;
		if (x != 2)
			g = true;
		sum += x;
	}
	ans |= (g && sum >= m);
	g = (n % 2 == 0);
	sum = 0;
	for (int i = 0; i < k; i++) {
		int x = a[i] / m;
		if (x <= 1)
			continue;
		if (x != 2)
			g = true;
		sum += x;
	}
	ans |= (g && sum >= n);
	cout << (ans ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}