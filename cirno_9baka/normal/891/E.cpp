// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=1000000007;
#define ri register int 
int n,m,i,j,a[5005];
ll f[5005][5005],ans,inv[10005],s=1;
ll C(int n,int m)
{
	ll ans=1;
	for(ri i=n;i>n-m;--i)
		ans=ans*i%M;
	return ans%M;
}
ll qpow(ll a,ll b)
{
	ll s=a,ans=1;
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
	for(ri i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s=s*a[i]%M;
	}
	inv[0]=inv[1]=1;
	for(ri i=2;i<=2*n;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(ri i=1;i<=2*n;++i)
		inv[i]=inv[i]*inv[i-1]%M;
	f[0][0]=1;
	for(ri i=1;i<=n;++i)
	{
		f[i][0]=f[i-1][0]*a[i]%M;
		for(ri j=1;j<=i;++j)
			f[i][j]=(f[i-1][j]*a[i]-f[i-1][j-1])%M;
	}
	for(ri i=0;i<=n&&i<=m;++i)
		ans=(ans+f[n][i]*C(m,i)%M*qpow(n,m-i))%M;
	cout<<((s-ans*qpow(qpow(n,m),M-2))%M+M)%M<<endl;
}