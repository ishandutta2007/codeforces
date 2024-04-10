#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,q;
vector < int > v[1000005];
int a,b;
int t,s;
int dp[1000005];
int global=1e9;
int last=0;
void dfs(int node, int prev)
{
	for(auto it: v[node])
	{
		if(it!=prev)
		{
			dp[it]=min(dp[node],it);
			dfs(it,node);
		}
	}
}
int main()
{	
	scanf("%d%d",&n,&q);
	for(int i=0;n-1>i;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin>>t>>s;
	s=(s)%n+1;
	dp[s]=s;
	dfs(s,-1);
	for(int i=1;q>i;i++)
	{
		scanf("%d%d",&t,&s);	
		s=(s+last)%n+1;
		if(t==1)
			global=min(global,dp[s]);
		else
			printf("%d\n",min(global,dp[s])),last=min(global,dp[s]);
	}	
    return 0;	
}