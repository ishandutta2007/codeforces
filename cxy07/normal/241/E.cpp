#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MAXM = 5010;

struct EDGE {
	int nxt;
	int to;
	int w;
	bool in;
} edge[MAXM << 1];

int n,m;
int head[MAXN],edgesize;
int savx[MAXM],savy[MAXM];
int dis[MAXN],inq[MAXN],ans[MAXM],negx[MAXM],negy[MAXM],negcnt;
bool in[MAXN],vis[MAXN];

inline void addedge(int x,int y,int w = 0) {
	edge[++edgesize].nxt = head[x];
	edge[edgesize].to = y;
	edge[edgesize].w = w;
	edge[edgesize].in = false;
	head[x] = edgesize;
}

bool DFS(int x) {
	if(x == n) return (in[x] = true);
	if(vis[x]) return in[x];
	vis[x] = true;
	for(register int i = head[x],to;i;i = edge[i].nxt) {
		to = edge[i].to;
		int tmp = DFS(to);
		edge[i].in |= tmp;
		in[x] |= tmp;
	}
	return in[x];
}

void SPFA(int x) {
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	queue<int> Q;
	dis[x] = 0;
	inq[x] = 1;
	Q.push(x);
	while(Q.size()) {
		int top = Q.front(); Q.pop();
		vis[top] = false;
		for(register int i = head[top],to;i;i = edge[i].nxt) {
			to = edge[i].to;
			if(dis[to] > dis[top] + edge[i].w) {
				dis[to] = dis[top] + edge[i].w;
				if(++inq[to] > n) {puts("No"); exit(0);}
				Q.push(to);
			}
		}
	}
}

int main () {
	scanf("%d%d",&n,&m);
	for(register int i = 1;i <= m; ++i) {
		scanf("%d%d",&savx[i],&savy[i]);
		addedge(savx[i],savy[i]);
	}
	DFS(1);
	for(register int i = 1;i <= m; ++i) 
		if(edge[i].in) negx[++negcnt] = savx[i],negy[negcnt] = savy[i];
	memset(edge,0,sizeof edge);
	memset(head,0,sizeof head);
	edgesize = 0;
	for(register int i = 1;i <= negcnt; ++i) {
		addedge(negx[i],negy[i],2);
		addedge(negy[i],negx[i],-1);
	}
	SPFA(1);
	for(register int i = 1,u,v;i <= m; ++i) {
		u = savx[i]; v = savy[i];
		if(dis[v] - dis[u] < 1 || dis[v] - dis[u] > 2) ans[i] = 1;
		else ans[i] = dis[v] - dis[u];
	}
	puts("Yes");
	for(register int i = 1;i <= m; ++i)
		printf("%d\n",ans[i]);
	return 0;
}