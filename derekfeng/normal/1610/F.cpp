#include<bits/stdc++.h>
using namespace std;
int n,m,N;
int u[600004],v[600004],w[600004],deg[300004];
int res,ans[600004],f[600004],del[600004],q[600004];
vector<int>g[300005];
set<int>E[2][300005];
bool vis[300005],used[600005];
void dfs(int x){
	vis[x]=1;
	for(auto y:g[x])if(!used[y]){
		used[y]=1;
		int p=u[y]^v[y]^x;
		if(u[y]==x)ans[y]=0;
		else ans[y]=1;
		if(!vis[p])dfs(p);
	}
}
int main(){
	scanf("%d%d",&n,&m),N=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		deg[u[i]]+=w[i],deg[v[i]]+=w[i],w[i]--;
		if(u[i]!=v[i])E[w[i]][u[i]].insert(i),E[w[i]][v[i]].insert(i);
	}
	for(int i=1;i<=n;i++)if(deg[i]&1)res++;
	for(int i=1;i<=N;i++)if(!del[i]&&u[i]!=v[i]){
		if(E[w[i]][u[i]].size()>1){
			int a=i;
			E[w[i]][u[i]].erase(a),E[w[i]][u[a]^v[a]^u[i]].erase(a);
			int b=(*E[w[i]][u[i]].begin());
			E[w[i]][u[i]].erase(b),E[w[i]][u[b]^v[b]^u[i]].erase(b);
			++N;
			f[a]=N,f[b]=N;
			del[a]=del[b]=1;
			if(u[a]==u[i])q[a]=1;
			if(v[b]==u[i])q[b]=1;
			a=u[a]^v[a]^u[i],b=u[b]^v[b]^u[i];
			u[N]=a,v[N]=b,w[N]=w[i];
			if(a!=b)E[w[i]][a].insert(N),E[w[i]][b].insert(N);
		}else if(E[w[i]][v[i]].size()>1){
			int a=i;
			E[w[i]][v[i]].erase(a),E[w[i]][u[a]^v[a]^v[i]].erase(a);
			int b=(*E[w[i]][v[i]].begin());
			E[w[i]][v[i]].erase(b),E[w[i]][u[b]^v[b]^v[i]].erase(b);
			++N;
			f[a]=N,f[b]=N;
			del[a]=del[b]=1;
			if(u[a]==v[i])q[a]=1;
			if(v[b]==v[i])q[b]=1;
			a=u[a]^v[a]^v[i],b=u[b]^v[b]^v[i];
			u[N]=a,v[N]=b,w[N]=w[i];
			if(a!=b)E[w[i]][a].insert(N),E[w[i]][b].insert(N);
		}
	}
	for(int i=1;i<=N;i++)if(!del[i]&&u[i]!=v[i])
		g[u[i]].push_back(i),g[v[i]].push_back(i);
	for(int i=1;i<=n;i++)if(!vis[i]&&g[i].size()==1)dfs(i);
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=N;i;i--){
		if(u[i]==v[i])ans[i]=1;
		else if(del[i])ans[i]=ans[f[i]]^q[i];
	}
	printf("%d\n",res);
	for(int i=1;i<=m;i++)putchar(ans[i]+'1');
}