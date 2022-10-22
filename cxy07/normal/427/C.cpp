//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
const int MAXM = 3e5 + 10;
const int mod = 1e9 + 7;

struct EDGE {
	int nxt;
	int to;
} edge[MAXM << 1];

int n,m,ans1,ans2;
int head[MAXN],edgesize;
int vnode[MAXN],v[MAXN];
int dfn[MAXN],low[MAXN],st[MAXN],col[MAXN],cnt,depth,top;
int minv[MAXN],vcnt[MAXN];
bool vis[MAXN];

inline void addedge(int x,int y) {
	edge[++edgesize].nxt = head[x];
	edge[edgesize].to = y;
	head[x] = edgesize;
}

void Tarjan(int u) {
	dfn[u] = ++depth;
	low[u] = dfn[u];
	st[++top] = u;
	vis[u] = true;
	for(register int i = head[u],to;i;i = edge[i].nxt) {
		to = edge[i].to;
		if(!dfn[to]) {
			Tarjan(to);
			low[u] = min(low[u],low[to]);
		} else if(vis[to]) low[u] = min(low[u],dfn[to]);
	}
	if(low[u] == dfn[u]) {
		col[u] = ++cnt;
		vis[u] = false;
		minv[cnt] = vnode[u];
		vcnt[cnt] = 1;
		while(st[top] != u) {
			col[st[top]] = cnt;
			vis[st[top]] = false;
			if(vnode[st[top]] < minv[cnt]) {
				minv[cnt] = vnode[st[top]];
				vcnt[cnt] = 0;
			}
			if(vnode[st[top]] == minv[cnt])
				vcnt[cnt]++;
			top--;
		}
		top--;
	}
}

signed main () {
	scanf("%lld",&n);
	for(register int i = 1;i <= n; ++i)
		scanf("%lld",&vnode[i]);
	scanf("%lld",&m);
	for(register int i = 1,x,y;i <= m; ++i) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for(register int i = 1;i <= n; ++i)
		if(!dfn[i]) Tarjan(i);
	ans2 = 1;
	for(register int i = 1;i <= cnt; ++i) {
		ans1 += minv[i];
		(ans2 *= vcnt[i]) %= mod;
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}