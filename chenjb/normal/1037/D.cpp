#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n;
vector<int> g[230000];
int d[230000],sum[230000],a[230000],f[230000];
void dfs(int x,int pre)
{
	for(auto p:g[x])
		if (p!=pre)
		{
			d[p]=d[x]+1;
			dfs(p,x);
		}
}
int main()
{
	cin>>n;
	rep(i,n)g[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	rep(i,n)scanf("%d",&a[i]);
	memset(d,255,sizeof(d));
	d[1]=1;
	dfs(1,0);
	rep(i,n)f[i]=2147483647;
	if (a[1]!=1){ puts("No"); return 0; }
	f[1]=0;
	for(int i=1;i<=n;i++)
		for(auto p:g[a[i]])
			f[p]=min(f[p],i+1);
	//rep(i,n)cout<<f[i]<<endl;
	for(int i=1;i<n;i++)if (f[a[i]]>f[a[i+1]]){ puts("No"); return 0; }
	puts("Yes");
}