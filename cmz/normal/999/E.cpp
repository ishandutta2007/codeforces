#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int fir[maxn],nxt[maxn],gett[maxn],dfn[maxn],low[maxn],top;
int n,m,s;
int col[maxn],inq[maxn],tot,q[maxn];
int x[maxn],y[maxn],color;
int ind[maxn];
inline void add(int x,int y){
	gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
void tarjan(int x){
	dfn[x]=low[x]=++top; inq[x]=1; q[++tot]=x;
	for (int i=fir[x];i;i=nxt[i]){
		int v=gett[i];
		if (!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		} else 
		if  (inq[v]) low[x]=min(low[x],dfn[v]);
	}
	if (low[x]==dfn[x]){
		++color; 
		while (q[tot+1]!=x){
			col[q[tot]]=color; inq[q[tot]]=0; --tot;
		}
	}
}
int main(){
int aaaaaaaa;
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]);
	} top=0;
	for (int i=1;i<=n;++i) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=m;++i) if (col[x[i]]!=col[y[i]])++ind[col[y[i]]];
	int ans=0;
	for (int i=1;i<=color;++i) 
	if (ind[i]==0&&i!=col[s]) ++ans;
	printf("%d",ans);
	return 0;
}