#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using plll = tuple<ll, ll, ll>;

struct rmq {
	pll T[550505];
	int sz = 1 << 18;

	void init(ll n, ll *A) {
		int i;
		for (i = 0; i < n; i++) {
			T[sz + i] = pll(A[i], i);
		}
		for (i = sz - 1; i; i--) {
			T[i] = max(T[i << 1], T[i << 1 | 1]);
		}
	}

	pll query(ll l, ll r) {
		pll ret(0, 0);
		for (l += sz, r += sz; l <= r; ){
			if (l & 1) ret = max(ret, T[l]);
			if (~r & 1) ret = max(ret, T[r]);
			l = l + 1 >> 1; r = r - 1 >> 1;
		}
		return ret;
	}
} RMQ;

struct segtree {
	ll T[550505];
	ll sz = 1 << 18;

	void add(ll l, ll r, ll v) {
		for (l += sz, r += sz; l <= r; ) {
			if (l & 1) T[l] += v;
			if (~r & 1) T[r] += v;
			l = l + 1 >> 1; r = r - 1 >> 1;
		}
	}

	ll get(ll i) {
		ll s = 0;
		for (i += sz; i; i >>= 1) {
			s += T[i];
		}
		return s;
	}
} L, R;

set <ll> S;
vector <plll> V[202020];
ll A[202020], B[202020], P[202020], Z[202020];
ll n, q;

void add(ll l, ll r, ll t) {
	V[RMQ.query(l, r).second].emplace_back(l, r, t);
}

void dnc(ll l, ll r) {
	if (l > r) return;
	int m = RMQ.query(l, r).second;
	dnc(l, m - 1); dnc(m + 1, r);

	for (auto &[s, e, t]: V[m]) {
		ll v = R.get(s) + L.get(e);
		if (e > m) v += A[m];
		//cout << s << " " << e << " " << t << ": " << v << endl;
		if (t < 0) Z[-t] -= v;
		else Z[t] += v;
	}

	ll ml = R.get(l);
	ll mr = min(A[m] + R.get(m + 1), B[m]);

	ll lv = ml + A[m];
	ll rv = mr;

	L.add(m, m, ml);
	R.add(m, m, mr);
	L.add(m + 1, r, lv);
	R.add(l, m - 1, rv);

	// cout << "<" << l << " " << r << ">" << ": " << ml << " " << mr << endl;
	// for (int i = l; i <= r; i++) {
	// 	cout << L.get(i) << " / " << R.get(i) << ", ";
	// }
	// cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i, x;

	cin >> n >> q;

	P[0] = n + 1; P[n + 1] = n + 2;
	for (i = 1; i <= n; i++) {
		cin >> P[i];
	}
	for (i = 1; i <= n; i++) {
		cin >> A[i];	
	}
	for (i = 1; i <= n; i++) {
		cin >> B[i];
	}

	n += 2;

	RMQ.init(n, P);

	add(0, n - 1, 0);

	S.insert(0); S.insert(n - 1);
	for (i = 1; i <= q; i++) {
		cin >> x;
		auto it = S.lower_bound(x);
		if (it == S.end() || *it != x) {
			add(*prev(it), *it, -i);
			add(*prev(it), x, i);
			add(x, *it, i);
			S.insert(x);
		}
		else {
			add(*prev(it), x, -i);
			add(x, *next(it), -i);
			add(*prev(it), *next(it), i);
			S.erase(it);
		}
	}

	dnc(0, n - 1);

	for (i = 1; i <= q; i++) {
		Z[i] += Z[i - 1];
		cout << Z[i] << "\n";
	}

	return 0;
}