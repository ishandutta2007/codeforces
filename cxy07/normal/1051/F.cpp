#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 50;
const int INF = 1e18;

struct EDGE {
	int nxt;
	int to;
	int w;
} edge[MAXM << 1],edge1[MAXM << 1];

struct NODE {
	int id,w;
	bool operator < (const NODE &b) const {return w > b.w;}
};

int n,m,q,cnt;
int f[MAXN],res[MAXN];
int head[MAXN],edgesize;
int head1[MAXN],edgesize1;
int dis[MAXN],dep[MAXN];
int dij[51][MAXN];
int lca[MAXN][31];
bool isr[MAXN];
bool done[MAXN];

inline void addedge(int x,int y,int w) {
	edge[++edgesize].nxt = head[x];
	edge[edgesize].to = y;
	edge[edgesize].w = w;
	head[x] = edgesize;
}

inline void addedge1(int x,int y,int w) {
	edge1[++edgesize1].nxt = head1[x];
	edge1[edgesize1].to = y;
	edge1[edgesize1].w = w;
	head1[x] = edgesize1;
}

inline void DFS(int now,int fa) {
	dep[now] = dep[fa] + 1;
	lca[now][0] = fa;
	for(register int i = head[now],to;i;i = edge[i].nxt) {
		to = edge[i].to;
		if(to == fa) continue;
		dis[to] = dis[now] + edge[i].w;
		DFS(to,now);
	}
}

inline int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(register int p = 20;p >= 0; --p) 
		if(dep[lca[x][p]] >= dep[y]) x = lca[x][p];
	if(x == y) return x;
	for(register int p = 20;p >= 0; --p) {
		if(lca[x][p] == lca[y][p]) continue;
		x = lca[x][p],y = lca[y][p];
	}
	return lca[x][0];
}

inline int len(int x,int y) {
	int Lca = LCA(x,y);
	return dis[x] + dis[y] - 2 * dis[Lca];
}

inline void Dijkstra(int x) {
	memset(done,0,sizeof done);
	priority_queue<NODE> Q;
	int s = res[x];
	Q.push((NODE){s,0});
	dij[x][s] = 0;
	while(Q.size()) {
		int now = Q.top().id;
		Q.pop();
		if (done[now]) continue;
		done[now] = 1;
		for(register int i = head1[now];i;i = edge1[i].nxt) {
			if(dij[x][edge1[i].to] > dij[x][now] + edge1[i].w) {
				dij[x][edge1[i].to] = dij[x][now] + edge1[i].w;
				Q.push((NODE){edge1[i].to,dij[x][edge1[i].to]});
			}
		}
	}
}

inline int find(int x) {
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

inline void unity(int x,int y) {f[find(x)] = find(y);}	

signed main () {
	scanf("%lld%lld",&n,&m);
	memset(dij,0x3f,sizeof dij);
	for(register int i = 1;i <= n; ++i)
		f[i] = i;
	for(register int i = 1,x,y,w;i <= m; ++i) {
		scanf("%lld%lld%lld",&x,&y,&w);
		addedge1(x,y,w);
		addedge1(y,x,w);
		if(find(x) != find(y)) {
			unity(x,y);
			addedge(x,y,w);
			addedge(y,x,w);
		} else isr[x] = isr[y] = true;
	}
	DFS(1,0);
	for(register int i = 1;i <= n; ++i)
		if(isr[i]) res[++cnt] = i,Dijkstra(cnt);
	for(register int p = 1;p <= 20; ++p)
		for(register int now = 1;now <= n; ++now)
			lca[now][p] = lca[lca[now][p - 1]][p - 1];
	scanf("%lld",&q);
	while(q--) {
		int x,y,ans = INF;
		scanf("%lld%lld",&x,&y);
		ans = len(x,y);
		for(register int i = 1;i <= cnt; ++i)
			ans = min(ans,dij[i][x] + dij[i][y]);
		printf("%lld\n",ans);
	}
	return 0;
}