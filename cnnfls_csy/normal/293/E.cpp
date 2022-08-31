#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#include<stack>
#define sqr(x) (x)*(x)
using namespace std;
vector<pair<long long,long long>/**/> bi[1000005],dis;
long long n,m,ll,i,j,gen,sum,dp[1000005],vis[1000005],sz[1000005],dep[1000005],dep2[1000005],x,y,z;
long long ans;
struct bit
{
	long long sum[1000005];
	void add(int x,long long y)
	{
		for (;x<=300000;x+=(x&(-x)))
		{
			sum[x]+=y;
		}
	}
	long long query(int x)
	{
		long long ssum=0;
		for (;x;x-=(x&(-x))) 
			ssum+=sum[x];
		return ssum;
	}
}cnts;
void getrt(long long x,long long fa)
{
	long long i;
	sz[x]=1;
	dp[x]=0;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i].first==fa||vis[bi[x][i].first]) continue;
		getrt(bi[x][i].first,x);
		sz[x]+=sz[bi[x][i].first];
		dp[x]=max(dp[x],sz[bi[x][i].first]);
	}
	dp[x]=max(dp[x],sum-sz[x]);
	if (dp[x]<dp[gen]) gen=x;
}
void getdis(long long x,long long fa)
{
	long long i;
	dis.push_back(make_pair(dep[x],dep2[x]));
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i].first==fa||vis[bi[x][i].first]) continue;
		dep[bi[x][i].first]=dep[x]+bi[x][i].second;
		dep2[bi[x][i].first]=dep2[x]+1;
		getdis(bi[x][i].first,x);
	}
}
/*bool cmp(pair<long long> x,pair<long long> y)
{
	if (x.first>y.first) return 1;
	if (x.first<y.first) return 0;
	return x.second<y.second;
}*/
long long getans(long long x,long long v,long long v2)
{
	long long i;
	dep[x]=v;
	dep2[x]=v2;
	dis.clear();
	getdis(x,0);
	sort(dis.begin(),dis.end()/*,cmp*/);
	for (i=0;i<dis.size();i++)
	{
		if (dis[i].second>100000) exit(1);
		if (m-dis[i].second>100000) exit(-1);
	}
	long long l=1,r=dis.size(),sums=0;
	//map<long long,vector<long long>/**/> cnts;
/*	for (i=0;i<dis.size();i++)
	{
		cerr<<dis[i].first<<' '<<dis[i].second<<endl;
		cnts[dis[i].first].push_back(dis[i].second);
	}*/
	stack<pair<int,int>/**/> s;
	for (i=0;i<r;i++)
	{
		//cerr<<dis[i].first<<' '<<dis[i].second<<endl;
		while (r-1>-1&&dis[i].first+dis[r-1].first>ll)
		{
			r--;
			if (i>=r)
			{
				/*cnts.add(dis[r].second+1,-1);
				s.push(dis[r].second+1);
				sums+=cnts.query(m-dis[r].second+1);*/
				//cnts.add(dis[r].second+1,1);
			}
			else if (dis[r].second<=m) sums+=cnts.query(m-dis[r].second+1);
		}
		cnts.add(dis[i].second+1,1);
		s.push(make_pair(dis[i].second+1,-1));
		//if (!cnts.empty())
		//{
			//cerr<<(--cnts.upper_bound(m-dis[i].first))->first<<endl;
			//cerr<<(cnts.upper_bound(m-dis[i].first)==cnts.begin())<<' '<<((--cnts.upper_bound(m-dis[i].first))==(--cnts.begin()))<<endl;
			/*for (map<long long,vector<long long>/**//*>::iterator it=(cnts.upper_bound(m-dis[i].first));it!=cnts.begin();)
			{
				it--;
				sum+=upper_bound(it->second.begin(),it->second.end(),ll-dis[i].second)-it->second.begin();
			}*/
		//}
		//cnts[dis[i].first].push_back(dis[i].second);
		/*for (map<long long,vector<long long>/**//*>::iterator it=cnts.begin();it!=cnts.end();it++)
		{
			cerr<<it->first<<':';
			int j;
			for (j=0;j<it->second.size();j++) cerr<<cnts[it->first][j]<<' ';
			cerr<<endl;
		}*/
	}
	while (r-1>-1)
	{
		r--;
		cnts.add(dis[r].second+1,-1);
		s.push(make_pair(dis[r].second+1,1));
		if (dis[r].second<=m) sums+=cnts.query(m-dis[r].second+1);
		//cnts.add(dis[r].second+1,1);
	}
	//for (i=0;i<dis.size();i++) cnts.add(dis[i].second+1,-1);
	while (!s.empty())
	{
		cnts.add(s.top().first,s.top().second);
		s.pop();
	}
	return sums;
}
void dfs(long long x)
{
	long long i;
	ans+=getans(x,0,0);
	vis[x]=1;
	for (i=0;i<bi[x].size();i++)
	{
		if (vis[bi[x][i].first]) continue;
		ans-=getans(bi[x][i].first,bi[x][i].second,1);
		sum=sz[bi[x][i].first];
		gen=0;
		getrt(bi[x][i].first,0);
		dfs(gen);
	}
}
int main()
{
	memset(cnts.sum,0,sizeof(cnts.sum));
	cin>>n>>m>>ll;
	ans=0;
	for (i=2;i<=n;i++)
	{
		cin>>x>>y;
		bi[x].push_back(make_pair(i,y));
		bi[i].push_back(make_pair(x,y));
	}
	dp[0]=1<<30;
	sum=n;
	gen=0;
	getrt(1,0);
	dfs(gen);
	cout<<ans;
	return 0;
}