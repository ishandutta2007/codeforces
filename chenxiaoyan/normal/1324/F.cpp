/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n;
bool a[N+1];
vector<int> nei[N+1];
int dp[N+1];
void dfs(int x=1,int fa=0){
	dp[x]=a[x]?1:-1;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dfs(y,x);
		dp[x]+=max(0,dp[y]);
	}
}
int ans[N+1];
void dfs0(int x=1,int fa=0){
	ans[x]=dp[x];
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dp[x]-=max(0,dp[y]);
		dp[y]+=max(0,dp[x]);
		dfs0(y,x);
		dp[y]-=max(0,dp[x]);
		dp[x]+=max(0,dp[y]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	dfs0();
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}