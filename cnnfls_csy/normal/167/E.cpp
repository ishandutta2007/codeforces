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
int n,m,i,j,k,mod,dp[605][605],rd[605],xs[605][605],ans=1,sz;
vector<int> ts,bi[605],nbi[605],nrd,ncd;
long long qp(long long x,long long y)
{
	if (y==0) return 1;
	if (y==1) return x;
	long long z=qp(x,y/2);
	z=z*z%mod;
	if (y&1) z=z*x%mod;
	return z;
}
int dfs(int x,int y)
{
	if (x==y) return 1;
	if (dp[x][y]!=-1) return dp[x][y];
	int i;
	dp[x][y]=0;
	for (i=0;i<nbi[y].size();i++)
	{
		dp[x][y]+=dfs(x,nbi[y][i]);
		dp[x][y]%=mod;
	}
	return dp[x][y];
}
int main()
{
	scanf("%d%d%d",&n,&m,&mod); 
	for (i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		nbi[y].push_back(x);
		rd[y]++;
	}
	for (i=1;i<=n;i++)
	{
		if (rd[i]==0) nrd.push_back(i);
		if (bi[i].size()==0) ncd.push_back(i);
	}
	sz=nrd.size();
	memset(dp,-1,sizeof(dp)); 
	for (i=0;i<sz;i++)
	{
		for (j=0;j<sz;j++)
		{
			xs[i][j]=dfs(nrd[i],ncd[j]);
		}
	}
	long long cnt=0;
	for (i=0;i<sz;i++)
	{
		for (j=i;j<sz;j++) if (xs[j][i]) break;
		for (k=i;k<sz;k++) swap(xs[i][k],xs[j][k]);
		if (j!=i) cnt++;
		for (j=i+1;j<sz;j++)
		{
			if (xs[j][i]==0) continue;
			long long t=xs[j][i]*qp(xs[i][i],mod-2)%mod;
			for (k=i;k<sz;k++)
			{
				xs[j][k]=((xs[j][k]-((long long)xs[i][k])*t)%mod+mod)%mod;
			}
		}
	}
	//cerr<<cnt<<endl;
	if (cnt&1) ans=mod-1;
	for (i=0;i<sz;i++)
	{
		ans=((long long)(ans))*xs[i][i]%mod;
	}
	cout<<ans;
	return 0;
}