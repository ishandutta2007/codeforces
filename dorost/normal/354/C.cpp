/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 701234, M = N * 2;
int a[N], ps[M];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, x, y, k;
	x = 1, y = 0;
	cin >> n >> k;
	int wef = k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ps[a[i]]++;
	}
	for (int i = 1; i < M; i++)
		ps[i] += ps[i - 1];
	ll mx = 0;
	for (int i = 1; i < M; i++) {
		ll cntall = n;
		for (int j = i; j < M; j += i) {
			ll l = j;
			ll r = min(j + wef, j + i - 1);
			r = min(M - 1, r);
			l = min(M, l);
			r = max(0LL, r);
			l = max(1LL, l);
			ll cnt = ps[r] - ps[l - 1];
			cntall -= cnt;
		}
		if (cntall == 0)
			mx = max(mx, i);
	}
	cout << mx;
}