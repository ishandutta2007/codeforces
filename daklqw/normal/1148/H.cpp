#include <bits/stdc++.h>

const int MAXN = 200010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
int Q, T;
class seg {
	int at, v, A[MAXN], tree[MAXN << 2];
	void mdf(int u, int l, int r) {
		if (l == r) return (void) (tree[u] = v);
		int mid = l + r >> 1;
		if (at <= mid) mdf(u << 1, l, mid);
		else mdf(u << 1 | 1, mid + 1, r);
		tree[u] = std::min(tree[u << 1], tree[u << 1 | 1]);
	}
	int _right(int u, int l, int r) {
		if (at <= l) {
			if (tree[u] > v) return INF;
			while (l != r) {
				if (tree[u << 1] <= v) u <<= 1, r = (l + r) / 2;
				else u = u << 1 | 1, l = (l + r) / 2 + 1;
			}
			return l;
		}
		int mid = l + r >> 1, t;
		if (at <= mid && (t = _right(u << 1, l, mid)) != INF)
			return t;
		if ((t = _right(u << 1 | 1, mid + 1, r)) != INF)
			return t;
		return INF;
	}
public:
	void mdf(int x, int y) {
		at = x, v = y, A[at] = v, mdf(1, 0, Q + 1);
	}
	int right(int x, int z) {
		return at = x, v = z, _right(1, 0, Q + 1);
	}
	inline int & operator [] (int x) { return A[x]; }
} lst;
struct itv {
	int l, r, x, y;
	bool operator < (const itv & b) const {
		return y < b.y;
	}
	LL val() { return (r - l + 1ll) * (y - x + 1); }
} ;
std::set<itv> S;
typedef std::vector<itv> VI;
VI hav[MAXN];
std::vector<LL> pre[MAXN];
void del(itv x, int at) {
	S.erase(x);
	if (x.x > at) return ;
	int k = x.y; x.y = at;
	hav[k].push_back(x);
	LL v = pre[k].empty() ? 0 : pre[k].back();
	pre[k].push_back(v + x.val());
}
void append(int at, int v) {
	lst.mdf(v, at);
	itv tp0 = *S.begin();
	if (tp0.y == 0) del(tp0, at - 1), tp0.r = tp0.x = at;
	else tp0 = (itv) {at, at, at, 0};
	S.insert(tp0);
	auto it = S.lower_bound((itv) {0, 0, 0, v});
	if (it == S.end() || it->y != v) return ;
	itv now = *it, nt = *(++it);
	del(now, at - 1);
	int R = now.r;
	while (R >= now.l) {
		int u = lst.right(v, R - 1);
		int L = std::max(lst[u], now.l - 1);
		itv t = (itv) {L + 1, R, at, u};
		if (u == nt.y) {
			del(nt, at - 1);
			assert(L == nt.r);
			t.l = nt.l;
		}
		S.insert(t);
		R = L;
	}
}
typedef const itv & cir;
inline itv red(itv x, int l, int r) {
	x.l = std::max(x.l, l);
	x.y = std::min(x.y, r);
	if (x.l > x.r || x.x > x.y) x.r = x.l - 1;
	return x;
}
auto cmpl = [] (cir a, cir b) { return a.r < b.r; };
auto cmpr = [] (cir a, cir b) { return a.x < b.x; };
auto cmpm = [] (cir a, cir b) { return a.l < b.l; };
LL qry(int at, int K, int l, int r) {
#define lb(X) (std::lower_bound(v.begin(), v.end(), t, X) - v.begin())
	VI & v = hav[K];
	itv t = (itv) {0, l, 0, 0};
	int a = lb(cmpl);
	t = (itv) {0, 0, r + 1, 0};
	int b = lb(cmpr);
	LL res = 0;
	if (a < b) {
	res += red(v[a], l, r).val();
	if (a != b - 1)
		res += red(v[b - 1], l, r).val();
	++a, b -= 2;
	if (a <= b) {
		res += pre[K][b] - pre[K][a - 1];
		if (hav[K][a].l < l) {
			t = (itv) {hav[K][a].l + 1, 0, 0, 0};
			int c = std::min((int) (lb(cmpm) - 1), b);
			if (a <= c)
			res -= (l - hav[K][a].l) * (hav[K][c].y - hav[K][a].x + 1ll);
		}
	}
	}
	auto it = S.lower_bound((itv) {0, 0, 0, K});
	if (it != S.end() && it->y == K)
		t = *it, t.y = at, res += red(t, l, r).val();
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> Q; // >> T;
	S.insert((itv) {0, 0, 0, Q + 12243});
	LL lans = 0;
	for (int opt = 1; opt <= Q; ++opt) {
		int x, l, r, K;
		std::cin >> x >> l >> r >> K;
		x = (x + lans) % (Q + 1);
		K = (K + lans) % (Q + 1);
		l = (l + lans) % opt + 1;
		r = (r + lans) % opt + 1;
		if (l > r) std::swap(l, r);
		append(opt, x);
		std::cout << (lans = qry(opt, K, l, r)) << '\n';
		// lans *= T;
	}
	return 0;
}