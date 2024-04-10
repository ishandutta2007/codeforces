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
int n,m,i,j,k,l,ans=2147480000,x,y,z,can,ll,r,mid,now;
vector<pair<pair<int,int>,int>/**/> t[200005];
bool cmp1(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{
	if (x.first.first<y.first.first) return 1;
	if (x.first.first>y.first.first) return 0;
	return x.second<y.second;
}
bool cmp2(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{
	if (x.first.second<y.first.second) return 1;
	if (x.first.second>y.first.second) return 0;
	return x.second<y.second;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		t[y-x+1].push_back(make_pair(make_pair(x,y),z));
	}
	for (i=1;i<=m;i++)
	{
		sort(t[i].begin(),t[i].end(),cmp1);
		/*for (j=0;j<t[i].size();j++)
		{
			cerr<<'('<<t[i][j].first.first<<','<<t[i][j].first.second<<','<<t[i][j].second<<')';
		}
		cerr<<endl;*/
	}
	for (i=1;i<m;i++)
	{
		j=m-i;
		now=2147480000;
		for (l=r=0;l<t[i].size();l++)
		{
			while (r<t[j].size()&&t[j][r].first.second<t[i][l].first.first)
			{
				if (now>t[j][r].second) now=t[j][r].second;
				r++;
			}
			if (now<2147480000)
			{
				ans=min(ans,now+t[i][l].second);
			}
		}
		/*for (l=can;l<t[j].size();l++)
		{
			if (i==j&&k==l) continue;
			if (t[i][k].first.second<t[j][l].first.first||t[j][l].first.second<t[i][k].first.first)
			{
				ans=min(ans,t[i][k].second+t[j][l].second);
			}
		}*/
	}
	if (ans<2147480000) cout<<ans; else cout<<-1;
	return 0;
}