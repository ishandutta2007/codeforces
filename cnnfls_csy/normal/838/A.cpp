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
int n,m,i,j,k,cnt[5005][5005],ans=1<<30,sum,x,y;
bool nopri[5005];
char mp[5005][5005];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=5000;i++)
	{
		for (j=1;j<=5000;j++)
		{
			mp[i][j]='0';
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	for (i=1;i<=5000;i++)
	{
		for (j=1;j<=5000;j++)
		{
			cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+mp[i][j]-'0';
		}
	}
	nopri[1]=1;
	for (i=2;i<=max(n,m);i++)
	{
		if (!nopri[i])
		{
			y=sqr(i);
			sum=0;
			for (j=2;i*j<=2500;j++) nopri[i*j]=1;
			for (j=1;j<=n;j+=i)
			{
				for (k=1;k<=m;k+=i)
				{
					x=cnt[j+i-1][k+i-1]-cnt[j+i-1][k-1]-cnt[j-1][k+i-1]+cnt[j-1][k-1];
					sum+=min(x,y-x);
				}
			}
			ans=min(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}