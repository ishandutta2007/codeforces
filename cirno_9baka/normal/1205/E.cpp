#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1000000007;
int n,p,i,j,k,mu[N],vis[N];
long long mi[N],ans;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&p);
	mi[0]=1;
	for(i=1;i<=n;++i)
	{
		mi[i]=mi[i-1]*p%M;
		mu[i]=1;
	}
	for(i=2;i<=n;++i)
		if(!vis[i])
			for(j=i;j<=n;j+=i)
			{
				vis[j]=1;
				mu[j]=-mu[j];
				if(j/i%i==0)
					mu[j]=0;
			}
	for(i=1;i<=n-1;++i)
		for(j=1;j<=(n-1)/i;++j)
		{
			int t=(n-1)/i/j;
			long long s=0;
			for(k=2;k<=t*2;++k)
				s+=(t-abs(t+1-k))*mi[max(i*j*k-n,i)];
			ans=(ans+s*mu[j])%M;
		}
	cout<<(ans*qpow(mi[n],M-2)%M+M)%M;
}