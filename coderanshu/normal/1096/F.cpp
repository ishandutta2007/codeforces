#include<bits/stdc++.h>
using namespace std ;

#define MM 1000000007
#define M 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
#define NCR 
ll inv[200000+5],fac_inv[200000+5],fac[200000+5];
void initialize()
{
	ll i;
	inv[1]=1;
	for(i=2;i<=200000;i++)
		inv[i]=power(i,M-2,M)%M; 
	fac[0]=fac[1]=1;
	for(i=2;i<=200000;i++)
		fac[i]=i*fac[i-1]%M;
	fac_inv[0]=fac_inv[1]=1;
	for(i=2;i<=200000;i++)
		fac_inv[i]=inv[i]*fac_inv[i-1]%M;
}
ll ncr(ll n,ll r)
{
	if(n<r) return 0;
	return (fac[n]*fac_inv[r]%M)*fac_inv[n-r]%M;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;
int _runtimeTerror_()
{
	ll n;
	cin>>n;
	ll i,a[n];
	bool mark[n+1]={0};
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]!=-1)
			mark[a[i]]=true;
	}
	ll ans=0,count=0;
	if(n==1)
	{
		cout<<0<<endl;return 0;
	}
	ordered_set<ll> s1,s2;
	for(i=1;i<=n;++i)
	{
		if(!mark[i])
		{
			++count;
			s1.insert(i);
		}
	}
	ans+=ncr(count,2)*fac[count]%M*power(2,M-2,M)%M;
	ll sfx[n];
	sfx[n-1]=(a[n-1]==-1);
	for(i=n-2;i>=0;--i)
	{
		sfx[i]=sfx[i+1]+(a[i]==-1);
	}
	for(i=n-1;i>=0;--i)
	{
		if(a[i]<0)
			continue;
		s2.insert(a[i]);
		s1.insert(a[i]);
		ll xx=s2.order_of_key(a[i]);
		ans+=xx*fac[count]%M;
		ans%=M;
		ll yy=s1.order_of_key(a[i]);
		ll tt=sz(s1)-1-yy;
		s1.erase(a[i]);
		ll zz=sfx[i];
		ans+=zz*yy%M*fac[count-1]%M;
		ans%=M;
		ans+=tt*fac[count-1]%M*(count-zz)%M;
		ans%=M;
	}
	cout<<ans*fac_inv[count]%M<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}