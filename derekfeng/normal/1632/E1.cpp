#include<bits/stdc++.h>
using namespace std;
vector<int>g[300004];
int n;
int dep[300004],f[300004],dp[300004];
void dfs(int x,int fa){
	dp[x]=dep[x];
	for(auto y:g[x])if(y!=fa){
		dep[y]=dep[x]+1,dfs(y,x);
		if(dp[x]>0)f[min(dp[x],dp[y])-1]=max(f[min(dp[x],dp[y])-1],dp[x]+dp[y]-2*dep[x]+1);
		dp[x]=max(dp[x],dp[y]);
	}
	if(dep[x]>0)f[dep[x]-1]=max(f[dep[x]-1],1);
}
void sol(){
	scanf("%d",&n);for(int i=1;i<=n;i++)g[i].clear(),f[i]=0;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=n-2;~i;i--)f[i]=max(f[i+1],f[i]);
	int lim=0;
	for(int i=1;i<=n;i++)lim=max(lim,dep[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		while(ans<lim&&f[ans]/2+i>ans)ans++;
		printf("%d ",ans);
	}
	puts("");
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}