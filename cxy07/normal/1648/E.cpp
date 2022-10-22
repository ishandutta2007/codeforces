//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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

const int MAXN = (1 << 19) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN << 1], to[MAXN << 1], w[MAXN << 1];
	void add(int x, int y, int _w) {
		//cout << x << ' ' << y << ' ' << _w << endl;
		nxt[++siz] = head[x]; to[siz] = y, w[siz] = _w, head[x] = siz;
	}
} e, AnsT;

struct E2 {
	int x, y, w, id;
	E2(int _x = 0, int _y = 0, int _w = 0, int _i = 0) : x(_x), y(_y), w(_w), id(_i) {}
	bool operator < (const E2 &b) const { return w < b.w; }
} es[MAXN], link[MAXN];

int TestCase, n, m, ncnt, Ans[MAXN];
int dsu[MAXN], W[MAXN], dfn[MAXN], idfn[MAXN], dfnc;
int dep[MAXN], jump[MAXN][18], maxw[MAXN][18];
int hvy[MAXN], top[MAXN], siz[MAXN], fa[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct SGT {
	int M = 1, c[MAXN << 1][2];
	void Init() { 
		M = 1; while(M < n) M <<= 1; 
		for(int i = 1; i <= (M << 1); ++i) c[i][0] = c[i][1] = 0;
	}
	void add(int x, int v) {
		if(!v) return;
		if(!c[x][0]) c[x][0] = v;
		else if(c[x][0] != v) c[x][1] = v;
	}
	void pushup(int x) {
		c[x][0] = c[x][1] = 0;
		add(x, c[x << 1][0]), add(x, c[x << 1][1]);
		add(x, c[x << 1 | 1][0]), add(x, c[x << 1 | 1][1]);
	}
	void update(int p, int v) {
		p += M; c[p][0] = v, c[p][1] = 0;
		while(p > 1) pushup(p >>= 1);
	}
	bool chk(int x, int v) { return (c[x][0] && c[x][0] != v) || (c[x][1] && c[x][1] != v); }
	int query_pre(int p, int v) {
		if(p < 1 || p > n) return -1;
		for(p = p + M + 1; p ^ 1; p >>= 1)
			if((p & 1) && chk(p ^ 1, v)) { p ^= 1; break; }
		if(!chk(p, v)) return -1;
		for(; p <= M; ) p = (p << 1 | chk(p << 1 | 1, v));
		return idfn[p - M];
	}
	int query_nxt(int p, int v) {
		if(p < 1 || p > n) return -1;
		for(p = p + M - 1; p ^ 1; p >>= 1)
			if(((~p) & 1) && chk(p ^ 1, v)) { p ^= 1; break; }
		if(!chk(p, v)) return -1;
		for(; p <= M; ) p = (p << 1 | (!chk(p << 1, v)));
		return idfn[p - M];
	}
} T;

int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }
void unity(int x, int y) { x = find(x), y = find(y); if(x != y) dsu[x] = y; }

void DFS0(int x, int f) {
	dep[x] = dep[f] + 1, siz[x] = 1, hvy[x] = 0, fa[x] = f;
	if(x <= n) idfn[dfn[x] = ++dfnc] = x;
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i]; DFS0(to, x); siz[x] += siz[to]; 
		if(!hvy[x] || siz[hvy[x]] < siz[to]) hvy[x] = to;
	}
}

void DFS1(int x, int tp) {
	top[x] = tp;
	if(hvy[x]) DFS1(hvy[x], tp);
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i]; if(to == fa[x] || to == hvy[x]) continue;
		DFS1(to, to);
	}
}
 
void DFS2(int x, int f) {
	jump[x][0] = f, dep[x] = dep[f] + 1;
	for(int i = 1; i <= 17; ++i) {
		jump[x][i] = jump[jump[x][i - 1]][i - 1];
		maxw[x][i] = max(maxw[x][i - 1], maxw[jump[x][i - 1]][i - 1]);
	}
	for(int i = AnsT.head[x], to; i; i = AnsT.nxt[i]) {
		to = AnsT.to[i]; if(to == f) continue;
		maxw[to][0] = AnsT.w[i]; DFS2(to, x);
	}
}
 
int LCA(int x, int y) {
	while(top[x] ^ top[y]) {
		if(dep[top[x]] < dep[top[y]]) y = fa[top[y]];
		else x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
 
int LCA2(int x, int y) {
	int res = -INF;
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 17, d = dep[x] - dep[y]; ~i; --i) 
		if((d >> i) & 1) { res = max(res, maxw[x][i]); x = jump[x][i]; }
	if(x == y) return res;
	for(int i = 17; ~i; --i)
		if(jump[x][i] ^ jump[y][i]) {
			res = max(res, maxw[x][i]), res = max(res, maxw[y][i]);
			x = jump[x][i], y = jump[y][i];
		}
	res = max(res, max(maxw[x][0], maxw[y][0]));
	return res;
}
 
bool chk() {
	for(int i = 1; i <= n; ++i) if(find(i) != find(1)) return false;
	return true;
}

void Boruvka() {
	for(int i = 1; i <= n; ++i) link[i] = E2(0, 0, INF);
	for(int i = 1; i <= n; ++i) T.update(dfn[i], dsu[i] = find(dsu[i]));
	for(int x = 1, pre, nxt, c; x <= n; ++x) {
		c = dsu[x];
		for(auto to : G[x]) T.update(dfn[to], c);
		nxt = T.query_nxt(dfn[x] + 1, c);
		pre = T.query_pre(dfn[x] - 1, c);
		if(~nxt) link[c] = min(link[c], E2(x, nxt, W[LCA(x, nxt)])), assert(dsu[nxt] != dsu[x]);
		if(~pre) link[c] = min(link[c], E2(x, pre, W[LCA(x, pre)])), assert(dsu[pre] != dsu[x]);
		for(auto to : G[x]) T.update(dfn[to], dsu[to]);
	}
	for(int i = 1, x, y; i <= n; ++i) { 
		if(!link[i].x || !link[i].y) continue;
		x = link[i].x, y = link[i].y;
		if(find(x) == find(y)) continue;
		AnsT.add(x, y, link[i].w), AnsT.add(y, x, link[i].w); unity(x, y);
	}
}

void solve() {
	read(n), read(m); T.Init();
	e.siz = AnsT.siz = dfnc = 0, ncnt = n;
	for(int i = 1; i <= (n << 1); ++i) 
		e.head[i] = AnsT.head[i] = 0, dsu[i] = i, G[i].clear();
	for(int i = 1; i <= m; ++i) {
		read(es[i].x), read(es[i].y), read(es[i].w); es[i].id = i;
		G[es[i].x].pb(es[i].y), G[es[i].y].pb(es[i].x);
	}
	sort(es + 1, es + m + 1);
	for(int i = 1, X, Y; i <= m; ++i) {
		X = find(es[i].x), Y = find(es[i].y);
		if(X == Y) continue;
		++ncnt; e.add(ncnt, X, 0), e.add(ncnt, Y, 0);
		W[ncnt] = es[i].w, dsu[X] = dsu[Y] = ncnt;
	}
	DFS0(ncnt, 0), DFS1(ncnt, ncnt); e.siz = 0; //assert(dfnc == n);
	for(int i = 1; i <= (n << 1); ++i) dsu[i] = i;
	while(!chk()) Boruvka();
	DFS2(1, 0);
	for(int i = 1; i <= m; ++i) Ans[es[i].id] = LCA2(es[i].x, es[i].y);
	for(int i = 1; i <= m; ++i) printf("%d ", Ans[i]);
	putchar('\n');
}

signed main () {
#ifdef FILE
	freopen("CF1648E.in", "r", stdin);
	freopen("CF1648E.out", "w", stdout);
#endif
	read(TestCase);
	while(TestCase--) solve();
	return 0;
}