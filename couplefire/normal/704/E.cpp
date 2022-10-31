#include <bits/stdc++.h>

const int N = 100005;
const double eps = 1e-7;

int n, m, head[N], tot;
struct edge { int to, nxt; } e[N << 1];

bool equal(double x, double y) { return std::abs(x - y) < eps; }
bool less(double x, double y) { return y - x > eps; }
bool leq(double x, double y) { return less(x, y) || equal(x, y); }
bool in_range(double t, double l, double r) { return leq(l, t) && leq(t, r); }

void link(int x, int y) {
	e[++tot] = (edge) { y, head[x] }, head[x] = tot;
	e[++tot] = (edge) { x, head[y] }, head[y] = tot;
}

int f[N], size[N], dep[N], son[N], top[N], down[N];

int dfs0(int x) {
	for (int i = head[x]; i; i = e[i].nxt) if (e[i].to != f[x]) {
		dep[e[i].to] = dep[x] + 1, f[e[i].to] = x, size[x] += dfs0(e[i].to);
		if (size[e[i].to] > size[son[x]]) son[x] = e[i].to;
	}
	return ++size[x];
}
void dfs1(int x) {
	if (son[x]) top[son[x]] = top[x], dfs1(son[x]), down[x] = down[son[x]];
	else down[x] = x;
	for (int i = head[x]; i; i = e[i].nxt) if (e[i].to != f[x] && e[i].to != son[x])
		top[e[i].to] = e[i].to, dfs1(e[i].to);
}

struct segment { double appear, disapp; int v, pos; };
std::vector<segment> a[N];

int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) std::swap(x, y);
		y = f[top[y]];
	}
	return dep[x] < dep[y] ? x : y;
}

void solve(int t, int c, int u, int v) {
	int l = lca(u, v), now = t * c, all = dep[u] + dep[v] - dep[l] * 2 + t * c;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			int to = f[top[u]];
			a[top[u]].emplace_back((segment) {
				(double) now / c, (double) (now + dep[u] - dep[to]) / c, c, dep[down[u]] - dep[u]
			});
			now += dep[u] - dep[to], u = to;
		} else {
			int to = f[top[v]];
			a[top[v]].emplace_back((segment) {
				(double) (all - dep[v] + dep[to]) / c, (double) all / c, -c, dep[down[v]] - dep[to]
			});
			all -= dep[v] - dep[to], v = to;
		}
	}
	if (dep[u] < dep[v]) {
		a[top[u]].emplace_back((segment) {
			(double) now / c, (double) (now + dep[v] - dep[u]) / c, -c, dep[down[u]] - dep[u]
		});
	} else {
		a[top[v]].emplace_back((segment) {
			(double) now / c, (double) (now + dep[u] - dep[v]) / c,  c, dep[down[u]] - dep[u]
		});
	}
}

struct event {
	double time; bool type; // 0 : appear, 1 : disappear
	int id;
	bool operator < (const event &rhs) const {
		return equal(time, rhs.time) ? type < rhs.type : time < rhs.time;
	}
} b[N << 1]; int etot = 0;

double near = 1e10, nowtime = 0; int now_p;

double get_pos(int x) {
	auto &p = a[now_p];
	return p[x].pos + p[x].v * (nowtime - p[x].appear);
};

struct cmp { bool operator () (int x, int y) const {
	return get_pos(x) < get_pos(y);
} };

void check(int x, int y) {
	auto &p = a[now_p];
	if (!leq(std::max(p[x].appear, p[y].appear), std::min(p[x].disapp, p[y].disapp))) return;
	double s = p[y].appear * p[y].v - p[x].appear * p[x].v - p[y].pos + p[x].pos;
	if (p[x].v == p[y].v) {
		if (equal(s, 0)) near = std::min(near, std::max(p[x].appear, p[y].appear));
	} else {
		double t = (p[y].appear * p[y].v - p[x].appear * p[x].v - p[y].pos + p[x].pos) / (p[y].v - p[x].v);
		// std::cout << "qaq : " << t << std::endl;
		if (leq(0, t) && in_range(t, p[x].appear, p[x].disapp) && in_range(t, p[y].appear, p[y].disapp))
			near = std::min(near, t);
	}
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, x, y; i < n; ++i)
		std::cin >> x >> y, link(x, y);
	dfs0(1), top[1] = 1, dfs1(1);
	for (int i = 0; i < m; ++i) {
		int t, c, u, v; std::cin >> t >> c >> u >> v, solve(t, c, u, v);
	}
	for (int i = 1; i <= n; ++i) if (i == top[i]) {
		now_p = i;
		auto &p = a[i]; etot = 0;
		for (int j = 0; j < p.size(); ++j) {
			// std::cout << p[j].appear << ' ' << p[j].disapp << ' ' << p[j].v << ' ' << p[j].pos << std::endl;
			b[etot++] = (event) { p[j].appear, 0, j };
			b[etot++] = (event) { p[j].disapp, 1, j };
		}
		std::sort(b, b + etot);
		std::multiset<int, cmp> s;
		for (int j = 0, k; j < etot; j = k) {
			k = j, nowtime = b[j].time;
			if (leq(near, nowtime)) break;
			while (k < etot && equal(b[k].time, nowtime)) {
				if (b[k].type == 0) {
					// std::cout << "insert : " << b[k].id << std::endl;
					auto it = s.insert(b[k].id);
					if (it != s.begin()) check(*std::prev(it), *it);
					auto p = it; ++p;
					if (p != s.end()) check(*it, *p);
				} else {
					// std::cout << "erase : " << b[k].id << std::endl;
					s.erase(b[k].id);
				}
				++k;
			}
		}
	}
	if (near > 1e6)
		std::cout << "-1\n";
	else
		std::cout << std::fixed << std::setprecision(18) << near << '\n';
	return 0;
}