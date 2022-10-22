/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];
vector <int> v[N];

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> w;
	for (int i = 0; i <= n; i++) {
		v[i].clear();
	}
	int mnx = INT_MAX, mxx = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
		if (i <= k * 3 || n - i <= k * 3) {
			w.push_back(a[i]);
		}
		mnx = min(mnx, a[i]);
		mxx = max(mxx, a[i]);
	}
	int mx = LLONG_MIN;
	for (int i = mnx; i <= min(n, mnx + k * 3); i++) {
		for (int j = max(0LL, (int)v[i].size() - 2); j < v[i].size(); j++) {
			int x = v[i][j];
			for (int i = 0; i < n; i++) {
				if (i == x) {
					continue;
				}
				mx = max(mx, (x + 1) * (i + 1) - ((a[x] | a[i]) * k));
			}
		}
	}
	for (int i = mxx; i >= max(0LL, mxx - k * 3); i--) {
		for (int j = max(0LL, (int)v[i].size() - 2); j < v[i].size(); j++) {
			int x = v[i][j];
			for (int i = 0; i < n; i++) {
				if (i == x) {
					continue;
				}
				mx = max(mx, (x + 1) * (i + 1) - ((a[x] | a[i]) * k));
			}
		}
	}
	for (auto i : w) {
		for (int j = max(0LL, (int)v[i].size() - 2); j < v[i].size(); j++) {
			int x = v[i][j];
			for (int i = 0; i < n; i++) {
				if (i == x) {
					continue;
				}
				mx = max(mx, (x + 1) * (i + 1) - ((a[x] | a[i]) * k));
			}
		}
	}
	cout << mx << ' ';
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