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
ll psi[M];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, x, y;
	cin >> n >> x >> y;
	int wef = x / y;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ps[a[i]]++;
		psi[a[i]] += a[i];
	}
	for (int i = 1; i < M; i++)
		ps[i] += ps[i - 1];
	for (int i = 1; i < M; i++)
		psi[i] += psi[i - 1];
	ll mn = LLONG_MAX;
	for (int i = 2; i < M; i++) {
		ll sum = 0, cntall = n;
		for (int j = 0; j < M; j += i) {
			ll r = j + i;
			ll l = max(j + 1, r - wef);
			r = min(M - 1, r);
			l = min(M, l);
			r = max(0LL, r);
			l = max(1LL, l);
			ll cnt = ps[r] - ps[l - 1];
			cntall -= cnt;
			ll sumi = psi[r] - psi[l - 1];
			sum += (cnt * r - sumi) * y;
		}
		sum += cntall * x;
		mn = min(mn, sum);
	}
	cout << mn;
}