/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N], b[N], suf[N], pre[N];

void solve() {
	int n, k, t;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		a[i] = 0;
	for (int i = 0; i < k; i++) 
		cin >> b[i];
	for (int i = 0; i < k; i++) {
		cin >> t;
		a[b[i] - 1] = t;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			a[i] = 2000000000;
		}
	}
	pre[0] = a[0];
	for (int i = 1; i < n; i++) {
		pre[i] = min(pre[i - 1], a[i] - i);
	}
	suf[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = min(suf[i + 1], a[i] - (n - 1 - i));
	}
	for (int i = 0; i < n; i++) {
		cout << min(pre[i] + i, suf[i] + (n - i - 1)) << ' ';
	}
	cout << '\n';
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