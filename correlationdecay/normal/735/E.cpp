#include <bits/stdc++.h>
#define maxn 109
using namespace std;
const int MOD=1e9+7;
vector<int>G[maxn];
long long dp[maxn][22][22];
int n,k;
inline void add(long long &x,long long y){
	x+=y;
	if(x>=MOD)
		x-=MOD;
}
void dfs(int u,int fa){
	long long f[2][22][22];
	memset(f,0,sizeof(f));
	int cur=0;
	f[0][0][k+1]=1;
	for(auto v:G[u]){
		if(v==fa)
			continue;
		dfs(v,u);
		memset(f[cur^1],0,sizeof(f[cur^1]));
		for(int i=0;i<=k+1;i++)
			for(int j=0;j<=k+1;j++)
				for(int a=0;a<=k+1;a++)
					for(int b=0;b<=k+1;b++){
						add(f[cur^1][max(a,i)][min(b,j)],f[cur][i][j]*dp[v][a][b]%MOD);
					}
		cur^=1;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<=k+1;j++){
			if(j+1<=k){
				if(i==0||(i+j+1)<=k)
					add(dp[u][0][min(j+1,k+1)],f[cur][i][j]);
				else
					add(dp[u][i+1][min(j+1,k+1)],f[cur][i][j]);
			}
			else{
				add(dp[u][i+1][min(j+1,k+1)],f[cur][i][j]);
			}
		}
	for(int i=0;i<=k;i++){
		for(int j=0;j<=(k+1);j++){
			dp[u][0][0]=(dp[u][0][0]+f[cur][i][j])%MOD;
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,-1);
	long long ans=0;
	for(int i=0;i<=k;i++)
		add(ans,dp[1][0][i]);
	cout<<ans<<endl;
	//system("pause");
	return 0;
}