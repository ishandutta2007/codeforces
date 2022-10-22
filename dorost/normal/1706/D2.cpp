/* 	* In the name of GOD  */

#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, SQ = 320;
int a[N];
int ss[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> v = {0};
	int x = a[0]; 
	for (int i = 1; i <= SQ; i++) {
		v.push_back(x / i);
		int l = x / (i + 1) + 1;
		int r = x / i;
		if (l <= r) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int mn = INT_MAX;
	for (int i : v) {
		if (i < x / k)
			continue;
		vector <pair <int, int>> w;
		for (int j = 0; j < n; j++) {
			if (i == 0 || a[j] / k >= i) {
				w.push_back({k, k});
			} else {
				int l = max(0, min(k, (a[j] / i) + 3));
				int r = min(k, max(0, (a[j] / i) - 3));
				while (l - r > 1) {
					int mid = (l + r) / 2;
					if (a[j] / mid < i) {
						l = mid;
					} else {
						r = mid;
					}
				}
				w.push_back({r, l});
			}
		}
		int mxx = 0;
		for (int j = 0; j < n; j++) {
			w[j].F = a[j] / w[j].F;
			w[j].S = a[j] / w[j].S;
			swap(w[j].F, w[j].S);
			if (w[j].F >= i) {
				mxx = max(mxx, w[j].F);
				w[j].F = i;
				w[j].S = i;
			}
		}
		sort(w.begin(), w.end());
		ss[0] = INT_MIN;
		int ss2 = INT_MAX;
		for (int i = 1; i <= n; i++) {
			ss[i] = max(ss[i - 1], w[i - 1].S);
			ss2 = min(ss2, w[i - 1].S);
		}
		int mx = INT_MIN;
		int mx2 = INT_MAX;
		for (int i = n - 1; i >= 0; i--) {
			mx = max(mx, w[i].F);
			mx2 = min(mx2, w[i].F);
			if (i != 0) {
				mn = min(mn, max(mxx, ss[i]) - mx2);
			}
		}
		mn = min(mn, max(mxx, mx) - mx2);
		mn = min(mn, max(mxx, ss[n]) - ss2);
	}
	cout << mn << ' ';
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