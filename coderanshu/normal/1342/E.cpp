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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#define NCR 
ll inv[3000000+5],fac_inv[3000000+5],fac[3000000+5];
void initialize()
{
	ll i;
	inv[1]=1;
	for(i=2;i<=3000000;i++)
		inv[i]=(M-M/i)*inv[M%i]%M; 
	fac[0]=fac[1]=1;
	for(i=2;i<=3000000;i++)
		fac[i]=i*fac[i-1]%M;
	fac_inv[0]=fac_inv[1]=1;
	for(i=2;i<=3000000;i++)
		fac_inv[i]=inv[i]*fac_inv[i-1]%M;
}
ll ncr(ll n,ll r)
{
	if(n<r) return 0;
	return (fac[n]*fac_inv[r]%M)*fac_inv[n-r]%M;
}

int _runtimeTerror_()
{
	
	ll n,k,i,j;
	cin>>n>>k;
	if(k==0)
	{
		cout<<fac[n]<<endl;return 0;
	}
	ll ans=ncr(n,k)*2%M;
	//cout<<(ncr(n,k)*power(n-k,n,M)*2)%M;
	ll val=n-k,ff=0;
	for(i=val,j=0;i>=0;--i,++j)
	{
		if(j&1)
			ff-=power(i,n,M)*ncr(val,i)%M;
		else
			ff+=power(i,n,M)*ncr(val,i)%M;
		ff+=M;
		ff%=M;
	}
	cout<<ans*ff%M;
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
	cerr<<"\n"<<_time_;
	return 0;
}