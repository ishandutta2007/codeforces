/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=3000;
int n;
vector<int> nei[N+1];
int fa[N+1],dep[N+1],sz[N+1];
void dfs(int x=1){
	sz[x]=1;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa[x])continue;
		fa[y]=x;
		dep[y]=dep[x]+1;
		dfs(y);
		sz[x]+=sz[y];
	}
}
int fa0[N+1][N+1];
int f[N+1][N+1];
int dp(int x,int y){
	if(~f[x][y])return f[x][y];
	return f[x][y]=max(dp(fa[x],y),dp(x,fa[y]))+sz[x]*sz[y];
}
signed main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++){
		int x=i,now=0;
		fa0[i][0]=i;
		while(x=fa[x])fa0[i][++now]=x;
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int j=1;j<=n;j++)for(int i=1;i<=n;i++)if(fa0[i][j])
		f[i][fa0[i][j]]=f[fa0[i][j]][i]=max(f[fa[i]][fa0[i][j]],f[i][fa0[i][j-1]])+sz[i]*(sz[1]-sz[fa0[i][j-1]]);
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans=max(ans,dp(i,j))/*,printf("dp(%lld,%lld)=%lld\n",i,j,dp(i,j))*/;
	cout<<ans;
	return 0;
}
/*1
5
1 2 2 3 3 4 3 5
*/