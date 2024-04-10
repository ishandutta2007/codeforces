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
int num[1005][2],dp[1005][2],n,m,i,j,k,l,r,ans;
string st;
int main()
{
	cin>>n>>m>>l>>r;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		st=" "+st;
		for (j=1;j<=m;j++)
		{
			if (st[j]=='.') num[j][0]++;
				else num[j][1]++;
		}
	}
	for (j=1;j<=m;j++)
	{
		num[j][0]+=num[j-1][0];
		num[j][1]+=num[j-1][1];
	}
	/*if (zero()&&m>1)
	{
		cout<<m*l;
		return 0;
	}*/
	//for (i=1;i<=m;i++) cerr<<num[i][0]<<' '<<num[i][1]<<endl;
	//cerr<<endl;   
	for (i=0;i<=m;i++)
    {
        dp[i][0]=dp[i][1]=1<<25;
    }
    for (i=0;i<=r;i++)
    {
        dp[i][0]=num[i][0];
        dp[i][1]=num[i][1];
    }
    for (i=l+1;i<=m;i++)
    {
        for (j=i-l;j>=max(i-r,l);j--)
        {
        	for (k=0;k<=1;k++)
        	{
            	dp[i][k]=min(dp[i][k],num[i][k]-num[j][k]+dp[j][!k]);
            }
        }
    }
	/*for (i=1;i<=m;i++)
	{
		for (j=0;j<=1;j++)
		{
			cerr<<dp[i][j]<<' ';
		}
		cerr<<endl;
	}*/
	cout<<min(dp[m][0],dp[m][1]);
	return 0;
}