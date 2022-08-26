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
struct cra
{
	int rd,l,r,id;
}num[2005];
vector<int> all;
vector<pair<int,int> > bi[4005];
int n,m,i,j,k,dp[2005][4005],x,pre[2005][4005];
bool cmp(cra x,cra y)
{
	return x.rd<y.rd;
}
void print(int x,int y)
{
	if (y==0) return;
	if (pre[x][y]!=-1)
	{
		printf("%d ",num[pre[x][y]].id);
		print(pre[x][y],y);
		print(x,num[pre[x][y]].l);
	}
	else print(x,y-1);
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&num[i].rd);
		num[i].l=x-num[i].rd;
		num[i].r=x+num[i].rd;
		num[i].id=i;
		all.push_back(num[i].l);
		all.push_back(num[i].r);
	}
	n++;
	num[n]={(int)(2e9),(int)(-2e9-5e8),(int)(2e9+5e8),0};
	all.push_back(num[n].l);
	all.push_back(num[n].r);
	sort(num+1,num+n+1,cmp);
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for (i=1;i<=n;i++)
	{
		num[i].l=upper_bound(all.begin(),all.end(),num[i].l)-all.begin(); 
		num[i].r=upper_bound(all.begin(),all.end(),num[i].r)-all.begin(); 
	}
	for (i=1;i<=n;i++)
	{
		bi[num[i].r].push_back(make_pair(num[i].l,i));
	}
	memset(pre,-1,sizeof(pre));
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=4000;j++) dp[i][j]=-1<<30;
		dp[i][num[i].l]=1;
		for (j=num[i].l+1;j<=num[i].r;j++)
		{
			dp[i][j]=dp[i][j-1];
			for (k=0;k<bi[j].size();k++)
			{
				if (num[bi[j][k].second].rd>=num[i].rd) continue;
				if (bi[j][k].first<num[i].l) continue;
				if (dp[i][bi[j][k].first]+dp[bi[j][k].second][j]>dp[i][j])
				{
					dp[i][j]=dp[i][bi[j][k].first]+dp[bi[j][k].second][j];
					pre[i][j]=bi[j][k].second;
				}
			}
		}
	}
	printf("%d\n",dp[n][num[n].r]-1);
	print(n,num[n].r);
	return 0;
}