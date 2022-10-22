/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
map <int, int> mn, mx;

void solve() {
	int n, k;
	cin >> n >> k;
	mn.clear();
	mx.clear();
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (mn[x] == 0)
			mn[x] = i;
		mx[x] = i;
	}
	for (int j = 0; j < k; j++) {
		int a, b;
		cin >> a >> b;
		cout << (mx[b] && mn[a] && mx[b] >= mn[a] ? "Yes" : "No") << '\n';
	}
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