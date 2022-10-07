#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=1000005;
int n,t,i,p[N],k,j;
long long fac[N],inv[N];
long long C(int n,int m)
{
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main()
{
	//scanf("%d",&t);
	t=1;
	fac[0]=inv[0]=inv[1]=1;
	for(i=2;i<=1000000;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=1000000;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	while(t--)
	{
		scanf("%d",&n);
		int tmp=n;
		int u=0;
		while(tmp)
		{
			tmp/=2;
			++u;
		}
		tmp=n;
		long long ans=1;
		for(i=u-1;i>=0;--i)
		{
			ans=ans*C(tmp-1,n/(1ll<<i)-n/(1ll<<i+1)-1)%M*fac[n/(1ll<<i)-n/(1ll<<i+1)]%M;
			tmp=n-n/(1<<i);
		}
		tmp=n/3;
		int y=0;
		while(tmp)
		{
			tmp/=2;
			++y;
		}
		if(y+1==u)
		{
			--y;
			for(i=y+1;i>=1;--i)
			{
				p[i]=3;
				for(j=1;j<=y+1;++j)
					if(i!=j)
						p[j]=2;
				p[0]=1;
				p[y+2]=n+1;
				for(j=1;j<=y+1;++j)
					p[j]=p[j]*p[j-1]%M;
				int tmp=n;
				long long s=1;
				for(j=y+1;j>=0;--j)
				{
					s=s*C(tmp-1,n/p[j]-n/p[j+1]-1)%M*fac[n/p[j]-n/p[j+1]]%M;
					tmp=n-n/p[j];
				}
				ans=(ans+s)%M;
			}
		}
		cout<<(ans%M+M)%M<<endl;
	}
}