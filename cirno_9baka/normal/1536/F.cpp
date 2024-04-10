#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N=1000005,M=1000000007;
int n,i,j,p[N],k;
long long fac[N],inv[N],ans;
long long C(int n,int m)
{
	if(n<m)
		return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	/*n=20;
	g[0]=1;
	for(i=1;i<=n;++i)
	{
		k=0;
		for(j=0;j<i;++j)
			p[++k]=f[j]^g[i-j-1];
		sort(p+1,p+1+k);
		int l=0;
		for(j=1;j<=k;++j)
			if(p[j]==l)
				++l;
		f[i]=l;
		k=0;
		for(j=0;j<i;++j)
		{
			p[++k]=g[j]^g[i-j-1];
			p[++k]=f[j]^f[i-j-1];
		}
		sort(p+1,p+1+k);
		l=0;
		for(j=1;j<=k;++j)
			if(p[j]==l)
				++l;
		g[i]=l;
	}
	for(i=1;i<=n;++i)
		cout<<f[i]<<' '<<g[i]<<endl;*/
	scanf("%d",&n);
	inv[0]=inv[1]=fac[0]=1;
	for(i=2;i<=n;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	for(i=n-2;i>=0;i-=2)
		ans=(ans+C(n-i,i)*fac[n-1-i])%M;
	cout<<ans*2*n%M;
}