//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 10;
const int add = 1e6;

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN << 1],to[MAXN << 1],w[MAXN << 1];
	inline void addedge(int _x,int _y,int _w = 0) {
		nxt[++edgesize] = head[_x];
		to[edgesize] = _y;
		w[edgesize] = _w;
		head[_x] = edgesize;
	}
} e;

struct NODE {
	int id,w;
	NODE(int _id = 0,int _w = 0):id(_id),w(_w) {}
	inline bool operator < (const NODE &b) const {return w > b.w;}
};

int n,m,s;
int dis[MAXN];
int tin[MAXN << 2],tout[MAXN << 2],nodesize;
bool vis[MAXN];
priority_queue<NODE> Q;

void build(int root,int l,int r) {
	if(l == r) {
		tin[root] = tout[root] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	tin[root] = ++nodesize;
	tout[root] = ++nodesize;
	e.addedge(tin[root],tin[root << 1]),e.addedge(tin[root],tin[root << 1 | 1]);
	e.addedge(tout[root << 1],tout[root]),e.addedge(tout[root << 1 | 1],tout[root]);
}

void linkin(int root,int l,int r,int L,int R,int u,int w) {
	if(L <= l && r <= R) {
		e.addedge(u,tin[root],w);
		return;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) linkin(root << 1,l,mid,L,R,u,w);
	if(R > mid) linkin(root << 1 | 1,mid + 1,r,L,R,u,w);
}

void linkout(int root,int l,int r,int L,int R,int u,int w) {
	if(L <= l && r <= R) {
		e.addedge(tout[root],u,w);
		return;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) linkout(root << 1,l,mid,L,R,u,w);
	if(R > mid) linkout(root << 1 | 1,mid + 1,r,L,R,u,w);
}

inline void Dijkstra() {
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	Q.push(NODE(s,dis[s]));
	while(Q.size()) {
		int x = Q.top().id; Q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(register int i = e.head[x],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(dis[to] > dis[x] + e.w[i]) {
				dis[to] = dis[x] + e.w[i];
				Q.push(NODE(to,dis[to]));
			}
		}
	}
}

signed main () {
	scanf("%lld%lld%lld",&n,&m,&s);
	nodesize = n;
	build(1,1,n);
	while(m--) {
		int opt,v,l,r,w;
		scanf("%lld",&opt);
		if(opt == 1) {
			scanf("%lld%lld%lld",&v,&l,&w);
			e.addedge(v,l,w);
		} else if(opt == 2) {
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			linkin(1,1,n,l,r,v,w);
		} else if(opt == 3) {
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			linkout(1,1,n,l,r,v,w);
		}
	}
	Dijkstra();
	for(register int i = 1;i <= n; ++i) {
		if(dis[i] == dis[MAXN - 1]) printf("-1 ");
		else printf("%lld ",dis[i]);
	}
	return 0;
}