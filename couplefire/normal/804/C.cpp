#include <bits/stdc++.h>
using namespace std;
const int N=300008;
int n,m,lt[N],res[N],sum,ans=1;
struct edge{
	int u,v,nt;
}eg[N*2];
vector <int> cl[N];
int cmp(int x,int y)
{
	return res[x]<res[y];
}
void dfs(int u,int fa)
{
	sort(cl[u].begin(),cl[u].end(),cmp);
	int col=ans,p=cl[u].size()-1;
	for (auto x:cl[u])
	{
		if (res[x]) continue;
		while (p>=0 && col==res[cl[u][p]]) p--,col--;
		res[x]=col--;
	}
	for (int i=lt[u];i;i=eg[i].nt)
	{
		if (eg[i].v!=fa) dfs(eg[i].v,u);
	}
}
void add(int u,int v)
{
	eg[++sum]=(edge){u,v,lt[u]};lt[u]=sum;
}
int main()
{
	cin.sync_with_stdio(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int num;cin>>num;
		ans=max(ans,num);
		for (int j=1;j<=num;j++)
		{
			int x;cin>>x;
			cl[i].push_back(x);
		}
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs(1,0);
	cout<<ans<<endl;
	for (int i=1;i<=m;i++) cout<<max(1,res[i])<<" ";
}