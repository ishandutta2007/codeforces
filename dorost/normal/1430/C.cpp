/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	cout << 2 << '\n';
	int mia = n;
	for (int i = n - 1; i > 0; i--) {
		cout << mia << ' ' << i << '\n';
		mia = (mia + i + 1) / 2;
	}
	assert(mia == 2);
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