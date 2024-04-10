/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, LG = 18, NINF = 2000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * -1LL;
int a[N], b[N], rmq1[N][LG], rmq2[N][LG], rmq3[N][LG];
int ps[N], psb[N];
pair <pair <int, int>, int> p[N];
int n, m;
int x[N], r[N];
bool ans[N];

void sp() {
	for (int i = 1; i <= n; i++) {
      	rmq1[i][0] = ps[i] + x[i] * psb[i];
  	}
    for (int i = 1; i < LG; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + (1 << i) > n + 2)
                break;
            rmq1[j][i] = max(rmq1[j][i - 1], rmq1[j + (1 << (i - 1))][i - 1]);
        }
    }
	for (int i = 1; i <= n; i++) {
      	rmq2[i][0] = ps[i] + x[i] * psb[i] - x[i];
  	}
    for (int i = 1; i < LG; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + (1 << i) > n + 2)
                break;
            rmq2[j][i] = max(rmq2[j][i - 1], rmq2[j + (1 << (i - 1))][i - 1]);
        }
    }
	for (int i = 1; i <= n; i++) {
      	rmq3[i][0] = ps[i] + x[i] * psb[i] + x[i];
  	}
    for (int i = 1; i < LG; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + (1 << i) > n + 2)
                break;
            rmq3[j][i] = max(rmq3[j][i - 1], rmq3[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int ask1(int l, int r) { 
    int mx;
	int sz = (r - l + 1);
	if (sz <= 0)
		return NINF;
    if (sz == 1) {
        mx = rmq1[l][0];
    } else {
        int x = 1, y = 0;
        while (x <= sz) {
            x *= 2;
            y++;
        }
        y--;
        mx = max(rmq1[l][y], rmq1[r - (1 << y) + 1][y]);
    }
    return mx;
}

int ask2(int l, int r) { 
    int mx;
	int sz = (r - l + 1);
	if (sz <= 0)
		return NINF;
    if (sz == 1) {
        mx = rmq2[l][0];
    } else {
        int x = 1, y = 0;
        while (x <= sz) {
            x *= 2;
            y++;
        }
        y--;
        mx = max(rmq2[l][y], rmq2[r - (1 << y) + 1][y]);
    }
    return mx;
}

int ask3(int l, int r) { 
    int mx;
	int sz = (r - l + 1);
	if (sz <= 0)
		return NINF;
    if (sz == 1) {
        mx = rmq3[l][0];
    } else {
        int x = 1, y = 0;
        while (x <= sz) {
            x *= 2;
            y++;
        }
        y--;
        mx = max(rmq3[l][y], rmq3[r - (1 << y) + 1][y]);
    }
    return mx;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n + 5; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i].F.F >> p[i].F.S;
		p[i].S = i;
	}
	x[n + 1] = INT_MAX;
	r[n + 1] = 0;
	sort(p, p + n);
	for (int i = 1; i <= n; i++) {
		x[i] = p[i - 1].F.F;
		r[i] = p[i - 1].F.S;
	}
	for (int i = 1; i <= n; i++) {
		int l = lower_bound(x, x + i, x[i] - r[i]) - x;
		int rr = upper_bound(x + i + 1, x + n + 2, x[i] + r[i]) - x - 1;
		b[l]++;
		b[i + 1] -= 2;
		b[rr + 1]++;
		a[l] += (r[i] - x[i]);
		a[i + 1] += (x[i] - r[i]);
		a[i + 1] += (r[i] + x[i]);
		a[rr + 1] += (-r[i] - x[i]);
	}
	ps[0] = a[0];
	psb[0] = b[0];
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + a[i];
		psb[i] = psb[i - 1] + b[i];
	}
	sp();
	for (int i = 1; i <= n; i++) {
		int l = lower_bound(x, x + i, x[i] - r[i]) - x;
		int rr = upper_bound(x + i + 1, x + n + 2, x[i] + r[i]) - x - 1;
		l = max(l, 1LL);
		rr = min(rr, n);
		int mx = max(ask1(1, l - 1), ask1(rr + 1, n));
		mx = max(mx, ask2(l, i) + x[i] - r[i]);
		mx = max(mx, ask3(i + 1, rr) - x[i] - r[i]);
		ans[p[i - 1].S] = (mx <= m);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << '\n';
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