#include <bits/stdc++.h>
using namespace std;
const int N=345678;
int ans[N];
vector<int>a[N];
vector<int>g[N];

void dfs(int u,int fa,set<int>&s)
{
	set<int>s1;
	set<int>s2;
	vector<int>vv;
	for(auto x:a[u])
	{
		s1.insert(x);
		if(s.count(x))
		{
			s2.insert(ans[x]);
		}
		else
		{
			vv.push_back(x);
		}
	}
	int now=1;
	for(auto x:vv)
	{
		s1.insert(x);
		while(s2.count(now))
		{
			now++;
		}
		ans[x]=now++;
	}
	for(auto v:g[u])
	{
		if(v==fa)continue;
		else 
		{
			dfs(v,u,s1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int t; 
		while(k--)
		{
			cin>>t;
			a[i].push_back(t);
		}
	}
	int u,v;
	for(int i=1;i<=n-1;i++)
	{
		
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	set<int>s;
	dfs(1,-1,s);
	for(int i=1;i<=m;i++)
	{
		if(ans[i]==0)
		{
			ans[i]=1;
		}
	}
	int res=0;
	for(int i=1;i<=m;i++)
	{
		res=max(res,ans[i]);
	}
	cout<<res<<endl;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}