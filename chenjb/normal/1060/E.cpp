
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> g[210000];
int n;
long long ans;
int d[2],son[210000];
void dfs(int x,int pre,int dis)
{
	d[dis%2]++;
	son[x]=1;
	for(auto p:g[x])
	{
		if (p==pre)continue;
		dfs(p,x,dis+1);
		son[x]+=son[p];
		ans=ans+1ll*son[p]*(n-son[p]);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	ans=0;
	dfs(1,0,0);
	//cout<<ans<<endl;
	cout<<(1ll*ans+1ll*d[1]*d[0])/2<<endl;
}