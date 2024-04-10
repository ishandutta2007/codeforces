#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int a[2100];
ll f[2100][2100],fc[100010],ic[100010];
ll qpow(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) (res*=x)%=mod;(x*=x)%=mod;y>>=1;
	}
	return res;
}
ll C(int n,int m){return fc[n]*ic[m]%mod*ic[n-m]%mod;}
int main()
{
	int n,k,i,j,t,o=0;cin>>n>>k;fc[0]=ic[0]=1;
	for (i=1;i<=n;i++) fc[i]=fc[i-1]*i%mod,ic[i]=qpow(fc[i],mod-2);
	for (i=1;i<=n;i++)
	{
		cin>>t;int u=0;
		for (j=1;j<=10;j++)
		{
			if (t && t%10!=4 && t%10!=7) break;
			if (t) u=u*2+(t%10==7);
			else u+=(1<<j);t/=10;
		}
		if (!t) a[u]++;else o++;
	}
	f[0][0]=1;
	for (i=0;i<2048;i++)
	{
		f[i+1][0]=1;
		for (j=1;j<=i+1;j++)
		{
			f[i+1][j]=f[i][j]+f[i][j-1]*a[i]%mod;
			f[i+1][j]%=mod;
		}
	}
	ll ans=0;
	for (i=0;i<=k && i<=2048;i++) if (k-i<=o)(ans+=f[2048][i]*C(o,k-i)%mod)%=mod;
	cout<<ans;
}