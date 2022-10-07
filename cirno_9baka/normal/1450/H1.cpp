#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=998244353;
int n,i,m,wb,t,cb;
char c[N];
long long fac[N],inv[N],ans,s;
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
	scanf("%d %d",&n,&m);
	scanf("%s",c+1);
	for(i=1;i<=n;++i)
		if(c[i]=='b')
			++cb;
	for(i=1;i<=n;++i)
		if(i&1)
			if(c[i]=='w')
				c[i]='b';
			else
				if(c[i]=='b')
					c[i]='w';
	fac[0]=inv[0]=inv[1]=1;
	for(i=2;i<=n;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	for(i=1;i<=n;++i)
	{
		if(c[i]=='b')
			++wb;
		if(c[i]=='?')
			++t;
	}
	for(i=n/2%2^wb%2;i<=t;i+=2)
	{
		ans=(ans+abs(wb+i-(n-wb-i))*fac[t]%M*inv[t-i]%M*inv[i])%M;
		//cout<<abs(wb+i-(n-wb-i))<<' '<<fac[t]%M*inv[t-i]%M*inv[i]%M<<endl;
		s=(s+fac[t]%M*inv[t-i]%M*inv[i])%M;
	}
	//cout<<ans*qpow(4,M-2)%M<<' '<<s<<endl;
	cout<<(ans*qpow(s,M-2)%M*qpow(4,M-2)%M+M)%M;
}