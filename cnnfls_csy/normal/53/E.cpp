#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
long long dp[1<<10][1<<10],n,m,k,i,j,l,p,bi[15][15],x,y,ans;
map<pair<int,int>,bool> bi2;
int main()
{
	cin>>n>>m>>k;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		x--;y--;
		bi[x][y]=bi[y][x]=1;
		bi2[make_pair(1<<x,1<<y)]=bi2[make_pair(1<<y,1<<x)]=1;
	}
	for (i=3;i<(1<<n);i++)
	{
		if (__builtin_popcount(i)==2)
		{
			dp[i][i]=bi2[make_pair(i&(-i),i^(i&(-i)))];
		}
		if (__builtin_popcount(i)>2)
		{
			for (j=i;j;j=(j-1)&i)
			{
				int sz=0;
				for (l=0;l<n;l++)
				{
					if (!((1<<l)&j)) continue;
					sz++;
					for (p=0;p<n;p++)
					{
						if (!((1<<p)&i)) continue;
						if (!bi[l][p]) continue;
						if ((1<<p)&j) continue;
						dp[i][j]+=dp[i^(1<<l)][j^(1<<l)^(1<<p)];
						dp[i][j]+=dp[i^(1<<l)][j^(1<<l)];
					}
				}
				dp[i][j]/=sz;
			}
		}
		if (i==(1<<n)-1)
		{
			for (j=i;j;j=(j-1)&i)
			{
				if (__builtin_popcount(j)==k) ans+=dp[i][j]/*/(n-1)*/; 
			}
		}
	}
	cout<<ans;
	return 0;
}