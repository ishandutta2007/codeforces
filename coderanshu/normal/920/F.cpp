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
	return (!e)?1:power(b*b%m,e/2,m)*(e&1?b:1)%m;
}
ll power( ll b, ll e)
{
	return (!e)?1:power(b*b,e/2)*(e&1?b:1);
}
ll val[1000005];
template<typename T>
class fenwick {
public:
	vector<T> bit;
	ll n;
	fenwick(vector<T> v)
	{
		n=sz(v);
		bit.resize(n);
		for(ll i=1;i<=n;++i)
		{
			update(i,v[i]);
		}
	}
	void update(ll in,T val)
	{
		for(ll j=in;j<=n;j+=j&-j)
			bit[j]+=val;
	}
	T get(ll r)
	{
		T x{};
		while(r>0)
		{
			x+=bit[r];
			r-=r&-r;
		}
		return x;
	}
	T query(ll l,ll r)
	{
		return get(r)-get(l-1);
	}
}; 
int _runtimeTerror_()
{
	ll n,m;
	cin>>n>>m;
	ll i;
	vector<ll> a(n+1);
	set<ll> toupdate;
	for(i=0;i<n;++i)
	{
		cin>>a[i+1];
		if(a[i+1]>2)toupdate.insert(i+1);
	}
	fenwick<ll> fenw(a);
	while(m--)
	{
		ll t,l,r;
		cin>>t>>l>>r;
		if(t==2)
			cout<<fenw.query(l,r)<<endl;
		else
		{
			vector<ll> rm;
			auto it=toupdate.lower_bound(l);
			while(it!=toupdate.end() && *it<=r)
			{
				ll z=val[a[*it]];
				if(z<=2)
					rm.pb(*it);
				fenw.update(*it,z-a[*it]);
				a[*it]=z;
				++it;
			}
			for(auto j:rm)
				toupdate.erase(j);
		}
	}
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
	for(int i=1;i<=1e6;++i)
	{
		for(int j=i;j<=1e6;j+=i)
			val[j]++;
	}
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}