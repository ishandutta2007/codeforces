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
int n,m,q,i,j,k,cnt[15][155][155],cnt1[15][155][155],x,y,xx,yy,t;
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	q++;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y>>t;
		cnt1[t][x][y]++;
	}
	for (k=0;k<=q;k++)
	{
		for (i=1;i<=150;i++)
		{
			for (j=1;j<=150;j++)
			{
				cnt[k][i][j]=cnt[k][i-1][j]+cnt[k][i][j-1]-cnt[k][i-1][j-1]+cnt1[k][i][j];
			}
		}
	}
	/*for (k=0;k<=q;k++)
	{
		for (i=1;i<=3;i++)
		{
			for (j=1;j<=3;j++)
			{
				cerr<<cnt[k][i][j]<<' ';
			}
			cerr<<endl;
		}
		cerr<<endl;
	}*/
	for (i=1;i<=m;i++)
	{
		cin>>t>>x>>y>>xx>>yy;
		ans=0;
		for (j=0;j<=q;j++)
		{
			ans+=(cnt[j][xx][yy]-cnt[j][xx][y-1]-cnt[j][x-1][yy]+cnt[j][x-1][y-1])*((j+t)%q);
		}
		cout<<ans<<endl;
	}
	return 0;
}