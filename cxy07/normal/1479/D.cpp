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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q, cnt;
int a[MAXN], rt[MAXN], ls[MAXN * 30], rs[MAXN * 30];
int fa[MAXN], p[MAXN][21], dep[MAXN];
vec<int> G[MAXN];
ull v[MAXN], sum[MAXN * 30], V = 1ull << 32;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void update(int &x, int pre, int l, int r, int p) {
	x = ++cnt; ls[x] = ls[pre], rs[x] = rs[pre], sum[x] = sum[pre] ^ v[p];
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) update(ls[x], ls[pre], l, mid, p);
	else update(rs[x], rs[pre], mid + 1, r, p);
}

void DFS(int x, int f) {
	fa[x] = f, p[x][0] = f, dep[x] = dep[f] + 1;
	for(int i = 1; i <= 20; ++i)
		p[x][i] = p[p[x][i - 1]][i - 1];
	update(rt[x], rt[f], 1, n, a[x]);
	for(auto to : G[x]) if(to ^ f) DFS(to, x);
}

int query(int a, int b, int c, int d, int l, int r, int L, int R) {
	if(!(sum[a] ^ sum[b] ^ sum[c] ^ sum[d])) return -1;
	if(l == r) return l;
	int mid = (l + r) >> 1, res = -1;
	if(L <= mid) res = query(ls[a], ls[b], ls[c], ls[d], l, mid, L, R);
	if(~res) return res;
	if(R > mid) res = query(rs[a], rs[b], rs[c], rs[d], mid + 1, r, L, R);
	return res;
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

void solve() {
	int a, b, c, d, l, r; 
	read(a), read(b), read(l), read(r);
	c = LCA(a, b); d = fa[c];
	printf("%d\n", query(rt[a], rt[b], rt[c], rt[d], 1, n, l, r));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	srand(time(0));
	read(n), read(q);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) 
		v[i] = 1ull * (randint(0, V - 1) << 32) | randint(0, V - 1);
	for(int i = 1, x, y; i < n; ++i)
		read(x), read(y), G[x].pb(y), G[y].pb(x);
	DFS(1, 0);
	while(q--) solve();
	return 0;
}