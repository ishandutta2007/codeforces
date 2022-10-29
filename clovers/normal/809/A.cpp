#include <bits/stdc++.h>
#define m_k make_pair
#define inf 0x3f3f3f3f
#define mod 1000000007
#define int long long
using namespace std;
const int N=3*1e5+100;
int n,a[N],z[N],sum[N],sz[N],ans;
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1ll) ans=(ans*a)%mod;
		b>>=1ll;
		a=(a*a)%mod;
	}
	return ans;
}
signed main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	z[0]=1;
	for (int i=1;i<=n;i++) z[i]=(z[i-1]+z[i-1])%mod;
	for (int i=1;i<=n;i++) sz[i]=(sz[i-1]+z[i])%mod;
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+(z[i]*a[i])%mod)%mod;
	for (int i=1;i<n;i++)
	{
		int num=(sum[n]-sum[i]+mod)%mod,tmp=(sz[n]-sz[i]+mod)%mod;
		tmp=(tmp*a[i])%mod;
		num=(num-tmp+mod)%mod;
		num=(num*m_pow(z[i+1],mod-2))%mod;
		ans=(ans+num)%mod;
	}
	printf("%lld\n",ans%mod);
}