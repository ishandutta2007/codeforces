#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> g[110000];
int n,m,s,k;
int a[110000];
vector<int> ans[110000];
int q[110000],d[110000];
void work(int typ)
{
	for(int i=1;i<=n;i++)d[i]=-1;
	int head=0,tail=0;
	for(int i=1;i<=n;i++)
		if (a[i]==typ){ d[i]=0; q[++tail]=i; }
	while (head<tail)
	{
		int x=q[++head];
		for(int p:g[x])
			if (d[p]==-1)
			{
				d[p]=d[x]+1;
				q[++tail]=p;
			}
	}
	for(int i=1;i<=n;i++)ans[i].pb(d[i]);
}
int main()
{
	cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=k;i++)work(i);

	for(int i=1;i<=n;i++)
	{
		sort(ans[i].begin(),ans[i].end());
		int sum=0;
		for(int j=0;j<s;j++)sum+=ans[i][j];
		printf("%d%c",sum,i==n?'\n':' ');
	}

	return 0;
}