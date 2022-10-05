#include<bits/stdc++.h>
#define rint register int
#define rep(i,a,b) for (rint i=(a),_E=(b); i<=_E; ++i)
#define per(i,a,b) for (rint i=(a),_E=(b); i>=_E; --i)
#define REP(i,n) for (rint i=(0),_E=(n); i<_E; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

inline int read() {
	char ch = getchar(); int x = 0;
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
#define _(x) (x = read())

const int N = 100005;
const int M = 505;
struct Block {
	int c[N], tot; vi v;
	inline void init(int x[], int n) {
		v.resize(tot = n);
		REP (i, n) v[i] = x[i+1], ++c[v[i]];
	}
	inline void print(int x[], int &cnt) {
		REP (i, tot) x[++cnt] = v[i], --c[v[i]];
	}
	inline int del(int r) {
		int res = v[r-1]; --c[res], --tot;
		v.erase(v.begin() + r - 1);
		return res;
	}
	inline void ins(int r, int x) {
		v.insert(v.begin() + r - 1, x); ++c[x], ++tot;
	}
	inline int qry(int l, int r, int k) {
		int res = 0;
		rep (i, l - 1, r - 1) res += (v[i] == k);
		return res;
	}
} a[M];
int x[N], n, m, T, TT, C, op, l, r, t, ans;

void rebuild() {
	int cnt = 0;
	rep (i, 1, C) a[i].print(x, cnt);
	rep (i, 1, C) a[i].init(x + (i - 1) * T, (i == C ? n - (i - 1) * T : T));
}

void reverse() {
	_(l), _(r);
	l = (l + ans - 1) % n + 1;
	r = (r + ans - 1) % n + 1;
	if (l > r) swap(l, r);
	if (l == r) return;
	int base = 0, val;
	rep (i, 1, C)
		if (base + a[i].tot < r) base += a[i].tot;
		else { val = a[i].del(r - base); break; }
	base = 0;
	rep (i, 1, C)
		if (base + a[i].tot < l) base += a[i].tot;
		else { a[i].ins(l - base, val); break; }
}

void query() {
	int base = 0, L, R;
	_(l), _(r), _(t);
	l = (l + ans - 1) % n + 1;
	r = (r + ans - 1) % n + 1;
	if (l > r) swap(l, r);
	t = (t + ans - 1) % n + 1;
	ans = 0;
	rep (i, 1, C) {
		L = base + 1; R = base + a[i].tot;
		if (l <= L && R <= r) ans += a[i].c[t];
		else if (l <= R && L <= r)
			ans += a[i].qry(max(1, l - base), min(a[i].tot, r - base), t);
		base += a[i].tot;
		if (r <= base) break;
	}
	printf("%d\n", ans);
}

int main() {
	_(n);
	if (!n) return 0;
	T = 500; TT = 3000;
	C = (n + T - 1) / T;
	rep (i, 1, n) _(x[i]);
	_(m);
	rep (i, 1, C) a[i].init(x + (i - 1) * T, (i == C ? n - (i - 1) * T : T));
	while (m--) {
		read() == 1? reverse() : query();
		if (m % TT == 0) rebuild();
	}
	return 0;
}