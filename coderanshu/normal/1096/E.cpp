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
ll inv[10000+5],fac_inv[10000+5],fac[10000+5];
void initialize()
{
	ll i;
	inv[1]=1;
	for(i=2;i<=10000;i++)
		inv[i]=(M-M/i)*inv[M%i]%M; 
	fac[0]=fac[1]=1;
	for(i=2;i<=10000;i++)
		fac[i]=i*fac[i-1]%M;
	fac_inv[0]=fac_inv[1]=1;
	for(i=2;i<=10000;i++)
		fac_inv[i]=inv[i]*fac_inv[i-1]%M;
}
ll ncr(ll n,ll r)
{
	if(n<0 || r<0)return 0;
	if(n<r) return 0;
	return (fac[n]*fac_inv[r]%M)*fac_inv[n-r]%M;
}

ll solve(ll sc,ll n,ll s)
{
	if(s<0)return 0;
	if(n==0 && s==0)return 1LL;
	ll ret=ncr(s+n-1,n-1);
	for(ll i=1;i<=n;++i)
	{
		ll kk=ncr(s-i*sc+n-1,n-1);
		kk*=ncr(n,i);
		kk%=M;
		if(i&1)ret-=kk;
		else ret+=kk;
		ret+=M;
		ret%=M;
	}
	return ret;
}
int _runtimeTerror_()
{
	ll p,s,r,i;	
	cin>>p>>s>>r;
	ll ans=0;
	for(i=r;i<=s;++i)
	{
		for(ll j=1;j<=p;++j)
		{
			ll fuck=solve(i,p-j,s-i*j);
			ans+=fuck*power(j,M-2,M)%M*ncr(p-1,j-1)%M;
			ans%=M;
		}
	}
	ll tt=ncr(s-r+p-1,p-1);
	cout<<ans*power(tt,M-2,M)%M<<endl;
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