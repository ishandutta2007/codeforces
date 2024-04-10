#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,m;
int vis[100004];
vector<int>a[100004],b[100004];
void dfs(int x,int col){
	vis[x]=col;
	for(int i=0;i<a[x].size();i++){
		int to=a[x][i],w=b[x][i];
		if(w==0)w=col^1;
		else w=col;
		if(vis[to]>-1){if(vis[to]!=w){puts("0");exit(0);}}
		else dfs(to,w);
	}
}
int main(){
	memset(vis,-1,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		a[u].push_back(v),b[u].push_back(w);
		a[v].push_back(u),b[v].push_back(w);
	}
	dfs(1,0);
	int ans=1;
	for(int i=2;i<=n;i++)if(vis[i]<0)dfs(i,0),ans=ans*2%MOD;
	printf("%d",ans);
}