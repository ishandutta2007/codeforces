#include <bits/stdc++.h>
using namespace std;

const int N = 330000;
const int INF = 1e9+7;
int p[N];
char c[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];
	p[0] = -INF, c[0] = 'G';
	p[n + 1] = 2 * INF, c[n + 1] = 'G';
	n++;
	int dap = 0;
	for (int i = 0; i < n; i++) if (c[i] == 'G') {
		int l = i, r;
		int pr = i, pb = i;
		int dr = 0, db = 0;
		int mir = n, mar = 0, mib = n, mab = 0;
		for (r = i + 1; r <= n && c[r] != 'G'; r++) {
			if (c[r] == 'R') {
				mir = min(mir, r);
				mar = max(mar, r);
				dr = max(dr, p[r] - p[pr]);
				pr = r;
			} else {
				mib = min(mib, r);
				mab = max(mab, r);
				db = max(db, p[r] - p[pb]);
				pb = r;
			}
		}
		dr = max(dr, p[r] - p[pr]);
		db = max(db, p[r] - p[pb]);
		if (l == 0 && r == n) {
			if (mar) dap += p[mar] - p[mir];
			if (mab) dap += p[mab] - p[mib];
		} else if (l == 0) {
			if (mar) dap += p[r] - p[mir];
			if (mab) dap += p[r] - p[mib];
		} else if (r == n) {
			if (mar) dap += p[mar] - p[l];
			if (mab) dap += p[mab] - p[l];
		} else {
			dap += min(2LL * (p[r] - p[l]), 3LL * (p[r] - p[l]) - dr - db);
		}
		i = r - 1;
	}
	cout << dap << endl;
	return 0;
}