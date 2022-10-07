#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int M=1000000007;
const int N=200005,E=100005;
const int inf=2147483647;
int T,i,n,m,w;
long long inv[N],fac[N],s,ans;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&w);
		s+=w;
	}
	s%=M;
	fac[0]=1;
	for(i=1;i<=m;++i)
		fac[i]=fac[i-1]*i%M;
	inv[m]=qpow(fac[m],M-2);
	for(i=m-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%M;
	for(i=0;i<m;++i)
		ans=(ans+(i&1?-1:1)*fac[m]*inv[i]%M*inv[m-i]%M*((qpow(m-i,n-1)*n%M*(n-1)+qpow(m-i,n)*n)%M))%M;
	ans=ans*inv[m]%M*qpow(n,M-2)%M;
	cout<<(ans*s%M+M)%M;
}