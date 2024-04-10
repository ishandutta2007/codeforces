/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
ld ps[N], ss[N];
int a[N];

void solve() {
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ps[0] = 0;
	ss[n + 1] = 0;
	ld sp = 1;
	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + ((ld)(i == 0 ? a[0] : a[i] - a[i - 1]) / sp);
		sp++;
	}
	ps[n + 1] = ps[n] + ((l - a[n - 1]) / sp);
	sp = 1;
	for (int i = n - 1; i >= 0; i--) {
		ss[i + 1] = ss[i + 2] + ((ld)(i == n - 1 ? l - a[n - 1] : a[i + 1] - a[i]) / sp);
		sp++;
	}
	ss[0] = ss[1] + (a[0] / sp);
	cout << fixed << setprecision(12);
	/* for (int i = 0; i <= n + 1; i++)
		cout << ps[i] << ' ';
	cout << '\n';
	for (int i = 0; i <= n + 1; i++)
		cout << ss[i] << ' ';
	cout << '\n';  */
	ld ans = -1;
	for (int i = 0; i <= n; i++) {
		if (max(ps[i], ss[i + 1]) <= min(ps[i + 1], ss[i])) {
			ld l = ss[i + 1], r = ps[i + 1];
			ld l2 = l, r2 = r, ssp = 1, ssp2 = 1;
			for (int i = 0; i < n; i++) {
//				l2 += ();
			}
			ld x, k = r2 - l2;
			ld sp1 = i + 1, sp2 = n - i + 1;
//			cout << sp1 << ' ' << sp2 << ' ' << l << ' ' << r << '\n';
			x = (sp1 / (sp1 + sp2)) * k;
			ans = l + x;
			break;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}