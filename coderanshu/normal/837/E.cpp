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


int _runtimeTerror_()
{
	ll x,y,i,j;
	cin>>x>>y;
	ll z = __gcd(x,y);
	ll a=x/z,b=y/z;
	ll ans=0;
	ll aa=a;
	vector<ll> pr;
	for(i=2;i*i<=aa;++i)
	{
		if(aa%i==0)
		{
			while(aa%i==0)
				aa/=i;
			pr.pb(i);
		}
	}
	if(aa>1)
		pr.pb(aa);
	//for(auto j:pr)
	//	cout<<j<<endl;
	while(b>1)
	{
		if(a==1)
		{
			ans+=b;
			break;
		}
		ll mx=INF,num=-1;
		for(auto j:pr)
		{
			if(b%j<mx)
			{
				mx=b%j;
				num=j;
			}
		}
		ans+=mx;
		b-=mx;
		ll zz=__gcd(a,b);
		b/=zz;
		a/=zz;
		vector<ll> temp;
		for(auto j:pr)
			if(a%j==0)
				temp.pb(j);
		pr=temp;
	}
	if(b==1)++ans;
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