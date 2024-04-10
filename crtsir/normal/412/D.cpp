#include<bits/stdc++.h>
using namespace std;
vector<int>bl[30010],ans;
bool vis[30010];
void dfs(int x)
{
	vis[x]=true;
	for(int i=0;i<bl[x].size();i++)
		if(!vis[bl[x][i]])
			dfs(bl[x][i]);
	ans.push_back(x);
	return;
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>a>>b,
		bl[--b].push_back(--a);
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i);
	if(ans.size()!=n)
		cout<<-1;
	else
		for(int i=n-1;i>-1;i--)
			cout<<ans[i]+1<<' ';
}