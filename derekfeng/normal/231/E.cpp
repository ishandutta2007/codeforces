#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,K,tms,cnt;
int pow2[100004],d[100004];
int vis[100004],low[100004],cmp[100004],siz[100004];
stack<int>st;
vector<int>g[100004],G[100004];
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
			cmp[u]=cnt,siz[cnt]++;
			st.pop();
			if(u==x)break;
		}
	}
}
int p[17][100004],lg[100004];
void dfs1(int x,int par,int depth){
	d[x]=depth,p[0][x]=par;
	for (int i=1;i<=lg[d[x]];++i)if(p[i-1][x])
		p[i][x]=p[i-1][p[i-1][x]];
	for(int i=0;i<G[x].size();i++)if(G[x][i]!=par)
		dfs1(G[x][i],x,depth+1);
}
int lca(int u,int v){
	if (d[u]>d[v]) swap(u,v);
	while (d[u]<d[v])v=p[lg[d[v]-d[u]]][v];
	if (u==v) return u;
	for (int i=lg[d[u]];i>=0;--i)
		if (p[i][u]!=p[i][v]) u=p[i][u],v=p[i][v];
	return p[0][u];
}
int q,per,ans[100004];
vector<int>qry[100004],ed[100004]; 
void dfs2(int x,int par){
	for(int i=0;i<qry[x].size();i++)ans[qry[x][i]]-=2*per;
	per+=(siz[x]>1);
	for(int i=0;i<ed[x].size();i++)ans[ed[x][i]]+=per;
	for(int i=0;i<G[x].size();i++)if(G[x][i]!=par)
		dfs2(G[x][i],x);
	per-=(siz[x]>1);
}
int main(){
	pow2[0]=1;
	for(int i=1;i<=1e5;i++)pow2[i]=pow2[i-1]*2%MOD;
	read(n),read(m); 
	for(int i=0;i<17;i++)lg[(1<<i)]=i;for(int i=1;i<=n;i++)lg[i]=max(lg[i],lg[i-1]);
	for(int i=0;i<m;i++){
		int u,v;read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)if(cmp[g[i][j]]!=cmp[i])
		G[cmp[i]].push_back(cmp[g[i][j]]);
	dfs1(1,-1,0);
	read(q);
	for(int i=1;i<=q;i++){
		int u,v;read(u),read(v),u=cmp[u],v=cmp[v]; 
		int L=lca(u,v);
		if(siz[L]>1)ans[i]--;
		qry[L].push_back(i);
		ed[u].push_back(i);
		ed[v].push_back(i);
	}
	dfs2(1,-1);
	for(int i=1;i<=q;i++)write(pow2[ans[i]]),puts("");
}