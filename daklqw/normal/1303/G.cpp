#include <bits/stdc++.h>

const int MAXN = 150010;
typedef long long LL;
void gma(LL & x, LL y) { x < y ? x = y : 0; }
int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int A[MAXN];
int sz[MAXN], rt, rtv, szall;
int vis[MAXN];
void _getroot(int u, int f) {
	sz[u] = 1;
	int ma = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f && !vis[to[i]]) {
			_getroot(to[i], u);
			sz[u] += sz[to[i]];
			ma = std::max(ma, sz[to[i]]);
		}
	ma = std::max(ma, szall - sz[u]);
	if (ma < rtv) rtv = ma, rt = u;
}

int getroot(int u) {
	_getroot(u, 0);
	szall = sz[u];
	rt = u, rtv = 0x3f3f3f3f;
	_getroot(u, 0);
	return rt;
}
typedef long double db;
struct _ {
	LL x, y;
	bool operator < (_ b) {
		return x == b.x ? y < b.y : x < b.x;
	}
	bool operator ^ (_ b) const {
		return (db) x * b.y - (db) y * b.x < 0;
	}
	LL operator () (_ b) const {
		return x * b.x + y + b.y;
	}
	_ operator - (_ b) const {
		return (_) {x - b.x, y - b.y};
	}
} ;
typedef std::vector<_> VI;

void dfs(int u, int f, int d, LL s, LL v1, LL v2, VI & in, VI & out) {
	in.push_back((_) {s, v1});
	out.push_back((_) {d, v2});
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f && !vis[to[i]]) {
			dfs(to[i], u, d + 1, s + A[to[i]],
				v1 + (d + 1ll) * A[to[i]],
				v2 + s + A[to[i]], in, out);
		}
}

LL ans = 0;
typedef std::vector<VI>::iterator IT;
void calc(VI a, VI b) {
	int cur = 0;
	for (auto t : a) {
		while (cur + 1 < (int) b.size()) {
			if (b[cur](t) <= b[cur + 1](t)) ++cur;
			else break;
		}
		gma(ans, b[cur](t));
	}
}
bool cross(_ a, _ b, _ c) {
	return (b - a) ^ (c - a);
}
VI merge(VI a, VI b, bool convex = true) {
	int lc = 0, rc = 0;
	static _ st[MAXN];
	int top = 0;
	while (lc < (int) a.size() || rc < (int) b.size()) {
		_ t;
		if (lc < (int) a.size() && (rc == (int) b.size() || a[lc] < b[rc]))
			t = a[lc++];
		else
			t = b[rc++];
		if (convex) {
			while (top > 1 && !cross(st[top - 1], st[top], t)) --top;
		}
		st[++top] = t;
	}
	return VI(st + 1, st + 1 + top);
}
std::pair<VI, VI> solve(IT lin, IT rin, IT lout, IT rout) {
	if (lin + 1 == rin)
		return std::make_pair(*lin, *lout);
	IT inm = (rin - lin) / 2 + lin;
	IT outm = (rout - lout) / 2 + lout;
	auto lhs = solve(lin, inm, lout, outm);
	auto rhs = solve(inm, rin, outm, rout);
	calc(lhs.first, rhs.second);
	calc(rhs.first, lhs.second);
	return std::make_pair(
			merge(lhs.first, rhs.first, false),
			merge(lhs.second, rhs.second)
			);
}
void solve(int u) {
	gma(ans, A[u]);
	vis[u] = true;
	std::vector<VI> din, dout;
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]]) {
			VI in, out;
			dfs(to[i], u, 1, A[to[i]], A[to[i]], A[to[i]], in, out);
			for (auto & t : in) {
				t.y += t.x + A[u];
				t.x += A[u];
			}
			std::sort(in.begin(), in.end());
			std::sort(out.begin(), out.end());
			din.push_back(in);
			dout.push_back(merge(out, VI()));
		}
	din.push_back(VI({(_) {A[u], A[u]}}));
	dout.push_back(VI({(_) {0, 0}}));
	if (!din.empty())
	solve(din.begin(), din.end(), dout.begin(), dout.end());
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]])
			solve(getroot(to[i]));
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	solve(getroot(1));
	std::cout << ans << std::endl;
	return 0;
}