#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long double db;
const db eps = 1e-8;
bool le(db a, db b) { return a + eps < b; }
bool ge(db a, db b) { return a - eps > b; }
bool leq(db a, db b) { return a - eps <= b; }
bool geq(db a, db b) { return a + eps >= b; }
bool eq(db a, db b) { return a <= b + eps && b <= a + eps; }

typedef long long LL;
typedef LL VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	db operator ^ (vec b) const { return (db) x * b.y - (db) y * b.x; }
	VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	LL operator () (int at) { return x * at + y; }
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec & x) {
		out << '(' << x.x << ' ' << x.y << ')';
		return out;
	}

} ;
typedef std::vector<vec> VP;
inline db cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
VP convexhull(VP x) {
	std::sort(x.begin(), x.end());
	static vec st[MAXN * 100]; int top = 0;
	for (auto t : x) {
		while (top > 1 && geq(cross(st[top - 1], st[top], t), 0)) --top;
		st[++top] = t;
	}
	return VP(st + 1, st + 1 + top);
}
VP convexmerge(const VP & x, const VP & y) {
	assert(!x.empty() && !y.empty());
	VP res; res.push_back(x[0] + y[0]);
	const int sx = x.size(), sy = y.size();
	int cx = 0, cy = 0;
	while (cx + 1 < sx && cy + 1 < sy) {
		while (cx + 1 < sx && leq((x[cx + 1] - x[cx]) ^ (y[cy + 1] - y[cy]), 0))
			res.push_back(x[++cx] + y[cy]);
		while (cy + 1 < sy && geq((x[cx + 1] - x[cx]) ^ (y[cy + 1] - y[cy]), 0))
			res.push_back(x[cx] + y[++cy]);
	}
	while (cx + 1 < sx) res.push_back(x[++cx] + y[cy]);
	while (cy + 1 < sy) res.push_back(x[cx] + y[++cy]);
	return res;
}
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
vec val[MAXN << 2];
void adde(int b, int e, vec v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
int n, m;
int sz[MAXN], rt, rtv, sznow;
bool vis[MAXN];
void getroot(int u, int fa = 0) {
	int maxv = 0; sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa && !vis[to[i]]) {
			getroot(to[i], u);
			sz[u] += sz[to[i]];
			maxv = std::max(maxv, sz[to[i]]);
		}
	maxv = std::max(maxv, sznow - sz[u]);
	if (maxv < rtv) rtv = maxv, rt = u;
}
void init(int sz) { rtv = 0x3f3f3f3f, rt = 0, sznow = sz; }
std::vector<VP> li;
VP now, ans;
void dfs(int u, vec dep, int fa = 0) {
	int hav = false;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa && !vis[to[i]])
			dfs(to[i], dep + val[i], u), hav = true;
	if (!hav) now.push_back(dep);
}
VP solve(int l, int r) {
	if (l + 1 == r) return li[l];
	int mid = l + r >> 1;
	VP lhs = solve(l, mid), rhs = solve(mid, r);
	VP res = convexmerge(lhs, rhs);
	ans.insert(ans.end(), res.begin(), res.end());
	lhs.insert(lhs.end(), rhs.begin(), rhs.end());
	return convexhull(lhs);
}
void divide(int u) {
	vis[u] = true;
	li.push_back(VP({vec(0, 0)}));
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]]) {
			dfs(to[i], val[i]);
			li.push_back(convexhull(now));
			now.clear();
		}
	solve(0, li.size());
	li.clear();
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]]) {
			getroot(to[i]);
			init(sz[to[i]]);
			getroot(to[i]);
			divide(rt);
		}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int b, e; vec x;
		std::cin >> b >> e >> x;
		adde(b, e, x);
	}
	ans.emplace_back(0, 0);
	init(n); getroot(1);
	divide(rt);
	ans = convexhull(ans);
	const int sz = ans.size(); int cur = 0;
	for (int i = 0; i < m; ++i) {
		while (cur + 1 < sz && ans[cur](i) < ans[cur + 1](i)) ++cur;
		std::cout << ans[cur](i) << ' ';
	}
	return 0;
}