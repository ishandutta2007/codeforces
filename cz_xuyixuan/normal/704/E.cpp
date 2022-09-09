#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 2e4;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct frac {ll x, y; };
ll absll(ll x) {return x >= 0 ? x : -x; }
frac make(int x) {return (frac) {x, 1}; }
frac normal(frac x) {
	ll g = __gcd(absll(x.x), absll(x.y));
	if (x.y < 0) g = -g;
	return (frac) {x.x / g, x.y / g};
}
frac operator + (frac a, frac b) {return normal((frac) {a.x * b.y + a.y * b.x, a.y * b.y}); }
frac operator - (frac a, frac b) {return normal((frac) {a.x * b.y - a.y * b.x, a.y * b.y}); }
frac operator * (frac a, frac b) {return normal((frac) {a.x * b.x, a.y * b.y}); }
frac operator / (frac a, frac b) {return normal((frac) {a.x * b.y, a.y * b.x}); }
bool operator < (frac a, frac b) {return a.x * b.y < b.x * a.y; }
bool operator > (frac a, frac b) {return a.x * b.y > b.x * a.y; }
bool operator <= (frac a, frac b) {return a.x * b.y <= b.x * a.y; }
bool operator >= (frac a, frac b) {return a.x * b.y >= b.x * a.y; }
bool operator == (frac a, frac b) {return a.x * b.y == b.x * a.y; }
int n, m, depth[MAXN], size[MAXN], son[MAXN];
int timer, father[MAXN], dfn[MAXN], up[MAXN];
vector <int> a[MAXN]; double ans;
int lca(int x, int y) {
	while (up[x] != up[y]) {
		if (depth[up[x]] < depth[up[y]]) swap(x, y);
		x = father[up[x]];
	}
	if (depth[x] < depth[y]) return x;
	else return y;
}
frac dist(int x, int y) {
	int z = lca(x, y);
	return (frac) {depth[x] + depth[y] - 2 * depth[z], 1};
}
struct event {frac k, b, l, r; };
frac Timer, Goal;
bool operator < (event a, event b) {
	if (a.k * Timer + a.b == b.k * Timer + b.b) {
		if (a.l == b.l) {
			if (a.r == b.r) return a.k < b.k;
			else return a.r < b.r;
		} else return a.l < b.l;
	} else return a.k * Timer + a.b < b.k * Timer + b.b;
}
multiset <event> st;
bool cmp(pair <event, bool> x, pair <event, bool> y) {
	frac tx = x.second ? x.first.l : x.first.r;
	frac ty = y.second ? y.first.l : y.first.r;
	if (tx == ty) return x.second > y.second;
	else return tx < ty;
}
frac inter(event a, event b) {
	if (a.k == b.k) {
		if (a.b == b.b) return max(a.l, b.l);
		else return make(INF);
	}
	frac res = (b.b - a.b) / (a.k - b.k);
	if (res >= max(a.l, b.l) && res <= min(a.r, b.r)) return res;
	else return make(INF);
}
void work(vector <event> &a) {
	st.clear(), Goal = make(INF);
	vector <pair <event, bool>> b;
	for (auto x : a) {
		b.emplace_back(x, true);
		b.emplace_back(x, false);
	}
	sort(b.begin(), b.end(), cmp);
	for (auto x : b) {
		frac now = x.second ? x.first.l : x.first.r;
		if (now >= Goal) {
			chkmin(ans, 1.0 * Goal.x / Goal.y);
			return;
		}
		Timer = now;
		if (x.second) {
			multiset <event> :: iterator tmp = st.insert(x.first);
			multiset <event> :: iterator pre = tmp, suf = tmp;
			if (pre != st.begin()) {
				pre--;
				chkmin(Goal, inter(*pre, *tmp));
			}
			if (++suf != st.end()) chkmin(Goal, inter(*tmp, *suf));
		} else {
			multiset <event> :: iterator tmp = st.lower_bound(x.first);
			multiset <event> :: iterator pre = tmp, suf = tmp;
			if (++suf != st.end() && pre != st.begin()) {
				pre--;
				chkmin(Goal, inter(*pre, *suf));
			}
			st.erase(tmp);
		}
	}
	chkmin(ans, 1.0 * Goal.x / Goal.y);
}
vector <event> heavy[MAXN], light[MAXN];
void addquery(int x, int y, frac s, frac v) {
	frac t = s + dist(x, y) / v;
	while (up[x] != up[y]) {
		if (depth[up[x]] > depth[up[y]]) {
			int f = up[x];
			heavy[f].push_back((event) {make(0) - v, make(depth[x]) + v * s, s, s + make(depth[x] - depth[f]) / v});
			s = s + make(depth[x] - depth[f]) / v;
			x = up[x], f = father[x];
			light[x].push_back((event) {make(0) - v, make(depth[x]) + v * s, s, s + make(depth[x] - depth[f]) / v});
			s = s + make(depth[x] - depth[f]) / v;
			x = father[x];
		} else {
			int f = up[y];
			heavy[f].push_back((event) {v, make(depth[y]) - v * t, t - make(depth[y] - depth[f]) / v, t});
			t = t - make(depth[y] - depth[f]) / v;
			y = up[y], f = father[y];
			light[y].push_back((event) {v, make(depth[y]) - v * t, t - make(depth[y] - depth[f]) / v, t});
			t = t - make(depth[y] - depth[f]) / v;
			y = father[y];
		}
	}
	int f = up[x];
	if (depth[x] > depth[y]) heavy[f].push_back((event) {make(0) - v, make(depth[x]) + v * s, s, t});
	else heavy[f].push_back((event) {v, make(depth[y]) - v * t, s, t});
}
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	size[pos] = 1, son[pos] = 0;
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos);
			size[pos] += size[x];
			if (size[x] > size[son[pos]]) son[pos] = x;
		}
}
void efs(int pos, int fa, int from) {
	up[pos] = from;
	father[pos] = fa;
	dfn[pos] = ++timer;
	if (son[pos]) efs(son[pos], pos, from);
	for (auto x : a[pos])
		if (x != son[pos] && x != fa)
			efs(x, pos, x);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	efs(1, 0, 1);
	for (int i = 1; i <= m; i++) {
		frac t, v; int x, y;
		read(t.x), t.y = 1;
		read(v.x), v.y = 1;
		read(x), read(y);
		addquery(x, y, t, v);
	}
	ans = INF;
	for (int i = 1; i <= n; i++) {
		work(heavy[i]);
		work(light[i]);
	}
	if (ans >= INF) puts("-1");
	else printf("%.10lf\n", ans);
	return 0;
}