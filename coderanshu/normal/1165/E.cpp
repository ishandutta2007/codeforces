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

int _runtimeTerror_()
{
	ll n;
	cin>>n;
	ll i,a[n],b[n];
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=0;i<n;++i)
		cin>>b[i];
	ll ans=0;
	ll arr[n];
	for(i=0;i<n;++i)
	{
		arr[i]=a[i]*(i+1)*(n-i);
	}
	sort(arr,arr+n,greater<ll>());
	sort(b,b+n);
	for(i=0;i<n;++i)
	{
		ans+=(b[i]*(arr[i]%MM))%MM;
		ans%=MM;
	}
	cout<<ans<<endl;
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