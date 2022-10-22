/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n;
	cin >> n;
	vector <int> x, y;
	for (int i = 0; i < 2 * n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0)
			y.push_back(abs(b));
		else
			x.push_back(abs(a));
	}
	ld ans = 0;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < n; i++) {
		ans += sqrt(x[i] * x[i] + y[i] * y[i]);
	}
	cout << fixed << setprecision(15);
	cout << ans << '\n';
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