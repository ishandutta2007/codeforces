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
#define runSieve
bool notPrime[2760003];
ll divPrime[2760003];
void sieve(int n=2760000)
{
	int k=sqrt(n);
	memf(notPrime);
	notPrime[1]=true;
	for(int i=2;i<=k;++i)
	{
		if(!notPrime[i])
		{
			for(int k=i*i;k<=n;k+=i)
			{
				if(!notPrime[k])
				{
					notPrime[k]=true;
					divPrime[k]=i;
				}
			}
		}
	}
}
vector<ll> pr;
int _runtimeTerror_()
{
	ll n;
	cin>>n;
	multiset<ll,greater<ll> > s;
	multiset<ll> v;
	vector<ll> ans;
	for(ll i=0;i<2*n;++i)
	{
		ll num;
		cin>>num;
		s.insert(num);
	}
	for(auto j:s)
	{
		if(notPrime[j])
		{
			ans.pb(j);
			j/=divPrime[j];
			s.erase(s.find(j));
		}
		else v.insert(j);
	}
	for(auto j:v)
	{
		if(!notPrime[j])
		{
			ans.pb(j);
			v.erase(v.find(pr[j-1]));
		}
	}
	for(auto j:ans)
		cout<<j<<" ";
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
	for(ll i=2;i<=2760000;++i)
		if(!notPrime[i])
			pr.pb(i);
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<endl<<_time_;
	return 0;
}