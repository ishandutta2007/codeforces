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
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, cnt;
int X[MAXN], Y[MAXN], oc[MAXN];
int same[MAXN], sc, lastans, root[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

struct Tarjan {
	struct EDGE {
		int head[MAXN], siz;
		int nxt[MAXN << 2], to[MAXN << 2];
	} e;
	void add(int x, int y) {
		e.nxt[++e.siz] = e.head[x];
		e.to[e.siz] = y, e.head[x] = e.siz;
	}
	int dfn[MAXN], col[MAXN], low[MAXN], dfnc, colc;
	bool isb[MAXN << 2];
	vec<int> idx, bridge;
	void DFS(int x, int ban) {
		dfn[x] = low[x] = ++dfnc;
		for(int i = e.head[x], to; i; i = e.nxt[i]) {
			if((i ^ 1) == ban) continue;
			to = e.to[i];
			if(!dfn[to]) {
				DFS(to, i); low[x] = min(low[x], low[to]);
				if(low[to] > dfn[x]) bridge.pb(i), isb[i] = isb[i ^ 1] = true;
			} else low[x] = min(low[x], dfn[to]);
		}
	}
	void Fill(int x, int c) {
		col[x] = c;
		for(int i = e.head[x], to; i; i = e.nxt[i]) {
			to = e.to[i];
			if(!col[to] && !isb[i]) Fill(to, c);
		}
	}
	int solve() {
		for(auto x : idx) if(!dfn[x]) DFS(x, 0);
		for(auto x : idx) if(!col[x]) Fill(x, ++colc);
		return colc;
	}
	void clear() {
		dfnc = colc = 0;
		for(auto x : idx) dfn[x] = col[x] = low[x] = e.head[x] = 0;
		for(auto x : bridge) isb[x] = isb[x ^ 1] = false;
		for(int i = 1; i <= e.siz; ++i) e.to[i] = e.nxt[i] = 0;
		idx.clear(), bridge.clear(); e.siz = 1;
	}
} T;

namespace VT {
	int dfn[MAXN], dfnc, p[MAXN][21], dep[MAXN];
	int stk[MAXN], top, root;
	vec<int> idx;
	void DFS(int x, int f) {
		p[x][0] = f, dfn[x] = ++dfnc, dep[x] = dep[f] + 1;
		for(int i = 1; i <= 20; ++i)
			p[x][i] = p[p[x][i - 1]][i - 1];
		for(auto to : G[x]) if(to ^ f) DFS(to, x);
	}
	int LCA(int x, int y) {
		if(dep[x] < dep[y]) swap(x, y);
		for(int i = 20; ~i; --i) 
			if(dep[p[x][i]] >= dep[y]) x = p[x][i];
		if(x == y) return x;
		for(int i = 20; ~i; --i)
			if(p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
		return p[x][0];
	}
	bool cmp(int a, int b) {return dfn[a] < dfn[b];}
	void add(int a, int b) {T.add(a, b), T.add(b, a);}
	void Insert(int x) {
		if(x == root) return;
		if(!top) return stk[++top] = x, T.idx.pb(x), void();
		int lca = LCA(x, stk[top]);
		while(top > 1 && dep[lca] < dep[stk[top - 1]])
			add(stk[top - 1], stk[top]), top--;
		if(dep[lca] < dep[stk[top]]) add(lca, stk[top--]);
		if((!top) || stk[top] != lca) stk[++top] = lca, T.idx.pb(lca);
		stk[++top] = x; T.idx.pb(x);
	}
	void build(int rt) {
		root = rt; sort(idx.begin(), idx.end(), cmp);
		stk[top = 1] = root; T.idx.pb(root);
		for(auto x : idx) Insert(x);
		while(top > 1) add(stk[top - 1], stk[top]), top--;
		idx.clear();
	}
}

void DFS(int x, int f, int c) {
	same[x] = c;
	for(auto to : G[x]) if(to ^ f) DFS(to, x, c);
}

bool cmp(int a, int b) {return same[a] < same[b];}

int Get(int id) {
	int res; read(res);
	res = (res + lastans) % n;
	return res ? res : n;
}

void solve(int id) {
	static int V, E, Ans; Ans = 1;
	static vec<int> node, U; node.clear(), U.clear();
	read(V), read(E); T.clear();
	for(int i = 1; i <= V; ++i) node.pb(oc[Get(id)]), U.pb(node.back());
	for(int i = 1, x, y; i <= E; ++i) {
		x = oc[Get(id)], y = oc[Get(id)];
		node.pb(x), node.pb(y);
		T.add(x, y); T.add(y, x);
	}
	sort(node.begin(), node.end());
	node.erase(unique(node.begin(), node.end()), node.end());
	sort(node.begin(), node.end(), cmp);
	for(int l = 0, r; l < node.size(); l = r + 1) {
		r = l;
		while(r + 1 < node.size() && same[node[r + 1]] == same[node[l]]) r++;
		VT :: idx.clear();
		for(int i = l; i <= r; ++i) VT :: idx.pb(node[i]);
		VT :: build(root[same[node[l]]]);
	}
	sort(T.idx.begin(), T.idx.end());
	T.idx.erase(unique(T.idx.begin(), T.idx.end()), T.idx.end());
	T.solve(); 
	for(auto x : U) Ans &= (T.col[x] == T.col[U[0]]);
	if(Ans) (lastans += id) %= n;
	puts(Ans ? "YES" : "NO");
}

signed main () {
#ifdef FILE
	freopen("CF639F.in", "r", stdin);
	freopen("CF639F.out", "w", stdout);
#endif
	read(n), read(m), read(q); T.e.siz = 1;
	for(int i = 1; i <= n; ++i) T.idx.pb(i);
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y); X[i] = x, Y[i] = y;
		T.add(x, y), T.add(y, x);
	}
	cnt = T.solve(); memcpy(oc, T.col, sizeof oc); T.clear();
	for(int i = 1, a, b; i <= m; ++i) {
		a = oc[X[i]], b = oc[Y[i]];
		if(a ^ b) G[a].pb(b), G[b].pb(a);
	}
	for(int i = 1; i <= cnt; ++i) 
		if(!same[i]) {
			DFS(i, 0, ++sc), root[sc] = i;
			VT :: DFS(i, 0);
		}
	for(int i = 1; i <= q; ++i) solve(i);
	return 0;
}