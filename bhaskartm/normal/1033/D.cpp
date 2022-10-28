#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
map<ll,ll>mp,mp2;
ll a[666],n;
void doit(ll x)
{
	ll A=(ll)sqrt(x);
	ll B=(ll)(cbrt(x)+1e-6);
	ll C=(ll)sqrt(A);
	if(C*C*C*C==x){mp[C]+=4;return;}
	if(B*B*B==x){mp[B]+=3;return;}
	if(A*A==x){mp[A]+=2;return;}
	for(ll i=1;i<=n;i++)
	{
		ll g=__gcd(x,a[i]);
		if(g==1||a[i]==x)continue;
		ll t=x/g;mp[g]++;mp[t]++;return;
	}
	mp2[x]++;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)doit(a[i]);
	ll ans=1;
	for(map<ll,ll>::iterator it=mp2.begin();it!=mp2.end();it++)(ans*=((*it).second+1)*((*it).second+1)%mod)%=mod;
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)(ans*=((*it).second+1))%=mod;
	printf("%lld\n",ans);	
	return 0;
}