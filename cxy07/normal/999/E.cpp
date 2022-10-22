#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

struct EDGE {
	int nxt;
	int to;
} edge[MAXN << 1];

int n,m,s,ans;
int savx[MAXN],savy[MAXN];
int head[MAXN],edgesize;
int dfn[MAXN],low[MAXN],st[MAXN],top,depth;
int col[MAXN],cnt,in[MAXN];
bool instack[MAXN];

inline void addedge(int x,int y) {
	edge[++edgesize].nxt = head[x];
	edge[edgesize].to = y;
	head[x] = edgesize;
}

inline void Tarjan(int u) {
	dfn[u] = low[u] = ++depth;
	st[++top] = u;
	instack[u] = true;
	for(register int i = head[u],v;i;i = edge[i].nxt) {
		v = edge[i].to;
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		} else if(instack[v]) low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u]) {
		col[u] = ++cnt;
		instack[u] = false;
		while(st[top] != u) {
			instack[st[top]] = false;
			col[st[top--]] = cnt;
		}
		top--;
	}
}

int main () {
	scanf("%d%d%d",&n,&m,&s);
	for(register int i = 1;i <= m; ++i) {
		scanf("%d%d",&savx[i],&savy[i]);
		addedge(savx[i],savy[i]);
	}
	for(register int i = 1;i <= n; ++i)
		if(!dfn[i]) Tarjan(i);
	for(register int i = 1;i <= m; ++i)
		if(col[savx[i]] != col[savy[i]])
			in[col[savy[i]]]++;
	for(register int i = 1;i <= cnt; ++i)
		if(!in[i]) ans++;
	if(!in[col[s]]) ans--;
	printf("%d\n",ans);
	return 0;
}