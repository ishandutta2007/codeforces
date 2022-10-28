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
	ll n,d,k,i;
	cin>>n>>d>>k;
	if(d>n-1)
	{
		cout<<"NO\n";return 0;
	}
	vector<ll> v(d+1);
	for(i=0;i<d+1;++i)
		v[i]=i+1;
	if(d>1 && k==1)
	{
		cout<<"NO\n";return 0;
	}
	ll zz=d-2;
	ll rem=n-d-1;
	vector<pair<ll,ll>> ans;
	for(i=0;i<d;++i)
		ans.pb({v[i],v[i+1]});
	if(rem==0)
	{
		cout<<"YES\n";
		for(i=0;i<d;++i)
			cout<<v[i]<<" "<<v[i+1]<<endl;
		return 0;
	}
	if(k<=2)
	{
		cout<<"NO\n";return 0;
	}
	ll curr=d+2;
	for(ll tt=1;tt<d;++tt)
	{
		ll dis=min(tt,d-tt);
		vector<ll> operate;
		operate.pb(v[tt]);
		while(dis>0)
		{
			vector<ll> temp;
			while(!operate.empty())
			{
				ll ff=operate.back();operate.pop_back();
				for(ll j=0;j<k-1-(ff==v[tt]);++j)
				{
					if(curr>n)break;
					ans.pb({ff,curr});
					temp.pb(curr);
					++curr;
				}
				if(curr>n)break;
			}
			if(curr>n)break;
			--dis;
			operate=temp;
		}
		if(curr>n)break;
	}
	if(curr<=n)
	{
		cout<<"NO\n";return 0;
	}
	cout<<"YES\n";
	for(auto j:ans)
	{
		cout<<j.F<<" "<<j.S<<endl;
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
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}