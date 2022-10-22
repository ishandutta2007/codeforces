//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int MAXM = 1e6 + 10;

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXM << 1],to[MAXM << 1];
	inline void addedge(int x,int y) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		head[x] = edgesize;
	}
	inline void clear() {
		memset(head,0,sizeof head);
		edgesize = 0;
	}
} e;

int T;
int n,m,a,b,ansa,ansb;
bool vis[MAXN];

int DFS(int x,int ban) {
	int tot = 1,flag = false;
	vis[x] = true;
	if(x == ban) return 0;
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(to == ban) {flag = true; continue;}
		if(vis[to]) continue;
		int now = DFS(to,ban);
		if(!now) flag = true;
		tot += now;
	}
	if(flag) return 0;
	return tot;
}

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&n,&m,&a,&b);
		e.clear();
		memset(vis,0,sizeof vis);
		ansa = ansb = 0;
		vis[a] = vis[b] = true;
		for(register int i = 1,x,y;i <= m; ++i) {
			scanf("%d%d",&x,&y);
			e.addedge(x,y);
			e.addedge(y,x);
		}
		for(register int i = e.head[a],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(!vis[to]) ansa += DFS(to,b);
		}
		for(register int i = e.head[b],to;i;i = e.nxt[i]) {
			to = e.to[i];
			if(!vis[to]) ansb += DFS(to,a);
		}
		printf("%lld\n",1ll * ansa * ansb);
	}
	return 0;
}