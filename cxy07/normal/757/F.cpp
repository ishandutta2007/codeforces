//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 4e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], edgesize;
	int nxt[MAXN << 1], to[MAXN << 1], w[MAXN << 1];
	inline void addedge(int x, int y, int _w = 1) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		w[edgesize] = _w;
		head[x] = edgesize;
	}
} G, T, e;

int n, m, s, Ans;
int ind[MAXN], outd[MAXN], ord[MAXN], fa[MAXN], siz[MAXN];
int lca[MAXN][21], dep[MAXN];
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

namespace BuildG {
	int dis[MAXN];
	priority_queue<pii> pq;
	void Dijkstra() {
		memset(dis, 0x3f, sizeof dis); dis[s] = 0;
		pq.push(mp(-dis[s], s));
		while(pq.size()) {
			int x = pq.top().scd; pq.pop(); if(vis[x]) continue;
			vis[x] = true;
			for(int i = G.head[x], to; i; i = G.nxt[i]) {
				to = G.to[i];
				if(dis[to] > dis[x] + G.w[i])
					dis[to] = dis[x] + G.w[i], pq.push(mp(-dis[to], to));
			}
		}
	}
	void main() {
		Dijkstra();
		for(int x = 1; x <= n; ++x) {
			if(!vis[x]) continue;
			for(int i = G.head[x]; i; i = G.nxt[i]) {
				if(!vis[G.to[i]]) continue;
				if(dis[G.to[i]] == dis[x] + G.w[i])
					e.addedge(x, G.to[i]), ind[G.to[i]]++;
			}
		}
	}
}

void update(int x) {
	lca[x][0] = fa[x], dep[x] = dep[fa[x]] + 1, T.addedge(fa[x], x);
	for(int i = 1; i <= 20; ++i)
		lca[x][i] = lca[lca[x][i - 1]][i - 1];
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; ~i; --i)
		if(dep[lca[x][i]] >= dep[y]) x = lca[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; --i)
		if(lca[x][i] ^ lca[y][i]) x = lca[x][i], y = lca[y][i];
	return lca[x][0];
}

void toposort() {
	queue<int> Q;
	while(Q.size()) Q.pop();
	for(int i = 1; i <= n; ++i)
		if(!ind[i]) fa[i] = n + 1, Q.push(i);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		update(x);
		for(int i = e.head[x], to; i; i = e.nxt[i]) {
			to = e.to[i];
			if(!fa[to]) fa[to] = x;
			else fa[to] = LCA(fa[to], x);
			if(!(--ind[to])) Q.push(to);
		}
	}
}

void DFS(int x) {
	siz[x] = (BuildG :: dis[x] != BuildG :: dis[MAXN - 1]);
	for(int i = T.head[x]; i; i = T.nxt[i])
		DFS(T.to[i]), siz[x] += siz[T.to[i]];
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(s);
	for(int i = 1, x, y, w; i <= m; ++i) {
		read(x), read(y), read(w);
		G.addedge(x, y, w), G.addedge(y, x, w);
	}
	BuildG :: main();
	toposort(); DFS(n + 1);
	for(int i = 1; i <= n; ++i) {
		if(i == s) continue;
		Ans = max(Ans, siz[i]);
	}
	printf("%lld\n", Ans);
	return 0;
}