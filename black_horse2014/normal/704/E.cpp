#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 110000;
int n;
vector<int> adj[N], dis[N];
int anc[N][18];
int par[N], dp[N], sz[N];
int fst[N], st[N], T;

struct FR {
	LL a, b;
	FR() : a(0), b(1) {}
	FR(LL x) : a(x), b(1) {}
	FR(LL x, LL y) {
		LL g = __gcd(x, y);
		x /= g, y /= g;
		if (y < 0) x = -x, y = -y;
		a = x, b = y;
	}
	bool operator<(const FR &that) const {
		return (long long)a * that.b < (long long)that.a * b;
	}
	bool operator>(const FR &that) const {
		return (long long)a * that.b > (long long)that.a * b;
	}
	bool operator==(const FR &that) const {
		return (long long)a * that.b == (long long)that.a * b;
	}
	bool operator<=(const FR &that) const {
		return !(that < *this);
	}
	bool operator>=(const FR &that) const {
		return !(*this < that);
	}
	FR operator+(const FR &that) const {
		return FR(a * that.b + that.a * b, b * that.b);
	}
	FR operator-(const FR &that) const {
		return FR(a * that.b - that.a * b, b * that.b);
	}
	FR operator*(const FR &that) const {
		return FR(a * that.a, b * that.b);
	}
	FR operator/(const FR &that) const {
		return FR(a * that.b, b * that.a);
	}
	double toDouble() const {
		return (double)a / b;
	}
};

int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	for (int i = 17; i >= 0; i--) {
		if (dp[anc[u][i]] < dp[v]) continue;
		u = anc[u][i];
		if (dp[u] == dp[v]) break;
	}
	if (u == v) return u;
	for (int i = 17; i >= 0; i--) {
		if (anc[u][i] == anc[v][i]) continue;
		u = anc[u][i], v = anc[v][i];
	}
	return anc[u][0];
}

inline void dfs(int u, int r) {
	par[u] = r;
	dp[u] = dp[r] + 1;
	sz[u] = 1;
	anc[u][0] = r;
	for (int i = 1; i <= 17; i++) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == r) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

inline void hld(int u, int hd) {
	fst[u] = hd, st[u] = ++T;
	if (adj[u].empty()) return;
	int w = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == par[u]) continue;
		if (sz[w] < sz[v]) w = v;
	}
	if (w) hld(w, hd);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == par[u]) continue; 
		if (v != w) ++T, hld(v, v);
	}
}

int p[N];

struct data{
	FR t, c;
	int u, v;
	int dir;
	data(FR t = FR(), FR c = FR(), int u = 0, int v = 0, int dir = 0) : t(t), c(c), u(u), v(v), dir(dir) {}
	void in() {
		int _t, _c;
		scanf("%d%d%d%d", &_t, &_c, &u, &v);
		t = FR(_t), c = FR(_c);
	}
} D[N];

vector<data> E;

void insert(data d) {
	FR t = d.t, c = d.c;
	int u = d.u, v = d.v;
	int flg = 0;
	if (dp[u] < dp[v]) swap(u, v), flg = 1;
	if (fst[u] == fst[v]) {
		E.push_back(data(t, c, st[v] + 1, st[u], !flg));
		return;
	}
	if (dp[fst[u]] < dp[fst[v]]) swap(u, v), flg ^= 1;
	FR t1 = t;
	FR dis = dp[u] + dp[v] - 2 * dp[lca(u, v)];
	if (flg) t1 = t + (dis - FR(st[u] - st[fst[u]] + 1)) / c;
	E.push_back(data(t1, c, st[fst[u]], st[u], !flg));
	if (flg) insert(data(t, c, v, par[fst[u]]));
	else insert(data(t + FR(st[u] - st[fst[u]] + 1) / c, c, par[fst[u]], v));
}

static const int INF = 0x3f3f3f3f;

struct PT {
	FR x, y;
	PT() {}
	PT(FR x, FR y) : x(x), y(y) {}
};

struct Segment {
	static FR curX;
	FR slope, intercept;
	FR xL, xR;
	Segment(FR slope, FR intercept, FR xL, FR xR) : slope(slope), intercept(intercept), xL(xL), xR(xR) {}
	Segment(PT A, PT B) {
		if (A.x > B.x) swap(A, B);
		xL = A.x, xR = B.x;
		if (xL == xR) {
			intercept = A.y;
			slope = 0;
		} else {
			slope = (B.y - A.y) / (xR - xL);
			intercept = A.y - A.x * slope;
		}
	}
	FR getY(const FR &x) const {
		return intercept + slope * x;
	}
	pair<PT, PT> getPoints() {
		return make_pair(PT(xL, getY(xL)), PT(xR, getY(xR)));
	}
	bool operator<(const Segment &that) const {
		FR y0 = getY(curX);
		FR y1 = that.getY(curX);
		return y0 < y1;
	}
	bool isIntersectTo(const Segment &that, FR &crossX) const {
		if(slope == that.slope) {
			if(intercept == that.intercept) {
				crossX = max(xL, that.xL);
				return !(xR < that.xL) && !(that.xR < xL);
			} else {
				return false;
			}
		} else {
			crossX = (intercept - that.intercept) / (that.slope - slope);
			return xL <= crossX && crossX <= xR && that.xL <= crossX && crossX <= that.xR;
		}
	}
};
FR Segment::curX;

PT solve(const vector<Segment> &segments) {
	if(segments.empty()) return PT(FR(INF), FR(INF));
	int n = (int)segments.size();
	vector<pair<FR, int>> events; 
	for (int i = 0; i < n; i++) {
		const Segment &s = segments[i];
		assert(!(s.xR < s.xL));
		events.emplace_back(s.xL, i);
		events.emplace_back(s.xR, n + i);
	}
	sort(events.begin(), events.end());
	multiset<Segment> ss;
	vector<decltype(ss.begin())> iters(n);
	FR minX(INF), minY;
	
	auto check = [&minX, &minY](const Segment &s, const Segment &t) {
		FR crossX;
		if(s.isIntersectTo(t, crossX)) {
			if (crossX < minX) minX = crossX, minY = s.getY(crossX);
		}
	};

	for(const auto &e : events) {
		if(!(e.first < minX)) break;
		Segment::curX = e.first;
		if(e.second < n) {
			int i = e.second;
			const Segment &s = segments[i];
			auto it = ss.lower_bound(s);
			if(it != ss.end()) check(*it, s);
			if(it != ss.begin()) --it, check(*it, s);
			if(!(e.first < minX)) break;
			iters[i] = ss.insert(it, segments[i]);
  		} else {
			int i = e.second - n;
			auto it = iters[i];
			it = ss.erase(it);
			if(it != ss.end() && it != ss.begin()) {
				const Segment &s = *it;
				--it;
				check(*it, s);
			}
		}
	}
	return PT(minX, minY);
}

int main() {
	int m; scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; i++) D[i].in();
	dfs(1, 0);
	hld(1, 1);
	for (int i = 0; i < m; i++) insert(D[i]);
	
	vector<Segment> vec;
	while (E.size()) {
		data d = E.back();
		E.pop_back();
		if (!d.dir) {
			vec.push_back(Segment(PT(d.t, FR(d.u - 1)), PT(d.t + FR(d.v - d.u + 1) / d.c, FR(d.v))));
		} else {
			vec.push_back(Segment(PT(d.t, FR(d.v)), PT(d.t + FR(d.v - d.u + 1) / d.c, FR(d.u - 1))));
		}
	}
	PT ret = solve(vec);
	double ans = ret.x.toDouble();
	if (fabs(ans - INF) < 1e-8) puts("-1");
	else printf("%.10lf\n", ans);
}/*123123456*/