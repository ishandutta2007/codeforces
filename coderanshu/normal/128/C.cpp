#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
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
ll inv[2000+5],fac_inv[2000+5],fac[2000+5];
void initialize()
{
	ll i;
	inv[1]=1;
	for(i=2;i<=2000;i++)
		inv[i]=(M-M/i)*inv[M%i]%M; 
	fac[0]=fac[1]=1;
	for(i=2;i<=2000;i++)
		fac[i]=i*fac[i-1]%M;
	fac_inv[0]=fac_inv[1]=1;
	for(i=2;i<=2000;i++)
		fac_inv[i]=inv[i]*fac_inv[i-1]%M;
}
ll ncr(ll n,ll r)
{
	if(n<r) return 0;
	return (fac[n]*fac_inv[r]%M)*fac_inv[n-r]%M;
}

int _runtimeTerror_()
{
	ll n,m,k;
	cin>>n>>m>>k;
	if(2*k>=n || 2*k>=m)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<ncr(n-1,2*k)*ncr(m-1,2*k)%M<<endl;

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