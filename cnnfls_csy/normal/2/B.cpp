#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define pb push_back
using namespace std;
int n,m,i,j,k,a[1005][1005][2],dp[1005][1005][2],la[1005][1005][2],zx,zy,yz[2]={2,5},x;
void zero(int zx,int zy)
{
	int i;
	cout<<"1\n";
	for (i=1;i<zx;i++) cout<<'D';
	for (i=1;i<zy;i++) cout<<'R';
	for (i=zx;i<n;i++) cout<<'D';
	for (i=zy;i<n;i++) cout<<'R';
}
void out(int z)
{
	cout<<dp[n][n][z]<<endl;
	int i,j,x,y;
	string w;
	x=y=n;
	while (x>1||y>1)
	{
		if (la[x][y][z])
		{
			w.pb('R');
			y--;
		}
		else
		{
			w.pb('D');
			x--;
		}
	}
	reverse(w.begin(),w.end());
	cout<<w;
	return;
}
int main()
{
	zx=zy=-1;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if (!x)
			{
				zx=i;
				zy=j;
			}
			for (k=0;k<=1;k++)
			{
				for (;x&&x%yz[k]==0;x/=yz[k]) a[i][j][k]++;
			}
		}
	}
	for (i=2;i<=n;i++) dp[i][0][0]=dp[0][i][0]=dp[i][0][1]=dp[0][i][1]=1<<25;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			for (k=0;k<=1;k++)
			{
				if (dp[i-1][j][k]<dp[i][j-1][k])
				{
					dp[i][j][k]=dp[i-1][j][k];
					la[i][j][k]=0;
				}
				else
				{
					dp[i][j][k]=dp[i][j-1][k];
					la[i][j][k]=1;
				}
				dp[i][j][k]+=a[i][j][k];
			}
		}
	}
	k=0;
	if (dp[n][n][0]>dp[n][n][1]) k=1;
	if (!min(dp[n][n][0],dp[n][n][1])||zx==-1) out(k); else zero(zx,zy); 
	return 0;
}