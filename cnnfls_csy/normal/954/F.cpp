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
struct ii
{
	long long num[4][4];
}fr,now;
long long dp[4],dp2[4],n,m,i,j,x,l,r,ans,mod=1e9+7;
map<long long,map<long long,long long>/**/> mp2;
void inc(long long x,long long y)
{
	mp2[x][y]++;
}
void dec(long long x,long long y)
{
	mp2[x][y]--;
}
ii mul(ii x,ii y)
{
	int i,j,k;
	ii ans;
	memset(ans.num,0,sizeof(ans.num));
	for (i=1;i<=3;i++)
	{
		for (j=1;j<=3;j++)
		{
			for (k=1;k<=3;k++)
			{
				(ans.num[i][j]+=x.num[i][k]*y.num[k][j])%=mod;
			}
		}
	}
	return ans;
}
ii qp(ii x,long long y)
{
	ii z;
	memset(z.num,0,sizeof(z.num));
	int i;
	for (i=1;i<=3;i++) z.num[i][i]=1;
	while (y)
	{
		if (y&1) z=mul(z,x);
		y/=2;
		x=mul(x,x);
	}
	return z;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	memset(fr.num,0,sizeof(fr.num));
	fr.num[1][1]=fr.num[1][2]=fr.num[2][1]=fr.num[2][2]=fr.num[2][3]=fr.num[3][3]=fr.num[3][2]=1;
	for (i=1;i<=n;i++)
	{
		cin>>x>>l>>r;
		r++;
		inc(l,x);
		dec(r,x);
	}
	mp2[m]=mp2[m];
	dp[2]=1;
	now=fr;
	for (map<long long,map<long long,long long>/**/>::iterator it=mp2.begin();it!=mp2.end();it++)
	{
		if (it!=mp2.begin())
		{
			map<long long,map<long long,long long>/**/>::iterator pre=it;
			pre--;
			for (i=1;i<=3;i++) it->second[i]+=pre->second[i];
			now=qp(now,it->first-pre->first);
		}
		else
		{
			now=qp(now,it->first-1);
		}
		/*cerr<<it->first<<": ";
		for (i=1;i<=3;i++) cerr<<it->second[i]<<' ';
		cerr<<endl;*/
		memset(dp2,0,sizeof(dp2));
		for (i=1;i<=3;i++)
		{
			for (j=1;j<=3;j++)
			{
				dp2[j]+=dp[i]*now.num[i][j];
				dp2[j]%=mod;
			}
		}
		for (i=1;i<=3;i++) if (!it->second[i]) dp[i]=dp2[i]; else dp[i]=0;
		now=fr;
		for (i=1;i<=3;i++)
		{
			for (j=1;j<=3;j++)
			{
				if (it->second[i]) now.num[i][j]=0;
			}
		}
	}
	cout<<dp[2]<<endl;
	return 0;
}