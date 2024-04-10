/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	if (k >= (min(n, m))) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int mx = 0;
	for (int x = 0; x <= k; x++) {
		int in = lower_bound(b, b + m, a[x] + ta) - b + (k - x);
		if (in >= m) {
			mx = INT_MAX;
			continue;
		}
		mx = max(mx, b[in] + tb);
	}
	cout << (mx == INT_MAX ? -1 : mx);
}