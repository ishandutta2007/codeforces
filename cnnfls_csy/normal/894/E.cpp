#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,num[1000005],dp[1000005],x,y,z,vis[1000005],fa[1000005],cnt,l,r,ans,mid,fi,sum[1000005];
vector<pair<long long,long long>/**/> bi[1000005],nbi[1000005],zbi[1000005];
vector<long long> ts;
void dfs(long long x)
{
	if (vis[x]) return;
	vis[x]=1;
	long long i;
	for (i=0;i<bi[x].size();i++)
	{
		dfs(bi[x][i].first);
	}
	ts.push_back(x);
}
void dfs2(long long x,long long col)
{
	if (fa[x]) return;
	fa[x]=col;
	long long i;
	for (i=0;i<nbi[x].size();i++)
	{
		dfs2(nbi[x][i].first,col);
	}
}
long long dfs3(long long x)
{
	if (dp[x]!=-1) return dp[x];
	dp[x]=0;
	int i;
	for (i=0;i<zbi[x].size();i++)
	{
		dp[x]=max(dp[x],zbi[x][i].second+dfs3(zbi[x][i].first));
	}
	return (dp[x]+=num[x]);
}
int main()
{
	ios::sync_with_stdio(0);
	for (i=1;i<=1000000;i++)
	{
		sum[i]=sum[i-1]+i*(i+1)/2;
	}
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		 cin>>x>>y>>z;
		 bi[x].push_back(make_pair(y,z));
		 nbi[y].push_back(make_pair(x,z));
	}
	for (i=1;i<=n;i++)
	{
		dfs(i);
	}
	for (i=n-1;i>-1;i--)
	{
		x=ts[i];
		if (fa[x]) continue; 
		dfs2(x,++cnt);
	}
	for (i=1;i<=n;i++)
	{
		for (j=0;j<bi[i].size();j++)
		{
			if (fa[i]==fa[bi[i][j].first])
			{
				x=bi[i][j].second;
				if (!x)
				{
					continue;
				}
				l=1;r=x;ans=1;
				while (l<r)
				{
					mid=(l+r)/2;
					if (mid*(mid+1)/2<=x)
					{
						l=mid+1;
						ans=mid;
					}
					else r=mid;
				}
				//num[fa[i]]+=x*ans-ans*(ans+1)/2;
				num[fa[i]]+=x*(ans+1)-sum[ans];
			}
			else
			{
				zbi[fa[i]].push_back(make_pair(fa[bi[i][j].first],bi[i][j].second));
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	cin>>fi;
	cout<<dfs3(fa[fi]);
	return 0;
}