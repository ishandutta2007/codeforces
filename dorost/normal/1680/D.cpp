/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 3012;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k, wef = 0, s = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			wef++;
		s -= a[i];
	}
	if (-s + k * wef < 0 || -s - k * wef > 0) {
		cout << -1 << '\n';
		return 0;
	}
	ll mx = 0;
	for (int l = 0; l < n; l++) {
		int cnt = 0, sum = 0;
		for (int r = l; r < n; r++) {
			cnt += (a[r] == 0);
			sum += a[r];
			int ans = min((wef - cnt) * k + s, k * cnt);
			mx = max(mx, ans + sum);
		}
	}
	for (int i = 0; i < n; i++)
		a[i] = -a[i];
	s = -s;
	for (int l = 0; l < n; l++) {
		int cnt = 0, sum = 0;
		for (int r = l; r < n; r++) {
			cnt += (a[r] == 0);
			sum += a[r];
			int ans = min((wef - cnt) * k + s, k * cnt);
			mx = max(mx, ans + sum);
		}
	}
	cout << mx + 1 << '\n';
}