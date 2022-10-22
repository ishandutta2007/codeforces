#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<int> son[200001],pre[200001],suf[200001];
int dp[200001],ans[200001],fa[200001];
void dfs_dp(int x=1){
	int i;
	dp[x]=1;
	for(i=0;i<son[x].size();i++)
		dfs_dp(son[x][i]),dp[x]=1ll*dp[x]*(dp[son[x][i]]+1)%mod;
	for(i=0;i<son[x].size();i++){
		int to=son[x][i],rto=son[x][son[x].size()-i-1];
		pre[x].push_back(pre[x].empty()?dp[to]+1:1ll*pre[x][i-1]*(dp[to]+1)%mod);
		suf[x].push_back(suf[x].empty()?dp[rto]+1:1ll*suf[x][i-1]*(dp[rto]+1)%mod);
	}
	reverse(suf[x].begin(),suf[x].end());
}
void dfs_change_root(int x=1){
	for(int i=0;i<son[x].size();i++){
		int to=son[x][i],cpy_x=dp[x],cpy_to=dp[to];
		dp[x]=1ll*(i?pre[x][i-1]:1)*(i<son[x].size()-1?suf[x][i+1]:1)%mod;
		if(fa[x])dp[x]=1ll*dp[x]*(dp[fa[x]]+1)%mod;
		dp[to]=1ll*dp[to]*(dp[x]+1)%mod;
		ans[to]=dp[to];
		dfs_change_root(to);
		dp[x]=cpy_x;dp[to]=cpy_to;
	}
}
int main(){
	int n,i;scanf("%d",&n);
	for(i=2;i<=n;i++){scanf("%d",fa+i);son[fa[i]].push_back(i);}
	dfs_dp();
	ans[1]=dp[1];dfs_change_root();
//	cout<<dp[1]<<"\n";
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
/*1
3
1 1
*/
/*2
5
1 2 3 4
*/