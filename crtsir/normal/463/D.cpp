//!!// 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5][1003],ans;
int dp[1003];
bool apath[5][1005][1005];
vector<int>v[1003];
int dfs(int x){
	if(dp[x])return dp[x];
	for(int i=0;i<v[x].size();i++)dp[x]=max(dp[x],dfs(v[x][i]));
	dp[x]++;
	return dp[x];
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			a[i][j]--;
			for(int ii=0;ii<j;ii++)apath[i][a[i][ii]][a[i][j]]=1;
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		for(int ii=1;ii<k;ii++)
			apath[0][i][j]&=apath[ii][i][j];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		if(apath[0][i][j])
			v[i].push_back(j);
	for(int i=0;i<n;i++)
		ans=max(ans,dfs(i));
	cout<<ans;
}
//!!//