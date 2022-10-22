#include <bits/stdc++.h>
using namespace std;
int n,m,num;
int f[100004],c[100004],ans=1e9;
vector<int>g[100004];
bool vis[100004];
void dfs(int x){
	vis[x]=1;num++;
	for(auto y:g[x])if(!vis[y])dfs(y);
}
void b(int x,int t){
	for(int i=n;i>=x;i--)f[i]=min(f[i-x]+t,f[i]);
}
void bfsearch(int x){
	if(x>n)return;
	ans=min(ans,f[x]);
	bfsearch(x*10+4),bfsearch(x*10+7);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)f[i]=1e9;
	for(int i=1;i<=n;i++)if(!vis[i]){
		num=0;dfs(i);
		c[num]++;
	}
	for(int i=1;i<=n;i++)if(c[i]){
		for(int j=1;j<=c[i];c[i]-=j,j<<=1)b(j*i,j);
		if(c[i])b(c[i]*i,c[i]);
	}
	bfsearch(4),bfsearch(7);
	if(ans==1e9)puts("-1");
	else printf("%d",ans-1);
}