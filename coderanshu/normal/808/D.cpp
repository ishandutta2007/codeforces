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
	ll i,a[n],psum[n],sum=0;
	multiset<ll> s2;
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		if(i==0)psum[i]=a[i];
		else psum[i]=psum[i-1]+a[i];
		sum+=a[i];
		s2.insert(a[i]);
	}
	if(n==1)
	{
		cout<<"NO";return 0;
	}
	multiset<ll> s;
	for(i=0;i<n;++i)
	{
		sum-=a[i];
		s.insert(a[i]);
		s2.erase(s2.find(a[i]));
		if(sum==psum[i])
		{
			cout<<"YES";return 0;
		}
		ll k=abs(psum[i]-sum);
		if(k&1)continue;
		if(psum[i]<sum)
		{
			if(s2.count(k/2))
			{
				cout<<"YES\n";return 0;
			}
		}
		else
		{
				if(s.count(k/2))
			{
				cout<<"YES\n";return 0;
			}
		}
	}
	cout<<"NO\n";return 0;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}