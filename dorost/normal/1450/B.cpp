/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int x[N], y[N];

int dis(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	bool f = false;
	for (int i = 0; i < n; i++) {
		bool h = true;
		for (int j = 0; j < n; j++) {
			if (dis(i, j) > k)
				h = false;
		}
		if (h)
			f = true;
	}
	cout << (f ? 1 : -1) << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}