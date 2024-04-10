#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
void exgcd(int a, int b, int & x, int & y) {
	if (!b) { x = 1, y = 0; }
	else {
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
}
int inv(int x) {
	int a, b;
	exgcd(x, mod, a, b);
	a += a >> 31 & mod;
	return a;
}
int li[11], bak;
void factor() {
	int t = mod;
	for (int i = 2; i * i <= t; ++i)
		if (t % i == 0) {
			li[bak++] = i;
			while (t % i == 0) t /= i;
		}
	if (t > 1) li[bak++] = t;
}
struct num {
	int pw[11], sl, vx;
	num() {
		memset(pw, 0, 44);
		vx = sl = 1;
	}
	num(int x) {
		memset(pw, 0, 44);
		vx = x % mod;
		for (int i = 0; i < bak; ++i)
			if (x % li[i] == 0) {
				while (x % li[i] == 0)
					++pw[i], x /= li[i];
			}
		sl = x % mod;
	}
	num operator ~() {
		num r = *this;
		for (int i = 0; i < bak; ++i)
			r.pw[i] = -r.pw[i];
		r.sl = inv(r.sl);
		return r;
	}
	int val() {
		int res = sl;
		for (int i = 0; i < bak; ++i) {
			res = pow(li[i], pw[i], res);
		}
		return res;
	}
	friend num operator + (num a, num b) {
		for (int i = 0; i < bak; ++i) a.pw[i] += b.pw[i];
		a.sl = mul(a.sl, b.sl);
		a.vx = mul(a.vx, b.vx);
		return a;
	}
} tag[MAXN << 2];
bool hav[MAXN << 2];
int sm[MAXN << 2];
void mkmul(int u, num x) {
	tag[u] = tag[u] + x;
	hav[u] = true;
	sm[u] = mul(sm[u], x.vx);
}
void pushdown(int u) {
	if (hav[u]) {
		mkmul(u << 1, tag[u]);
		mkmul(u << 1 | 1, tag[u]);
		tag[u] = num();
		hav[u] = false;
	}
}
void add(int u, int l, int r, int L, int R, num x) {
	if (L <= l && r <= R) return mkmul(u, x);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) add(u << 1, l, mid, L, R, x);
	if (mid < R) add(u << 1 | 1, mid + 1, r, L, R, x);
	reduce(sm[u] = sm[u << 1] + sm[u << 1 | 1] - mod);
}
void div(int u, int l, int r, int tar, int x) {
	if (l == r) {
		tag[u] = tag[u] + (~num(x));
		sm[u] = tag[u].val();
		return ;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (tar <= mid) div(u << 1, l, mid, tar, x);
	else div(u << 1 | 1, mid + 1, r, tar, x);
	reduce(sm[u] = sm[u << 1] + sm[u << 1 | 1] - mod);
}
int qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sm[u];
	int mid = l + r >> 1, res = 0;
	pushdown(u);
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) reduce(res += qry(u << 1 | 1, mid + 1, r, L, R) - mod);
	return res;
}
int A[MAXN];
void build(int u, int l, int r) {
	if (l == r) {
		sm[u] = (tag[u] = num(A[l])).vx;
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	reduce(sm[u] = sm[u << 1] + sm[u << 1 | 1] - mod);
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> mod;
	factor();
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	build(1, 1, n);
	int Q; std::cin >> Q;
	while (Q --> 0) {
		int opt, l, r, x, p;
		std::cin >> opt;
		if (opt == 1) {
			std::cin >> l >> r >> x;
			add(1, 1, n, l, r, num(x));
		} else if (opt == 2) {
			std::cin >> p >> x;
			div(1, 1, n, p, x);
		} else {
			std::cin >> l >> r;
			std::cout << qry(1, 1, n, l, r) << '\n';
		}
	}
	return 0;
}