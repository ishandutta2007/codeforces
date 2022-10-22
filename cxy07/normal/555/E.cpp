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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN << 1], to[MAXN << 1];
	void add(int x, int y) {
		nxt[++siz] = head[x];
		to[siz] = y, head[x] = siz;
	}
} e, T;

int n, m, q;
int dfn[MAXN], low[MAXN], dfnc;
int col[MAXN], con[MAXN], colc, conc;
int p[MAXN][21], dep[MAXN], up[MAXN], dn[MAXN];
bool cut[MAXN << 1];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Tarjan(int x, int f) {
	dfn[x] = low[x] = ++dfnc;
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i];
		if(to == f) continue;
		if(!dfn[to]) {
			Tarjan(to, x);
			low[x] = min(low[x], low[to]);
			if(low[to] > dfn[x]) cut[i] = cut[i ^ 1] = true;
		} else low[x] = min(low[x], dfn[to]);
	}
}

void DFS1(int x) {
	col[x] = colc;
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i];
		if(col[to] || cut[i]) continue;
		DFS1(to);
	}
}

void DFS2(int x, int f) {
	con[x] = conc, dep[x] = dep[f] + 1, p[x][0] = f;
	for(int i = 1; i <= 20; ++i)
		p[x][i] = p[p[x][i - 1]][i - 1];
	for(int i = T.head[x], to; i; i = T.nxt[i]) {
		to = T.to[i];
		if(to == f) continue;
		DFS2(to, x);
	}
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; ~i; --i)
		if(dep[p[x][i]] >= dep[y]) x = p[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; --i)
		if(p[x][i] ^ p[y][i]) x = p[x][i], y = p[y][i];
	return p[x][0];
}

void chk(int x, int f) {
	for(int i = T.head[x], to; i; i = T.nxt[i]) {
		to = T.to[i];
		if(to == f) continue;
		chk(to, x);
		up[x] += up[to], dn[x] += dn[to];
	}
	if(up[x] && dn[x]) puts("No"), exit(0);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(q); e.siz = 1;
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		e.add(x, y), e.add(y, x);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) Tarjan(i, 0);
	for(int i = 1; i <= n; ++i)
		if(!col[i]) colc++, DFS1(i);
	for(int i = 1; i <= n; ++i)
		for(int j = e.head[i]; j; j = e.nxt[j])
			if(col[i] ^ col[e.to[j]]) 
				T.add(col[i], col[e.to[j]]);
	for(int i = 1; i <= colc; ++i)
		if(!con[i]) conc++, DFS2(i, 0);
	for(int i = 1, x, y; i <= q; ++i) {
		read(x), read(y);
		x = col[x], y = col[y];
		if(x == y) continue;
		if(con[x] ^ con[y]) return puts("No"), 0;
		int lca = LCA(x, y);
		up[x]++, up[lca]--, dn[y]++, dn[lca]--;
	}
	for(int i = 1; i <= colc; ++i)
		if(!p[i][0]) chk(i, 0);
	puts("Yes");
	return 0;
}