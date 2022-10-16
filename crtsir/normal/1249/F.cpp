#include<bits/stdc++.h>
using namespace std;
int n,d,a[203],dp[203][203];
vector<int>v[203];
void dfs(int x,int par=-1){
	dp[x][0]=a[x];
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=par)
		{
			dfs(v[x][i],x),
			dp[v[x][i]][d]=max(dp[v[x][i]][d-1],dp[v[x][i]][d]);
			for(int j=d-1;j>0;j--)
				dp[v[x][i]][j]=dp[v[x][i]][j-1];
			dp[v[x][i]][0]=0;
			for(int j=0;j<=d;j++){
				int tmp=dp[x][j];dp[x][j]=0;
				for(int k=0;k<=d;k++)
					if(j+k>=d)
						dp[x][min(k,j)]=max(dp[x][min(k,j)],dp[v[x][i]][k]+tmp);
			}
		}
}
int main(){
	cin>>n>>d;d++;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;v[x].push_back(y);v[y].push_back(x);
	}
	dfs(1);
	int ans=0;
	for(int i=0;i<=d;i++)ans=max(ans,dp[1][i]);
	cout<<ans;
}