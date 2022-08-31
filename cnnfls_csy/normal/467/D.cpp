#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,k,x,y,cnt,used[500005],ans1,ans2;
pair<long long,long long> dis[100005];
vector<long long> bi[100005],in;
vector<pair<pair<long long,long long>,long long>/**/> v;
map<string,long long> mp1;
map<long long,string> mp2;
string st,st1;
void dfs(long long x,pair<long long,long long> y)
{
	int i;
	used[x]=1;
	dis[x]=min(dis[x],y);
	y=dis[x];
	for (i=0;i<bi[x].size();i++)
	{
		if (!used[bi[x][i]])
		{
			dfs(bi[x][i],y);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		cnt=0;
		for (j=0;j<st.length();j++)
		{
			st[j]=tolower(st[j]);
			if (st[j]=='r') cnt++;
		}
		if (!mp1.count(st))
		{
			mp1[st]=mp2.size()+1;
			mp2[mp1.size()]=st;
			dis[mp1[st]]=make_pair(cnt,st.length());
			v.push_back(make_pair(dis[mp1[st]],mp1[st]));
		}
		in.push_back(mp1[st]);
	}
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>st>>st1;
		cnt=0;
		for (j=0;j<st.length();j++)
		{
			st[j]=tolower(st[j]);
			if (st[j]=='r') cnt++;
		}
		if (!mp1.count(st))
		{
			mp1[st]=mp2.size()+1;
			mp2[mp1.size()]=st;
			dis[mp1[st]]=make_pair(cnt,st.length());
			v.push_back(make_pair(dis[mp1[st]],mp1[st]));
		}
		cnt=0;
		for (j=0;j<st1.length();j++)
		{
			st1[j]=tolower(st1[j]);
			if (st1[j]=='r') cnt++;
		}
		if (!mp1.count(st1))
		{
			mp1[st1]=mp2.size()+1;
			mp2[mp1.size()]=st1;
			dis[mp1[st1]]=make_pair(cnt,st1.length());
			v.push_back(make_pair(dis[mp1[st1]],mp1[st1]));
		}
		bi[mp1[st1]].push_back(mp1[st]);
	}
	sort(v.begin(),v.end());
	for (i=0;i<v.size();i++)
	{
		if (!used[v[i].second])
		{
			dfs(v[i].second,v[i].first);
		}
	}
	for (i=0;i<in.size();i++)
	{
		ans1+=dis[in[i]].first;
		ans2+=dis[in[i]].second;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}