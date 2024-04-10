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
#define runSieve SIEVE
bool notPrime[1000005];
ll divPrime[1000005];
void sieve(int n=1000000)
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
				notPrime[k]=true;
				divPrime[k]=i;
			}
		}
	}
}
vector<ll> pr,checkvalue;
ll val,xx;
void factorize(ll k)
{
	while(k!=1 && notPrime[k])
	{
		ll z=divPrime[k];
		pr.pb(z);
		while(k%z==0)k/=z;
	}
	if(k>1)pr.pb(k);
}
void calculate()
{
	ll i,j;
	ll sub=(1<<xx);
	for(i=1;i<sub;++i)
	{
		ll value=1,cnt=0;
		for(j=0;j<xx;++j)
		{
			if(i&(1<<j))
			{
				++cnt;
				value*=pr[j];
			}
		}
		if(cnt&1)value*=-1;
		checkvalue.pb(value);
	}
}
ll calculator(ll n)
{
	ll result=n;
	for(auto j:checkvalue)
		result+=n/j;
	return result;
}
ll check(ll n)
{
	ll i=calculator(n);
	return i-val;
}
int _runtimeTerror_()
{
	ll x,p,k;
	cin>>x>>p>>k;
	ll st=x+1,en=1e8;
	pr.clear();
	checkvalue.clear();
	factorize(p);
	xx=sz(pr);
	calculate();
	val=calculator(x);
	while(st<=en)
	{
		ll mid=(st+en)>>1;
		if(check(mid)<k)st=mid+1;
		else en=mid-1;
	}
	cout<<en+1<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif

	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}