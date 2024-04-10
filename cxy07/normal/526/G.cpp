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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, Ans, leaf, sumw;
int ind[MAXN], dep[MAXN], A, B;
vec<pii> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Getdep(int x, int f) {
	for(auto to : G[x]) {
		if(to.fst == f) continue;
		dep[to.fst] = dep[x] + to.scd; 
		Getdep(to.fst, x);
	}
}

struct Tree {
	int rt, top[MAXN], son[MAXN], len[MAXN], fa[MAXN], up[MAXN];
	int jump[MAXN][21], ww[MAXN][21], dep[MAXN];
	int pos[MAXN], sum[MAXN];
	pii link[MAXN];
	void DFS(int x, int f) {
		jump[x][0] = fa[x] = f;
		for(int i = 1; i <= 20; ++i) {
			jump[x][i] = jump[jump[x][i - 1]][i - 1];
			ww[x][i] = ww[x][i - 1] + ww[jump[x][i - 1]][i - 1];
		}
		for(auto t : G[x]) {
			int to = t.fst, w = t.scd;
			if(to == f) continue;
			up[to] = ww[to][0] = w;
			DFS(to, x);
			if(!son[x] || len[to] + up[to] > len[x])
				len[x] = len[to] + up[to], son[x] = to;
		}
	}
	void DFS2(int x, int tp) {
		top[x] = tp;
		if(son[x]) DFS2(son[x], tp);
		for(auto to : G[x]) 
			if(to.fst != fa[x] && to.fst != son[x]) 
				DFS2(to.fst, to.fst);
	}
	void build(int _rt) {
		rt = _rt;
		DFS(rt, 0); DFS2(rt, rt);
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			if(top[i] == i) link[++cnt] = mp(-len[i] - up[i], i);
		sort(link + 1, link + cnt + 1);
		for(int i = 1; i <= cnt; ++i) {
			pos[link[i].scd] = i;
			sum[i] = -link[i].fst + sum[i - 1];
		}
	}
	int opt1(int x, int y) {
		int res = len[x];
		for(int i = 20; ~i; --i)
			if(pos[top[jump[x][i]]] >= y)
				res += ww[x][i], x = jump[x][i];
		return res + up[x] + sum[y - 1];
	}
	int opt2(int x, int y) {
		int res = len[x];
		for(int i = 20; ~i; --i)
			if(pos[top[jump[x][i]]] > y)
				res += ww[x][i], x = jump[x][i];
		return sum[y] - len[fa[x]] + res + up[x];
	}
	int query(int x, int y) {
		if(2 * y >= leaf) return sumw;
		y = 2 * y - 1;
		if(pos[top[x]] <= y) return sum[y];
		return max(opt1(x, y), opt2(x, y));
	}
} T[3];

signed main () {
#ifdef FILE
	freopen("CF526G.in", "r", stdin);
	freopen("CF526G.out", "w", stdout);
#endif
	read(n), read(q);
	for(int i = 1, x, y, w; i < n; ++i) {
		read(x), read(y), read(w);
		G[x].pb(mp(y, w)), G[y].pb(mp(x, w));
		ind[x]++, ind[y]++, sumw += w;
	}
	for(int i = 1; i <= n; ++i)
		if(ind[i] == 1) leaf++;
	Getdep(1, 0); A = max_element(dep + 1, dep + n + 1) - dep;
	Getdep(A, 0); B = max_element(dep + 1, dep + n + 1) - dep;
	T[1].build(A), T[2].build(B);
	while(q--) {
		int x, y; read(x), read(y);
		x = (x + Ans - 1) % n + 1;
		y = (y + Ans - 1) % n + 1;
		Ans = max(T[1].query(x, y), T[2].query(x, y));
		printf("%lld\n", Ans);
	}
	return 0;
}