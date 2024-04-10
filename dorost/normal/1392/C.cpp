/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

void solve() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 2; i >= 0; i--) {
		if(a[i] <= a[i + 1])
			continue;
		ans += (a[i] - a[i + 1]);
		a[i + 1] = a[i];
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}