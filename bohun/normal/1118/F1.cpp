#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
int col[300005];
int a,b;
vector < int > v[300005];
int ile[3];
ll ans=0;
int dp[300005][3];
void dfs(int node, int prev)
{
	dp[node][col[node]]++;
	for(auto it: v[node])
	{
		if(it==prev)
			continue;
		dfs(it,node);
		for(int j=0;3>j;j++)
			dp[node][j]+=dp[it][j];
	}
	if(dp[node][1]==ile[1] and dp[node][2]==0)
		ans++;
	if(dp[node][2]==ile[2] and dp[node][1]==0)
		ans++;
}
int main(){
	cin>>n;
	for(int i=1;n>=i;i++)
		{
			cin>>col[i];
			ile[col[i]]++;
		}
	for(int i=0;n-1>i;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1);
	cout<<ans;
    return 0;	
}