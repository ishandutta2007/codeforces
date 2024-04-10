/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 6;
int a[M], b[N], c[N][M], suf[N];
pair <int, int> d[N];

void solve() {
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			c[i][j] = b[i] - a[j];
		}
	}
	int mmn = LLONG_MAX;
	for (int i = 0; i < 6; i++) {
		d[0].F = 0;
		d[0].S = 0;
		for (int j = 1; j < n; j++) {
			int mn = INT_MAX, mn2 = INT_MAX;
			for (int k = 0; k < 6; k++) {
				if (c[0][i] >= c[j][k] && abs(c[0][i] - c[j][k]) < mn) {
					mn = abs(c[0][i] - c[j][k]);
				}
			}
			for (int k = 0; k < 6; k++) {
				if (c[0][i] <= c[j][k] && abs(c[0][i] - c[j][k]) < mn2) {
					mn2 = abs(c[0][i] - c[j][k]);
				}
			}
			d[j].F = mn;
			d[j].S = mn2;
		}
		sort(d, d + n);
		suf[n] = 0;
		for (int j = n - 1; j >= 0; j--) {
			suf[j] = max(suf[j + 1], d[j].S);
		}
		mmn = min(mmn, suf[0]);
		int mx = 0;
		for (int j = 0; j < n; j++) {
			mx = max(mx, d[j].F);
			mmn = min(mmn, mx + suf[j + 1]);
		}
	}
	cout << mmn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}