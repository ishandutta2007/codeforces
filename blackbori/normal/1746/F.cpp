#include <bits/stdc++.h>

using namespace std;
using ll = long long;

random_device rd;
mt19937 rng(rd());

const ll M = 30;

ll n;

struct fenwick {
	ll T[303030];
	void add(ll i, ll x) {
		for (; i <= n; i += i & -i) {
			T[i] += x;
		}
	}
	ll sum(ll i) {
		ll s = 0;
		for (; i; i -= i & -i) {
			s += T[i];
		}
		return s;
	}
} F[M];

map<ll, ll> S;
ll m;
ll A[303030], D[606060][M];

void upd(ll i, ll x) {
	ll j;
	if (S.find(x) == S.end()) {
		S[x] = ++m;
		for (j = 0; j < M; j++) {
			D[m][j] = rng();
		}
	}
	x = S[x];

	if (A[i]) {
		for (j = 0; j < M; j++) {
			F[j].add(i, -D[A[i]][j]);
		}
	}
	{
		A[i] = x;
		for (j = 0; j < M; j++) {
			F[j].add(i, D[x][j]);
		}
	}
}

bool query(ll l, ll r, ll k) {
	ll i, t;
	for (i = 0; i < M; i++) {
		t = F[i].sum(r) - F[i].sum(l - 1);
		if (t % k) return 0;
	}
	return 1;
}

void tc() {
	ll i, x, t, j, l, r, k, q;
	cin >> n >> q;
	for (i = 1; i <= n; i++) {
		cin >> x; upd(i, x);
	}

	for (i = 1; i <= q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> j >> x;
			upd(j, x);
		}
		else {
			cin >> l >> r >> k;
			cout << (query(l, r, k) ? "YES" : "NO") << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	// cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}