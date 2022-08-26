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
int n,m,i,j,k,l,start[200005],cnt,rd[200005],x,ti[200005],tim,used[200005];
vector<pair<int,int>/**/> num;
vector<int> ans;
vector<int> bi[200005];
bool cmp(int x,int y)
{
	return ti[x]>ti[y];
} 
void dfs(int x)
{
	used[x]=1;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (!used[bi[x][i]]) dfs(bi[x][i]);
	}
	ti[x]=++tim;
}
int main()
{
	ios::sync_with_stdio(0); 
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		start[i]=num.size();
	 	for (j=1;j<=m;j++)
	 	{
		 	cin>>x;
		 	if (x!=-1)
			{
				num.push_back(make_pair(x,j));
			}
		}
		sort(num.begin()+start[i],num.end()); 
	} 
	start[n+1]=num.size();
	cnt=m+1;
	for (i=1;i<=n;i++)
	{
		for (j=start[i];j<start[i+1];j=k)
		{
			for (k=j;k<start[i+1];k++)
			{
				if (num[k].first!=num[j].first)
				{
					break;
				}
			}
			for (l=j;l<k;l++)
			{
				if (j>start[i]) 
				{
					bi[cnt-1].push_back(num[l].second);
					rd[num[l].second]++;
				}
				if (k<start[i+1]) 
				{
					bi[num[l].second].push_back(cnt);
					rd[cnt]++;
				}
			}
			if (k<start[i+1]) cnt++;
		}
	}
/*	for (i=1;i<cnt;i++)
	{
		cerr<<i<<':';
		for (j=0;j<bi[i].size();j++)
		{
			cerr<<bi[i][j]<<' ';
		}
		cerr<<endl;
	}*/
	for (i=1;i<cnt;i++)
	{
		if (!rd[i])
		{
			dfs(i);
		}
		ans.push_back(i);
	}
	tim=0;
	for (i=1;i<cnt;i++)
	{
		if (!ti[i])
		{
			cout<<-1;
			return 0;
		}
	}
	for (i=1;i<cnt;i++)
	{
		for (j=0;j<bi[i].size();j++)
		{
			if (ti[bi[i][j]]>ti[i])
			{
				cout<<-1;
				return 0;
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp); 
	for (i=0;i<ans.size();i++)
	{
		if (ans[i]<=m) cout<<ans[i]<<' ';
	}
	return 0;
}