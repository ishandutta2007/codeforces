#include<bits/stdc++.h>
using namespace std;
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,ans;
vector<int>g[2004];
int tms,cnt,vis[2004],low[2004],cmp[2004];
stack<int>st;
void dfs(int x,int par){
	vis[x]=low[x]=++tms;
	st.push(x);
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par&&g[x][i]!=x){
		if(vis[g[x][i]])low[x]=min(low[x],vis[g[x][i]]);
		else dfs(g[x][i],x),low[x]=min(low[x],low[g[x][i]]);
	}
	if(low[x]==vis[x]){
		++cnt;
		ans--;
		while(1){
			int u=st.top();st.pop();
			cmp[u]=cnt;
			ans++;
			if(u==x)break;
		}
	}
}
vector<int>G[2003];
int lons[2003],ret,cur;
int dfs1(int x,int par){
	if(G[x].size()<=1)cur++;
	int siz=1;
	lons[x]=1;
	for(int i=0;i<G[x].size();i++)if(G[x][i]!=par&&G[x][i]!=x){
		siz+=dfs1(G[x][i],x);
		int val=lons[G[x][i]];
		ret=max(ret,val+lons[x]);
		lons[x]=max(lons[x],val+1);
	}
	return siz;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,-1),ans++;
	ans--;
	for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)
		if(cmp[i]!=cmp[g[i][j]])G[cmp[i]].push_back(cmp[g[i][j]]);
	for(int i=1;i<=cnt;i++)if(!lons[i]){
		ret=1,cur=0;
		int sz=dfs1(i,-1);
		if(sz==1)continue;
		ans+=sz-(ret-2+cur);
	}
	write(ans);
}