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
#define pb emplace_back
#define LL long long
#define mp make_pair
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
const int base = 131;

int n, m;
int dep[MAXN], p[MAXN][21], fa[MAXN];
int pw[MAXN], ip[MAXN];
char s[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, x = 1ll * x * x % mod) if(b & 1) res = 1ll * res * x % mod;
	return res;
}

void DFS(int x, int f) {
	fa[x] = p[x][0] = f, dep[x] = dep[f] + 1;
	for(int i = 1; i <= 20; ++i) p[x][i] = p[p[x][i - 1]][i - 1];
	for(auto to : G[x]) if(to ^ f) DFS(to, x);
}

namespace Hash {
	int up[MAXN], dn[MAXN];
	void DFS(int x) {
		up[x] = (1ll * up[fa[x]] * base % mod + s[x]) % mod;
		dn[x] = (dn[fa[x]] + 1ll * qpow(base, dep[x] - 1) * s[x] % mod) % mod;
		for(auto to : G[x])
			if(to != fa[x]) DFS(to);
	}
	int UP(int x, int y) {
		if(dep[x] < dep[y] || !y) return 0;
		int len = dep[x] - dep[y] + 1;
		return (up[x] - 1ll * up[fa[y]] * pw[len] % mod + mod) % mod;
	}
	int DN(int x, int y) {
		int res = (dn[y] - dn[fa[x]] + mod) % mod;
		res = 1ll * res * ip[dep[x] - 1] % mod;
		return res;
	}
	void build() {
		DFS(1); pw[0] = ip[0] = 1, pw[1] = base, ip[1] = inv(base);
		for(int i = 1; i <= n; ++i) {
			pw[i] = 1ll * pw[i - 1] * pw[1] % mod;
			ip[i] = 1ll * ip[i - 1] * ip[1] % mod;
		}
	}
}

namespace kth {
	int top[MAXN];
	int len[MAXN], son[MAXN], hb[MAXN];
	int topbit[MAXN];
	vec<int> up[MAXN], dn[MAXN];
	void DFS1(int x) {
		len[x] = dep[x];
		for(auto to : G[x]) {
			if(to == fa[x]) continue;
			DFS1(to);
			if(len[to] > len[x]) son[x] = to, len[x] = len[to];
		}
	}
	void DFS2(int x,int tp) {
		top[x] = tp;
		if(x == tp) {
			for(int i = 0, v = x; i <= len[x] - dep[x]; ++i)
				up[x].pb(v), v = fa[v];
			for(int i = 0, v = x; i <= len[x] - dep[x]; ++i)
				dn[x].pb(v), v = son[v];
		}
		if(son[x]) DFS2(son[x], tp);
		for(auto to : G[x]) {
			if(to == son[x] || to == fa[x]) continue;
			DFS2(to, to);
		}
	}
	void build() {
		for(int i = 1; i <= n; ++i) hb[i] = hb[i >> 1] + 1;
		DFS1(1); DFS2(1, 1);
	}
	int qk(int x, int k) {
		if(k < 0 || k > dep[x]) return 0;
		if(!k) return x;
		int bit = hb[k]; k -= (1 << (bit - 1));
		x = p[x][bit - 1];
		k -= dep[x] - dep[top[x]]; x = top[x];
		if(k >= 0) return up[x][k];
		else return dn[x][-k];
	}
}

using kth :: qk;
using Hash :: UP;
using Hash :: DN;

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; ~i; --i) 
		if(dep[p[x][i]] >= dep[y]) x = p[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; --i)
		if(p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
	return p[x][0];
}

int way(int a, int b, int lca, int len) {
	if(dep[a] - dep[lca] + 1 >= len) return UP(a, qk(a, len - 1));
	int res = UP(a, qk(a, dep[a] - dep[lca] - 1)), anc; len -= dep[a] - dep[lca];
	anc = qk(b, (dep[b] - dep[lca] + 1) - len);
	res = (res + 1ll * pw[dep[a] - dep[lca]] * DN(lca, anc)) % mod;
	return res;
}

int calc() {
	int a, b, c, d; read(a), read(b), read(c), read(d);
	if(s[a] != s[c]) return 0;
	int l1 = LCA(a, b), l2 = LCA(c, d), L = 1, R, mid;
	R = min(dep[a] + dep[b] - dep[l1] * 2 + 1, 
			dep[c] + dep[d] - dep[l2] * 2 + 1);
	while(L < R) {
		mid = (L + R + 1) >> 1;
		if(way(a, b, l1, mid) == way(c, d, l2, mid)) L = mid;
		else R = mid - 1;
	}
	return L;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); scanf("%s", s + 1);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	DFS(1, 0);
	Hash :: build(), kth :: build();
	read(m);
	while(m--) printf("%d\n", calc());
	return 0;
}