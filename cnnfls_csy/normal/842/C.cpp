#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,dp[200005],num[200005],x,y,used[200005],dp3[200005];
set<int> dp2[200005];
vector<int> bi[200005];
int gcd(int x,int y)
{
	if (y) return gcd(y,x%y);
	return x;
}
void dfs2(int x,int fa)
{
	if (used[x]) return;
	used[x]=1;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa) continue;
		dp[bi[x][i]]=gcd(num[bi[x][i]],dp[x]);
		for (set<int>::iterator it=dp2[x].begin();it!=dp2[x].end();it++)
		{
			dp2[bi[x][i]].insert(gcd(num[bi[x][i]],*it));
		}
		dp2[bi[x][i]].insert(dp[x]);
		dfs2(bi[x][i],x);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++) cin>>num[i];
	for (i=1;i<n;i++)
	{
		 cin>>x>>y;
		 bi[x].push_back(y);
		 bi[y].push_back(x);
	}
	memset(used,0,sizeof(used));
	dp[1]=num[1];
	dp2[1].insert(0);
	dfs2(1,0);
	for (i=1;i<=n;i++) cout<<max(dp[i],*dp2[i].rbegin())<<' ';
	return 0;
}