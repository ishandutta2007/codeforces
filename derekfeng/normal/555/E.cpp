#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void outputno(){
	puts("No");exit(0);
}
int n,m,q,cnt,tms,cmp[200004],vis[200004],low[200004],tr[200004];
vector<int>g[200004],G[200004];
int d[200004],up[200004],down[200004];
stack<int>st;
void dfs(int x,int par){
	vis[x]=low[x]=++tms,st.push(x);
	bool parnum=0;
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]==par){
			if(!parnum)parnum=1;
			else low[x]=min(low[x],vis[par]);
		}else{
			if(!vis[g[x][i]])dfs(g[x][i],x),low[x]=min(low[x],low[g[x][i]]);
			else low[x]=min(low[x],vis[g[x][i]]);
		}
	}
	if(low[x]==vis[x]){
		++cnt;
		while(1){
			int u=st.top();
			cmp[u]=cnt;
			st.pop();
			if(u==x)break;
		}
	}
}
int p[18][200004],lg[200004];
void dfs1(int x,int par,int depth,int w){
	d[x]=depth,p[0][x]=par,tr[x]=w;
	for (int i=1;i<=lg[d[x]];++i)if(p[i-1][x])
		p[i][x]=p[i-1][p[i-1][x]];
	for(int i=0;i<G[x].size();i++)if(G[x][i]!=par)
		dfs1(G[x][i],x,depth+1,w);
}
int lca(int u,int v){
	if (d[u]>d[v]) swap(u,v);
	while (d[u]<d[v])v=p[lg[d[v]-d[u]]][v];
	if (u==v) return u;
	for (int i=lg[d[u]];i>=0;--i)
		if (p[i][u]!=p[i][v]) u=p[i][u],v=p[i][v];
	return p[0][u];
}
void dfs2(int x,int par){
	for(int i=0;i<G[x].size();i++)if(G[x][i]!=par)
		dfs2(G[x][i],x),up[x]+=up[G[x][i]],down[x]+=down[G[x][i]];
	if(up[x]&&down[x])outputno();
}
int main(){
	read(n),read(m),read(q);
	for(int i=0;i<18;i++)lg[(1<<i)]=i;for(int i=1;i<=n;i++)lg[i]=max(lg[i-1],lg[i]);
	for(int i=0;i<m;i++){
		int u,v;read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,-1);
	for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)if(cmp[g[i][j]]!=cmp[i])
		G[cmp[i]].push_back(cmp[g[i][j]]);
	for(int i=1;i<=cnt;i++)if(!d[i])dfs1(i,-1,1,++tms);
	while(q--){
		int u,v;read(u),read(v),u=cmp[u],v=cmp[v];
		if(u==v)continue;
		if(tr[u]!=tr[v])outputno();
		int L=lca(u,v);
		up[u]++,down[v]++,up[L]--,down[L]--;
	}
	for(int i=1;i<=cnt;i++)if(d[i]<2)dfs2(i,-1);
	puts("Yes");
}