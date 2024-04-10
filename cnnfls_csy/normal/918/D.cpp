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
int n,m,i,j,k,l,dp[105][105][27],x,y,rd[105],id[105],cd[105];
char c;
vector<int> bi[105],fbi[105][26],tuopu,nrd;
/*bool cmp(ii x,ii y)
{
	if (x.c>y.c) return 1;
	if (x.c<y.c) return 0;
	if (id[x.y]>id[y.y]) return 1;
	if (id[x.y]<id[y.y]) return 0;
	if (id[x.x]>id[y.x]) return 1;
	if (id[x.x]<id[y.x]) return 0;
}*/
/*void dfs(int x)
{
	int i;
	tuopu.push_back(x);
	rd[x]=-1;
	for (i=0;i<bi[x].size();i++)
	{
		rd[bi[x][i]]--;
		if (!rd[bi[x][i]]) dfs(bi[x][i]);
	}
}*/
int dfs(int x,int y,int z)
{
	int i;
	if (dp[x][y][z]!=-1) return dp[x][y][z];
	if (dfs(x,y,z+1)) return dp[x][y][z]=1;
	for (i=0;i<fbi[x][z].size();i++)
	{
		if (!dfs(y,fbi[x][z][i],z)) return dp[x][y][z]=1;
	}
	return dp[x][y][z]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d %c",&x,&y,&c);
		bi[x].push_back(y);
		fbi[x][c-'a'].push_back(y);
		cd[x]++;rd[y]++;
	}
	/*for (i=1;i<=n;i++)
	{
		if (!rd[i]) nrd.push_back(i);
	}
	for (i=0;i<nrd.size();i++)
	{
		if (!rd[nrd[i]]) dfs(nrd[i]);
	}
	reverse(ts.begin(),ts.end());*/
	memset(dp,-1,sizeof(dp));
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			dp[i][j][26]=0;
		}
	}
	/*for (k=26;k>=0;k--)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				dp[ts[i]][ts[j]][k]=dp[ts[i]][ts[j]][k+1];
				for (l=0;l<bi[i][k].size();l++)
				{
					if (!dp[j][bi[i][k][l]][k]) dp*/
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (dfs(i,j,0)) printf("A"); else printf("B");
		}
		puts("");
	}
	return 0;
}