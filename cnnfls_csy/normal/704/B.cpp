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
long long tl[5005],tr[5005],fl[5005],fr[5005],pos[5005],ans,st,ed,mi,ms,f,n,m,i,j;
vector<long long> now;
long long dist(long long x,long long y)
{
	//swap(x,y);
	if (pos[x]<pos[y])
	{
		return pos[y]-pos[x]+tr[y]+fl[x];
	}
	else
	{
		return pos[x]-pos[y]+tl[y]+fr[x];
	}
}
int main()
{
	cin>>n>>st>>ed;
	for (i=1;i<=n;i++)
	{
		cin>>pos[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>tr[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>tl[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>fr[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>fl[i];
	}
	now.push_back(st);
	now.push_back(ed);
	for (i=1;i<=n;i++)
	{
		if (i==st||i==ed) continue;
		mi=1ll<<55;
		ms=0;
		for (j=1;j<now.size();j++)
		{
			if ((f=dist(now[j-1],i)+dist(i,now[j])-dist(now[j-1],now[j]))<mi)
			{
				mi=f;
				ms=j;
			}
		}
		now.insert(now.begin()+ms,i);
	}
	/*for (i=0;i<now.size();i++) cerr<<now[i]<<"->";
	cerr<<endl;*/
	for (i=1;i<now.size();i++) ans+=dist(now[i-1],now[i]);
	cout<<ans;
	return 0;
}