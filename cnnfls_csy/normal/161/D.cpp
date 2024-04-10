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
vector<long long> bi[100005],dis;
long long n,m,i,j,gen,sum,dp[100005],vis[100005],sz[100005],dep[100005],x,y,z;
long long ans;
void getrt(long long x,long long fa)
{
	long long i;
	sz[x]=1;
	dp[x]=0;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa||vis[bi[x][i]]) continue;
		getrt(bi[x][i],x);
		sz[x]+=sz[bi[x][i]];
		dp[x]=max(dp[x],sz[bi[x][i]]);
	}
	dp[x]=max(dp[x],sum-sz[x]);
	if (dp[x]<dp[gen]) gen=x;
}
void getdis(long long x,long long fa)
{
	long long i;
	dis.push_back(dep[x]);
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa||vis[bi[x][i]]) continue;
		dep[bi[x][i]]=dep[x]+1;
		getdis(bi[x][i],x);
	}
}
long long getans(long long x,long long v)
{
	long long i;
	dep[x]=v;
	dis.clear();
	getdis(x,0);
	sort(dis.begin(),dis.end());
	long long l=1,r=dis.size(),sum=0;
	while (l<r)
	{
		if (dis[l-1]+dis[r-1]<m) l++;
		else if (dis[l-1]+dis[r-1]>m) r--;
		else if (dis[l-1]+dis[r-1]==m)
		{
			long long cnt1=1,cnt2=1;
			while (l<r-1&&dis[l]+dis[r-1]==m)
			{
				l++;cnt1++;
			}
			while (l<r-1&&dis[l-1]+dis[r-2]==m)
			{
				r--;cnt2++;
			}
			if (dis[l-1]==dis[r-1])
			{
				sum+=(cnt1+cnt2)*(cnt1+cnt2-1)/2;
			}
			else sum+=cnt1*cnt2;
			l++;
		}
	}
	return sum;
}
void dfs(long long x)
{
	long long i;
	ans+=getans(x,0);
	vis[x]=1;
	for (i=0;i<bi[x].size();i++)
	{
		if (vis[bi[x][i]])  continue;
		ans-=getans(bi[x][i],1);
		sum=sz[bi[x][i]];
		gen=0;
		getrt(bi[x][i],0);
		dfs(gen);
	}
}
int main()
{
	cin>>n>>m;
	ans=0;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dp[0]=1<<30;
	sum=n;
	gen=0;
	getrt(1,0);
	dfs(gen);
	cout<<ans;
	return 0;
}