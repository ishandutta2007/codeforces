#include<bits/stdc++.h>
using namespace std;
int n,m,a,x;
vector<int>v[201];
bool vis[201];
void dfs(int s)
{
	for(int i=0;i<v[s].size();i++)
		if(!vis[v[s][i]])
			vis[v[s][i]]=1,
			dfs(v[s][i]);
}
int main()
{
	cin>>n>>m;
	bool can=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		can=(a|can);
		for(int j=0;j<a;j++)
			cin>>x,
			v[i].push_back(x+n-1),
			v[x+n-1].push_back(i);
	}
	if(!can)
	{
		cout<<n;
		return 0;
	}
	int ans=-1;
	for(int i=0;i<n;i++)
		if(!vis[i])
			vis[i]=1,
			dfs(i),
			ans++;
	cout<<ans;
}