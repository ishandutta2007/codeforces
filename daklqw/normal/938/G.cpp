#include <bits/stdc++.h>

const int MAXN = 400010;
struct E {
	int x, y, v;
	bool operator < (E b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
} es[MAXN];
int bak;
const int MAXQ = MAXN * 30;
int head[MAXN << 2], nxt[MAXQ], to[MAXQ], tot;
void addq(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}
std::map<E, std::pair<int, int> > S;
void modify(int u, int l, int r, int L, int R, int v) {
	// if (u == 1) std::cout << "INSERT " << L << " " << R << " " << es[v].x << " " << es[v].y << " " << es[v].v << std::endl;
	if (L <= l && r <= R) {
		// std::cout << "INS " << u << " " << l << " " << r << " " << v << std::endl;
		return addq(u, v);
	}
	int mid = l + r >> 1;
	if (L <= mid) modify(u << 1, l, mid, L, R, v);
	if (mid < R) modify(u << 1 | 1, mid + 1, r, L, R, v);
}
struct linearbase {
	int a[32];
	linearbase() { memset(a, 0, 128); }
	void insert(int x) {
		for (int i = 31; ~i; --i)
			if (x >> i & 1) {
				if (!a[i]) a[i] = x;
				x ^= a[i];
			}
	}
	int query(int x) {
		for (int i = 31; ~i; --i)
			if ((x ^ a[i]) < x)
				x ^= a[i];
		return x;
	}
} ;
struct his {
	int x, v, r;
} st[MAXN << 1]; int top;
int fa[MAXN], val[MAXN], rnk[MAXN];
int n, m, initm, xs[MAXN], ys[MAXN], tnow = 1;
std::pair<int, int> find(int x) {
	int res = 0;
	while (x != fa[x]) {
		res ^= val[x];
		x = fa[x];
	}
	return std::make_pair(x, res);
}
void merge(int x, int y, int v, linearbase & L) {
	// std::cout << "CONN " << x << " " << y << " " << v << std::endl;
	auto fx = find(x), fy = find(y);
	v ^= fx.second ^ fy.second;
	x = fx.first, y = fy.first;
	if (x == y) {
		// std::cout << "MERGE " << x << " " << y << " INS " << v << std::endl;
		return L.insert(v);
	}
	if (rnk[x] > rnk[y]) std::swap(x, y);
	st[++top] = (his) {x, val[x], rnk[x]};
	fa[x] = y, val[x] = v;
	if (rnk[x] == rnk[y])
		st[++top] = (his) {y, val[y], rnk[y]++};
}
void restore(int hi) {
	while (top > hi) {
		auto t = st[top--];
		fa[t.x] = t.x;
		val[t.x] = t.v;
		rnk[t.x] = t.r;
	}
}
void solve(int u, int l, int r, linearbase now) {
	// std::cout << "SOLVE " << u << " " << l << " " << r << std::endl;
	int cur = top, mid = l + r >> 1;
	for (int i = head[u]; i; i = nxt[i]) {
		auto t = es[to[i]];
		merge(t.x, t.y, t.v, now);
	}
	if (l == r) {
		auto fx = find(xs[l]), fy = find(ys[l]);
		int ans = 0;
		if (fx.first != fy.first) ans = -1;
		else ans = now.query(fx.second ^ fy.second);
		std::cout << ans << '\n';
		if (l >= tnow - 1) exit(0);
	}
	if (l < r) {
		solve(u << 1, l, mid, now);
		solve(u << 1 | 1, mid + 1, r, now);
	}
	restore(cur);
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> initm;
	for (int i = 1, x, y, d; i <= initm; ++i) {
		std::cin >> x >> y >> d; ++bak;
		if (x > y) std::swap(x, y);
		S[es[bak] = (E) {x, y, d}] = std::make_pair(tnow, bak);
	}
	std::cin >> m;
	for (int i = 1, opt, x, y, d; i <= m; ++i) {
		std::cin >> opt >> x >> y;
		if (x > y) std::swap(x, y);
		if (opt == 1) {
			std::cin >> d; ++bak;
			S[es[bak] = (E) {x, y, d}] = std::make_pair(tnow, bak);
		} else if (opt == 2) {
			auto t = S.lower_bound((E) {x, y, 0});
			auto v = t -> second;
			if (tnow > v.first)
				modify(1, 1, m, v.first, tnow - 1, v.second);
			S.erase(t);
		} else {
			xs[tnow] = x, ys[tnow] = y;
			++tnow;
		}
	}
	for (auto t : S) {
		auto v = t.second;
		if (tnow > v.first)
			modify(1, 1, m, v.first, tnow - 1, v.second);
	}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	if (tnow > 1) solve(1, 1, m, linearbase());
	return 0;
}