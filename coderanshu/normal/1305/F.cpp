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
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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
const int N=200005;
ll a[N],n;
ll solve(ll num)
{
	ll i;
	vector<ll> pr;
	for(i=2;i*i<=num;++i)
	{
		if(num%i==0)
		{
			pr.pb(i);
			while(num%i==0)
				num/=i;
		}
	}
	if(num>1)pr.pb(num);
	ll ret=INF;
	for(auto j:pr)
	{
		ll fof=0;
		for(i=0;i<n;++i)
		{
			if(a[i]%j>=j-a[i]%j)
				fof+=j-a[i]%j;
			else if(a[i]-a[i]%j>0)
				fof+=a[i]%j;
			else fof+=j-a[i]%j;

		}
		ret=min(ret,fof);
	}
	return ret;
}
int _runtimeTerror_()
{
	ll i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	shuffle(a,a+n,rng);
	ll count=20;
	ll ans=n;
	while(count--)
	{
		ll num=a[rng()%n];
		ans=min(ans,solve(num));
		if(num-1>0)
			ans=min(ans,solve(num-1));
		ans=min(ans,solve(num+1));
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
	cerr<<"\n"<<_time_;
	return 0;
}