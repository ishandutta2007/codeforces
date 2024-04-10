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
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i], sum += a[i];
	int mx = *max_element(a, a + n);
	cout << max(mx * (n - 1), (sum + n - 2) / (n - 1) * (n - 1)) - sum << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}