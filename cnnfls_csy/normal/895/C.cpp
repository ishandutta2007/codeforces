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
long long mod=1e9+7,n,m,i,j,dp[2][1<<19],cnt[75],x,msk[75],p2[100005],inv;
bool pri[75];
vector<int> p;
long long qp(long long x,long long y)
{
	if (y<0) return 0;
	if (y==0) return 1;
	if (y==1) return x;
	long long z=qp(x,y/2);
	z=z*z%mod;
	if (y&1) z=z*x%mod;
	return z;
}
int main()
{
	ios_base::sync_with_stdio(0);
	p2[0]=1;
	for (i=1;i<=100000;i++) p2[i]=p2[i-1]*2%mod;
	inv=qp(2,mod-2);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	pri[1]=1;
	for (i=2;i<=70;i++)
	{
		if (pri[i]) continue;
		p.push_back(i);
		for (j=2;i*j<=70;j++) pri[i*j]=1;
	}
	for (i=1;i<=70;i++)
	{
		x=i;
		for (j=0;j<19&&sqr(p[j])<=x;j++)
		{
			while (x%p[j]==0)
			{
				msk[i]^=(1<<j);
				x/=p[j];
			}
		}
		if (x>1) msk[i]^=(1<<(upper_bound(p.begin(),p.end(),x)-p.begin()-1));
		/*cerr<<i<<'=';
		for (j=0;j<19;j++)
		{
			if ((1<<j)&msk[i]) cerr<<p[j]<<'*';
		}
		cerr<<endl;*/
	}
	dp[0][0]=1;
	for (i=1;i<=70;i++)
	{
		if (cnt[i]==0)
		{
			memcpy(dp[i&1],dp[(i-1)&1],sizeof(dp[i&1]));
			continue;
		}
		for (j=0;j<(1<<19);j++)
		{
			dp[i&1][j]=(dp[(i-1)&1][j]*(p2[cnt[i]]*inv%mod)%mod+dp[(i-1)&1][j^msk[i]]*(p2[cnt[i]]*inv%mod)%mod)%mod;
		}
	}
	cout<<dp[0][0]-1;
	return 0;
}