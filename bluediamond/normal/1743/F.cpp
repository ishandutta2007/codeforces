#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= M) return a - M;
	if (a < 0) return a + M;
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int add(int a, int b, int c) {
	return add(add(a, b), c);
}

int mul(int a, int b, int c) {
	return mul(mul(a, b), c);
}

int add(int a, int b, int c, int d) {
	return add(add(a, b, c), d);
}

int mul(int a, int b, int c, int d) {
	return mul(mul(a, b, c), d);
}

int add(int a, int b, int c, int d, int e) {
	return add(add(a, b, c, d), e);
}

int mul(int a, int b, int c, int d, int e) {
	return mul(mul(a, b, c, d), e);
}

int add(int a, int b, int c, int d, int e, int f) {
	return add(add(a, b, c, d, e), f);
}

int mul(int a, int b, int c, int d, int e, int f) {
	return mul(mul(a, b, c, d, e), f);
}

int add(int a, int b, int c, int d, int e, int f, int g) {
	return add(add(a, b, c, d, e, f), g);
}

int mul(int a, int b, int c, int d, int e, int f, int g) {
	return mul(mul(a, b, c, d, e, f), g);
}

int add(int a, int b, int c, int d, int e, int f, int g, int h) {
	return add(add(a, b, c, d, e, f, g), h);
}

int mul(int a, int b, int c, int d, int e, int f, int g, int h) {
	return mul(mul(a, b, c, d, e, f, g), h);
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

void dvup(int& a, int b) {
	a = dv(a, b);
}

struct Seg {
	int l, r;
};

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int n, limit = 0;
	cin >> n;
	vector<Seg> segs(n);
	for (auto& seg : segs) {
		cin >> seg.l >> seg.r;
		assert(0 <= seg.l && seg.l <= seg.r);
		limit = max(limit, seg.r);
	}

	vector<int> last(limit + 1, -1);
	set<int> s;
	for (int i = 0; i <= limit; i++) {
		s.insert(i);
	}

	for (int i = n - 1; i >= 1; i--) {
		int l = segs[i].l, r = segs[i].r;
		while (1) {
			auto it = s.lower_bound(l);
			if (it == s.end()) {
				break;
			}
			int x = *it;
			if (x <= r) {
				assert(l <= x && x <= r);
				last[x] = i;
				s.erase(x);
			}
			else {
				break;
			}
		}
	}

	int sol = 0;

	for (int x = 0; x <= limit; x++) {
		int g = 0;
		if (segs[0].l <= x && x <= segs[0].r) {
			g = 1;
		}

		if (g == 0 && last[x] == -1) {
			continue;
		}
		if (last[x] == -1) {
			addup(sol, pw(2, n - 1));
			continue;
		}

		addup(sol, mul(pw(2, n - last[x]), pw(3, last[x] - 1)));
	}

	cout << sol << "\n";



	return 0;
}


/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */