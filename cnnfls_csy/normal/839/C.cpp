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
vector<int> bi[100005];
int n,m,i,j,x,y;
double dp[100005];
double dfs(int x,int fa)
{
	if (dp[x]>0.0001) return dp[x];
	double sum=0,cnt=0;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]!=fa)
		{
			cnt++;
			sum+=dfs(bi[x][i],x);
		}
	}
	if (!cnt) cnt++; 
	dp[x]=sum/cnt;
	if (x!=1) dp[x]++;
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<n;i++)
	{
		 cin>>x>>y;
		 bi[x].push_back(y);
		 bi[y].push_back(x);
	}
	dfs(1,0);
	printf("%.12f",dp[1]);
	return 0;
}