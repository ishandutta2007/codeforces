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
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	vector <int> v;
	for (int i = 0; i < n - 1; i++) {
		v.push_back(a[i + 1] - a[i]);
	}
	k = abs(k - a[0]);
	int gcd = 0;
	for (int i = 0; i < v.size(); i++) {
		gcd = __gcd(gcd, v[i]);
	}
	if (k % gcd == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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