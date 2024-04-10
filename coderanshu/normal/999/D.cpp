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
	ll n,m;
	cin>>n>>m;
	ll a[n],i,b[m]={0};
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		b[a[i]%m]++;
	}
	ll tt=n/m;
	multiset<ll> s;
	for(i=0;i<m;++i)
	{
		if(b[i]==tt)continue;
		if(b[i]<tt)
		{
			for(int j=0;j<tt-b[i];++j)
				s.insert(i);
		}
	}
	//for(auto j:s)
	//	cout<<j<<endl;
	ll temp[m]={0},ans=0;
	for(i=0;i<n;++i)
	{
		temp[a[i]%m]++;
		if(temp[a[i]%m]>tt)
		{
			ll ff=0;
			auto it=s.lower_bound(a[i]%m);
			if(it==s.end())
			{
				//it=s.begin();
				ff=*s.begin()+m-a[i]%m;
				ans+=ff;
				s.erase(s.begin());
			}
			else
			{
				ff=*it-a[i]%m;
				ans+=ff;
				s.erase(s.find(*it));
			}
			--temp[a[i]%m];
			a[i]+=ff;
		}
	}
	cout<<ans<<endl;
	for(i=0;i<n;++i)
		cout<<a[i]<<" ";
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