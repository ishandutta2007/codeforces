//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'
#define y1 _y1

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct frac {
	int x, y;
	frac() {}
	frac(int _x, int _y = 1) { 
		x = _x, y = _y;
		int g = __gcd(abs(x), abs(y));
		if (y < 0) g = -g;
		x /= g, y /= g;
	}
} T, Ans = INF;

frac operator + (frac a, frac b) {return frac(a.x * b.y + a.y * b.x, a.y * b.y);}
frac operator - (frac a, frac b) {return frac(a.x * b.y - a.y * b.x, a.y * b.y);}
frac operator * (frac a, frac b) {return frac(a.x * b.x, a.y * b.y);}
frac operator / (frac a, frac b) {return frac(a.x * b.y, a.y * b.x);}
frac operator - (frac a) {return 0 - a;}
bool operator < (frac a, frac b) {return a.x * b.y < b.x * a.y;}
bool operator > (frac a, frac b) {return a.x * b.y > b.x * a.y;}
bool operator <= (frac a, frac b) {return a.x * b.y <= b.x * a.y;}
bool operator >= (frac a, frac b) {return a.x * b.y >= b.x * a.y;}
bool operator == (frac a, frac b) {return a.x * b.y == b.x * a.y;}

struct NODE {
	frac k, b, L, R;
	NODE(frac _k, frac _b, frac _L, frac _R) : k(_k), b(_b), L(_L), R(_R) {}
};

bool operator < (NODE x, NODE y) {
	if(x.k * T + x.b == y.k * T + y.b)
		return x.L == y.L ? (x.R == y.R ? x.k < y.k : x.R < y.R) : x.L < y.L;
	return x.k * T + x.b < y.k * T + y.b;
}

int n, m;
int top[MAXN], siz[MAXN], son[MAXN], dep[MAXN], fa[MAXN];
multiset<NODE> S;
vec<int> G[MAXN];
vec<pair<NODE, bool>> opt;
vec<NODE> up[MAXN], dn[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

frac calc(NODE a, NODE b) {
	if(a.k == b.k) return a.b == b.b ? max(a.L, b.L) : INF;
	frac res = (a.b - b.b) / (b.k - a.k);
	if(max(a.L, b.L) <= res && res <= min(a.R, b.R)) return res;
	return INF;
}

bool cmp(pair<NODE, bool> a, pair<NODE, bool> b) {
	frac x, y; 
	x = a.scd ? a.fst.R : a.fst.L, y = b.scd ? b.fst.R : b.fst.L;
	return x == y ? a.scd < b.scd : x < y;
}

void DFS1(int x, int f) {
	fa[x] = f, dep[x] = dep[f] + 1, siz[x] = 1, son[x] = 0;
	for(auto to : G[x]) {
		if(to == fa[x]) continue;
		DFS1(to, x);
		siz[x] += siz[to];
		if(!son[x] || siz[son[x]] < siz[to]) son[x] = to;
	}
}

void DFS2(int x, int tp) {
	top[x] = tp;
	if(son[x]) DFS2(son[x], tp);
	for(auto to : G[x]) {
		if(to == son[x] || to == fa[x]) continue;
		DFS2(to, to);
	}
}

int LCA(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int dis(int x, int y) {return dep[x] + dep[y] - (dep[LCA(x, y)] << 1);}

void init(int x, int y, frac s, frac v) {
	frac t = s + dis(x, y) / v;
	while(top[x] != top[y]) {
		if(dep[top[x]] > dep[top[y]]) {
			up[top[x]].pb(NODE(-v, dep[x] + v * s, s, s + (dep[x] - dep[top[x]]) / v));
			s = s + (dep[x] - dep[top[x]]) / v; x = top[x];
			dn[x].pb(NODE(-v, dep[x] + v * s, s, s + (dep[x] - dep[fa[x]]) / v));
			s = s + (dep[x] - dep[fa[x]]) / v; x = fa[x];
		} else {
			up[top[y]].pb(NODE(v, dep[y] - v * t, t - (dep[y] - dep[top[y]]) / v, t));
			t = t - (dep[y] - dep[top[y]]) / v; y = top[y];
			dn[y].pb(NODE(v, dep[y] - v * t, t - (dep[y] - dep[fa[y]]) / v, t));
			t = t - (dep[y] - dep[fa[y]]) / v; y = fa[y];
		}
	}
	if(dep[x] > dep[y]) up[top[x]].pb(NODE(-v, dep[x] + v * s, s, t));
	else up[top[x]].pb(NODE(v, dep[y] - v * t, s, t));
}

void solve(vec<NODE> V) {
	opt.clear(); S.clear();
	for(auto v : V) opt.pb(mp(v, 0)), opt.pb(mp(v, 1));
	sort(opt.begin(), opt.end(), cmp);
	for(auto v : opt) {
		frac cur = v.scd ? v.fst.R : v.fst.L;
		if(cur >= Ans) break;
		T = cur;
		if(v.scd == 0) { // L
			auto it = S.insert(v.fst), tmp = it;
			if(tmp != S.begin()) Ans = min(Ans, calc(*(--tmp), *it));
			tmp = it;
			if((++tmp) != S.end()) Ans = min(Ans, calc(*tmp, *it)); 
		} else { // R
			auto it = S.lower_bound(v.fst), pre = it, suf = it;
			if((++suf) != S.end() && pre != S.begin()) Ans = min(Ans, calc(*suf, *(--pre)));
			S.erase(it);
		}
	}
}

signed main () {
#ifdef FILE
	freopen("CF704E.in", "r", stdin);
	freopen("CF704E.out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	DFS1(1, 0), DFS2(1, 1);
	for(int i = 1, a, b, s, t; i <= m; ++i) {
		read(s), read(t), read(a), read(b);
		init(a, b, s, t);
	}
	for(int i = 1; i <= n; ++i) 
		solve(dn[i]), solve(up[i]);
	if(Ans == INF) puts("-1");
	else printf("%.10lf\n", 1. * Ans.x / Ans.y);
	return 0;
}