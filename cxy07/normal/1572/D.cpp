//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = (1 << 20) + 10;
const int SIZ = 2e4 + 10;
const int MAXM = 5e4 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[SIZ], siz;
	int nxt[MAXM], to[MAXM], w[MAXM], c[MAXM];
	void _add(int x, int y, int _w, int _c) {
		nxt[++siz] = head[x];
		to[siz] = y, w[siz] = _w, c[siz] = _c, head[x] = siz;
	}
	void add(int x, int y, int w, int c) { _add(x, y, w, c), _add(y, x, 0, -c); }
} e;

struct NODE {
	int a, b, w;
	NODE(int _a = 0, int _b = 0, int _w = 0) : a(_a), b(_b), w(_w) {}
	bool operator < (const NODE &b) const { return w > b.w; }
} w[MAXN * 20];

int n, k, S, T, Ans, lim, cnt;
int a[MAXN], idc, type[MAXN];
map<int, int> id;

namespace Flow {
	int dis[SIZ], maxflow, mincost;
	bool vis[SIZ];
	queue<int> Q;
	bool SPFA() {
		memset(vis, 0, sizeof vis);
		memset(dis, -0x3f, sizeof dis);
		Q.push(S), dis[S] = 0, vis[S] = true;
		while(Q.size()) {
			int x = Q.front(); Q.pop(); vis[x] = false;
			for(int i = e.head[x], to; i; i = e.nxt[i]) {
				to = e.to[i]; if(!e.w[i]) continue;
				if(dis[to] < dis[x] + e.c[i]) {
					dis[to] = dis[x] + e.c[i];
					if(!vis[to]) Q.push(to), vis[to] = true;
				}
			}
		} return (dis[T] != dis[SIZ - 1]);
	}
	int Dinic(int x, int flow) {
		if(x == T || !flow) return flow;
		int res = flow; vis[x] = true;
		for(int i = e.head[x], to, k; i && res; i = e.nxt[i]) {
			to = e.to[i]; if(!e.w[i]) continue;
			if(to != T && vis[to]) continue;
			if(dis[to] != dis[x] + e.c[i]) continue;
			k = Dinic(to, min(res, e.w[i]));
			if(!k) dis[to] = 0;
			e.w[i] -= k, e.w[i ^ 1] += k, res -= k;
			mincost += e.c[i] * k;
		} return flow - res;
	}
	int Getflow() {
		maxflow = mincost = 0;
		while(SPFA()) maxflow += Dinic(S, INF);
		return mincost;
	}
}

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

signed main () {
#ifdef FILE
	freopen("CF1572D.in", "r", stdin);
	freopen("CF1572D.out", "w", stdout);
#endif
	read(n), read(k); e.siz = 1;
	for(int i = 0; i < (1 << n); ++i) read(a[i]);
	for(int i = 0; i < (1 << n); ++i)
		for(int p = 0, x, y; p < n; ++p) {
			if((i >> p) & 1) continue;
			x = i, y = i | (1 << p);
			if(popc(x) & 1) swap(x, y);
			w[++cnt] = NODE(x, y, a[x] + a[y]);
		}
	lim = min(cnt, k * (2 * n - 1) + 1);
	nth_element(w + 1, w + lim + 1, w + cnt + 1);
	for(int i = 1; i <= lim; ++i) {
		if(!id.count(w[i].a)) type[id[w[i].a] = ++idc] = 1;
		if(!id.count(w[i].b)) type[id[w[i].b] = ++idc] = 2;
		e.add(id[w[i].a], id[w[i].b], 1, w[i].w);
	} S = idc + 3, T = idc + 2;
	for(int i = 1; i <= idc; ++i) {
		if(type[i] == 1) e.add(idc + 1, i, 1, 0);
		else e.add(i, T, 1, 0);
	} e.add(S, idc + 1, k, 0);
	Ans = Flow::Getflow();
	printf("%lld\n", Ans);
	return 0;
}