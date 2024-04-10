#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll sz = 1 << 18;

ll A[101010], B[101010], S[101010], X[101010];
ll T1[550505], T2[5505050];
ll n;

ll minval(ll l, ll r) {
	ll s = 1e18;
	l += sz; r += sz;
	for (; l <= r; ) {
		if (l & 1) s = min(s, T1[l]);
		if (~r & 1) s = min(s, T1[r]);
		l = l + 1 >> 1; r = r - 1 >> 1;
	}
	return s;
}

ll maxval(ll l, ll r) {
	ll s = -1e18;
	l += sz; r += sz;
	for (; l <= r; ) {
		if (l & 1) s = max(s, T2[l]);
		if (~r & 1) s = max(s, T2[r]);
		l = l + 1 >> 1; r = r - 1 >> 1;
	}
	return s;
}

void tc() {
	ll q, i, l, r;
	cin >> n >> q;
	for (i = 1; i <= n; i++) cin >> A[i];
	for (i = 1; i <= n; i++) {
		cin >> B[i]; A[i] = B[i] - A[i];
		S[i] = S[i - 1] + A[i];
		X[i] = X[i - 1] + max(A[i], 0ll);
	}
	for (i = 0; i <= n; i++) T1[sz + i] = T2[sz + i] = S[i];
	for (i = sz; i >= 1; i--) {
		T1[i] = min(T1[i << 1], T1[i << 1 | 1]);
		T2[i] = max(T2[i << 1], T2[i << 1 | 1]);
	}
	for (; q--; ) {
		cin >> l >> r; l--;
		if (S[l] != S[r] || minval(l, r) < S[r]) cout << "-1\n";
		else cout << maxval(l, r) - S[r] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}