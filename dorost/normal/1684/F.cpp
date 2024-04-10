/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int mxr[N], mnl[N];
int a[N];
pair <int, int> b[N];
vector <int> v[N];
int l[N], r[N];
int ne[N];
int need[N];

void solve() {
	for (int i = 0; i < N; i++) {
		mxr[i] = 0;
		ne[i] = 0;
		mnl[i] = N;
		v[i].clear();
	}
	int nl = N, nr = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i].F = a[i];
		b[i].S = i;
	}
	sort(b, b + n);
	a[b[0].S] = 0;
	for (int i = 1; i < n; i++) {
		if (b[i].F == b[i - 1].F) 
			a[b[i].S] = a[b[i - 1].S];
		else
			a[b[i].S] = a[b[i - 1].S] + 1;
	}
	for (int i = 0; i < n; i++) {
		v[a[i]].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
		mnl[r[i]] = min(mnl[r[i]], l[i]);
		mxr[l[i]] = max(mxr[l[i]], r[i]);
	}
	for (int i = 1; i < n; i++) {
		mxr[i] = max(mxr[i - 1], mxr[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		mnl[i] = min(mnl[i], mnl[i + 1]);
	}
	for (int i = 0; i < n; i++) {
		int rr = mxr[i];
		int ll = mnl[i];
		if (i <= rr) {
			int x = upper_bound(v[a[i]].begin(), v[a[i]].end(), i) - v[a[i]].begin();
			int y = upper_bound(v[a[i]].begin(), v[a[i]].end(), rr) - v[a[i]].begin() - 1;
			if (x >= 0 && x < v[a[i]].size() && v[a[i]][x] > i && v[a[i]][x] <= rr) {
				x = v[a[i]][x];
				nl = min(nl, x);
				nr = max(nr, i);
				ne[i] = max(ne[i], x);
			} 
			if (y >= 0 && y < v[a[i]].size() && v[a[i]][y] > i && v[a[i]][y] <= rr) {
				y = v[a[i]][y];
				nl = min(nl, y);
				nr = max(nr, i);
				ne[i] = max(ne[i], y);
			}
		}
	}
	if (nl == N) {
		cout << 0 << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0)
			need[i] = 0;
		else
			need[i] = max(need[i - 1], ne[i - 1]);
	}
	int mn = N;
	for (int i = 0; i < n; i++) {
		if (i > nl)
			continue;
		int rr = max(nr, need[i]);
		mn = min(mn, rr - i + 1);
	}
	cout << mn << '\n';
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