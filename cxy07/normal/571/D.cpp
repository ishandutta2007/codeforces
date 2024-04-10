//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define LL long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 1e6 + 10;
const int R = 1e6;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, ansc;
LL Ans[MAXN];
char tmps[MAXN];

struct SET {
	int f[MAXN], up[MAXN], tot[MAXN], cnt, root;
	int dfn[MAXN], siz[MAXN], dfnc;
	vec<int> G[MAXN];
	void init() {
		cnt = n, dfnc = 0;
		for(int i = 1; i <= n; ++i) f[i] = up[i] = i, tot[i] = 1;
	}
	int find(int x) {
		if(f[x] ^ x) return f[x] = find(f[x]);
		return x;
	}
	void unity(int x, int y, bool link = 0) {
		x = find(x), y = find(y);
		if(x == y) return;
		cnt++; if(link) G[cnt].pb(up[x]), G[cnt].pb(up[y]);
		f[x] = y, tot[y] += tot[x]; tot[x] = 0, up[x] = up[y] = cnt;
	}
	void make() {
		root = ++cnt;
		for(int i = 1; i <= n; ++i)
			if(find(i) == i) G[root].pb(up[i]);
	}
	void DFS(int x) {
		dfn[x] = ++dfnc, siz[x] = 1;
		for(auto to : G[x]) {
			DFS(to);
			siz[x] += siz[to];
		}
	}
} A, B;

struct Query {
	int opt, x, y;
	Query(int _o = 0, int _x = 0, int _y = 0) : opt(_o), x(_x), y(_y) {}
} q[MAXN];

struct Q2 {
	int t, x, p;
	Q2(int _t = 0, int _x = 0, int _p = 0) : t(_t), x(_x), p(_p) {}
	bool operator < (const Q2 &b) const {return t < b.t;}
};

vec<Q2> qs;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

struct SGT1 {
	LL tag[MAXN << 2];
	void update(int x, int l, int r, int L, int R, LL v) {
		if(L <= l && r <= R) return tag[x] += v, void();
		int mid = (l + r) >> 1;
		if(L <= mid) update(x << 1, l, mid, L, R, v);
		if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	}
	LL query(int x, int l, int r, int p, LL now) {
		now += tag[x];
		if(l == r) return now;
		int mid = (l + r) >> 1;
		if(p <= mid) return query(x << 1, l, mid, p, now);
		else return query(x << 1 | 1, mid + 1, r, p, now);
	}
} P;

struct SGT {
	int t[MAXN << 2], tag[MAXN << 2];
	void pushdown(int x) {
		if(!tag[x]) return;
		tag[x << 1] = t[x << 1] = tag[x << 1 | 1] = t[x << 1 | 1] = tag[x];
		tag[x] = 0;
	}
	void update(int x, int l, int r, int L, int R, int v) {
		if(L <= l && r <= R) return tag[x] = t[x] = v, void();
		int mid = (l + r) >> 1; pushdown(x);
		if(L <= mid) update(x << 1, l, mid, L, R, v);
		if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	}
	int query(int x, int l, int r, int p) {
		if(l == r) return t[x];
		int mid = (l + r) >> 1; pushdown(x);
		if(p <= mid) return query(x << 1, l, mid, p);
		else return query(x << 1 | 1, mid + 1, r, p);
	}
} T;

void solve1(int id) {
	int opt = q[id].opt, x = q[id].x, y = q[id].y;
	if(opt == 1) return A.unity(x, y), void();
	if(opt == 2) return B.unity(x, y), void();
	if(opt == 4) {
		int top = B.up[B.find(x)];
		int l = B.dfn[top], r = B.dfn[top] + B.siz[top] - 1;
		T.update(1, 1, R, l, r, id);
	}
	if(opt == 5) {
		int c = T.query(1, 1, R, B.dfn[x]);
		ansc++;
		if(c) qs.pb(Q2(c, -A.dfn[x], ansc));
		qs.pb(Q2(id, A.dfn[x], ansc));
	}
}

int pos = 0;

void solve2(int id) {
	int opt = q[id].opt, x = q[id].x, y = q[id].y;
	if(opt == 1) return A.unity(x, y), void();
	if(opt == 2) return B.unity(x, y), void();
	if(opt == 3) {
		int top = A.up[A.find(x)];
		int l = A.dfn[top], r = A.dfn[top] + A.siz[top] - 1, siz = A.tot[A.find(x)];
		P.update(1, 1, R, l, r, siz);
	}
	while(pos < qs.size() && qs[pos].t == id) {
		int sgn = qs[pos].x < 0 ? -1 : 1;
		Ans[qs[pos].p] += sgn * P.query(1, 1, R, abs(qs[pos].x), 0);
		pos++;
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); A.init(), B.init();
	for(int i = 1, x, y; i <= m; ++i) {
		scanf("%s", tmps + 1); read(x);
		if(tmps[1] == 'U') read(y), q[i] = Query(1, x, y), A.unity(x, y, true);
		if(tmps[1] == 'M') read(y), q[i] = Query(2, x, y), B.unity(x, y, true);
		if(tmps[1] == 'A') q[i] = Query(3, x, 0);
		if(tmps[1] == 'Z') q[i] = Query(4, x, 0);
		if(tmps[1] == 'Q') q[i] = Query(5, x, 0);
	}
	A.make(), B.make();
	A.DFS(A.root); B.DFS(B.root); A.init(), B.init();
	for(int i = 1; i <= m; ++i) solve1(i);
	sort(qs.begin(), qs.end()); A.init(), B.init();
	for(int i = 1; i <= m; ++i) solve2(i);
	for(int i = 1; i <= ansc; ++i) printf("%lld\n", Ans[i]);
	return 0;
}