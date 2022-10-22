/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	map <int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		if (mp[a[i] + k]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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