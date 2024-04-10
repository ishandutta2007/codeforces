//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 2e5 + 10;
const int MAXM = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;

struct EDGE1 {
	int x,y,w;
	bool tag;
	EDGE1(int _x = 0,int _y = 0,int _w = 0):x(_x),y(_y),w(_w) {}
} G[MAXM];

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXM << 1],to[MAXM << 1],w[MAXM << 1];
	inline void addedge(int x,int y,int _w) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		w[edgesize] = _w;
		head[x] = edgesize;
	}
} e;

int n,m,ans;
int fa[MAXN],LB[110],dep[MAXN];
int p[MAXN][31],w[MAXN][31];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int find(int x) {
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return fa[x];
}

void unity(int x,int y) {
	if(find(x) != find(y))
		fa[find(x)] = find(y);
}

void DFS(int x,int f,int W) {
	p[x][0] = f;
	w[x][0] = W;
	dep[x] = dep[f] + 1;
	for(int i = 1;i <= 20; ++i)
		p[x][i] = p[p[x][i - 1]][i - 1],
		w[x][i] = w[p[x][i - 1]][i - 1] ^ w[x][i - 1];
	for(int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(to == f) continue;
		DFS(to,x,e.w[i]);
	}
}

int XOR(int x,int y) {
	int res = 0;
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 20;~i; --i)
		if(dep[p[x][i]] >= dep[y]) 
			res ^= w[x][i],x = p[x][i];
	if(x == y) return res;
	for(int i = 20;~i; --i) {
		if(p[x][i] == p[y][i]) continue;
		res ^= w[x][i] ^ w[y][i];
		x = p[x][i],y = p[y][i];
	}
	return res ^ w[x][0] ^ w[y][0];
}

void Insert(int v) {
	for(int i = 63;~i; --i) {
		if((v & (1ll << i)) == 0) continue;
		if(!LB[i]) LB[i] = v;
		v ^= LB[i];
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	for(int i = 1;i <= n; ++i) fa[i] = i;
	for(int i = 1,x,y,w;i <= m; ++i) {
		read(x); read(y); read(w);
		G[i] = EDGE1(x,y,w);
	}
	for(int i = 1,x,y,w;i <= m; ++i) {
		x = G[i].x,y = G[i].y,w = G[i].w;
		if(find(x) == find(y)) {
			G[i].tag = false;
			continue;
		}
		G[i].tag = true;
		unity(x,y);
		e.addedge(x,y,w);
		e.addedge(y,x,w);
	}
	DFS(1,0,0);
	for(int i = 1,v;i <= m; ++i) {
		if(G[i].tag) continue;
		v = G[i].w;
		v ^= XOR(G[i].x,G[i].y);
		Insert(v);
	}
	ans = XOR(1,n);
	for(int i = 63;~i; --i)
		if((ans ^ LB[i]) < ans) ans ^= LB[i];
	printf("%lld\n",ans);
	return 0;
}