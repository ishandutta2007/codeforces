#include<cstdio>
#include<map>
#define ll long long
using namespace std;
const int N=1e5+10,mod=998244353;
ll fastpow(ll a,int b)
{
	ll s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod, b>>=1;
	}
	return s;
}
ll fac[N],ifac[N];
void init(int n)
{
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=fastpow(fac[n],mod-2);
	for(int i=n-1;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
ll C(int a,int b){return fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
ll calc1(int a,int b)
{
	ll ans=0;
	for(int i=0;i<=a&&i<=b;i++)
		ans=(ans+C(a,i)*C(b,i))%mod;
	return ans;
}
ll calc2(int a)
{
	return fastpow(2,a);
}
int n,T,a[N],cnt,tp[N],t1[N],t2[N];
ll s,sum;
map<ll,int> t;
int _get(ll a)
{
	if(!t[a]) t[a]=++cnt;
	if(a*2==sum) tp[t[a]]=1;
	return t[a];
}
int main()
{
	init(1e5);
	scanf("%d",&T);
	while(T--)
	{
		s=sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(s*2>sum) break;
			t1[_get(s)]++;
		}
		s=0;
		for(int i=n;i;i--)
		{
			s+=a[i];
			if(s*2>sum) break;
			t2[_get(s)]++;
		}
		ll ans=1;
		for(int i=1;i<=cnt;i++)
		{
			if(t2[i]==0||t1[i]==0) continue;
			if(tp[i])
			{
				ans=ans*calc2(t1[i]-(sum==0))%mod;
				tp[i]=0;
			}
			else
			{
				ans=ans*calc1(t1[i],t2[i])%mod;
			}
		}
		for(int i=1;i<=cnt;i++) t1[i]=t2[i]=0;
		printf("%lld\n",ans);
		cnt=0,t.clear();
	}
}