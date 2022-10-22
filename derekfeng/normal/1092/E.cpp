#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<int>g[1004];
pii L[1004];
int dist,ans=1e9,cnt,f[1004];
int vis[1004];
int mn[1004];
void dfs(int x,int fa){
	vis[x]=fa;
	L[x]={0,x};
	for(auto y:g[x])if(!vis[y]){
		dfs(y,fa);
		if(L[x].fi+L[y].fi+1>dist)dist=L[x].fi+L[y].fi+1;
		if(L[y].fi+1>L[x].fi)L[x]={L[y].fi+1,L[y].se};
	}
}
void dfs1(int x,int fa,int d,int s){
	f[s]=max(f[s],d);
	for(auto y:g[x])if(y!=fa)
		dfs1(y,x,d+1,s);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,++cnt);
	if(m==n-1){
		printf("%d",dist);
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs1(i,0,0,i);
		if(mn[vis[i]]==0||f[mn[vis[i]]]>f[i])mn[vis[i]]=i;
	}
	int p;
	for(int i=1;i<=n;i++){
		vector<int>w;
		for(int j=1;j<=cnt;j++)if(j!=vis[i])w.push_back(f[mn[j]]);
		sort(w.begin(),w.end());
		int dis=max(dist,max(f[i]+w.back()+1,(w.size()>1?w[w.size()-2]+w.back()+2:0)));
		if(dis<ans)ans=dis,p=i;
	}
	printf("%d\n",ans);
	for(int i=1;i<=cnt;i++)if(i!=vis[p])printf("%d %d\n",p,mn[i]);
}