#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int n,m,T;
int fr[5003][5003],vis[5003],dp[5003][5003]; 
vector<pii>g[5003];
vector<int>num;
void dfs_order(int x){
	vis[x]=1;
	for (int i=0;i<g[x].size();i++)if(!vis[g[x][i].fi])
		dfs_order(g[x][i].fi);
	num.push_back(x);  
}
void output(int pl,int now){
	if (pl!=1) output(fr[pl][now],now-1);
	printf("%d ",pl);
}
int main(){
	for (int i=0;i<5003;i++)for(int j=0;j<5003;j++)dp[i][j]=1e9+1,fr[i][j]=-1;
	cin>>n>>m>>T;
	for (int i=0;i<m;i++){
		int x,y,u;scanf("%d%d%d",&x,&y,&u);
		g[x].push_back(mkp(y,u));
	}
	dfs_order(1);
	dp[1][1]=0;
	reverse (num.begin(),num.end());
	for (int i=0;i<num.size();i++){
		int x=num[i];
		for (int i=2;i<=n;i++)
			for (int j=0;j<g[x].size();j++)
				if (dp[g[x][j].fi][i]>dp[x][i-1]+g[x][j].se){
					dp[g[x][j].fi][i]=dp[x][i-1]+g[x][j].se;
					fr[g[x][j].fi][i]=x;
				}
	}
	int now;
	for (int i=1;i<=n;i++)if(dp[n][i]<=T) now=i;
	printf("%d\n",now);
	output(n,now);
}