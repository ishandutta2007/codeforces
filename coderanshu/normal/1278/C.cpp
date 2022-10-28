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
#define level 20
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
	ll a[2*n],i,c=0,ca=0;
	for(i=0;i<2*n;++i)cin>>a[i];
	map<ll,ll> m;
	for(i=n;i<2*n;++i)
	{
		if(a[i]==1)c++;
		else c--;
		if(a[i-n]==1)ca++;
		else --ca;
	}
	m[c]=0;
	for(i=n;i<2*n;++i)
	{
		if(a[i]==1)--c;
		else ++c;
		if(!m.count(c))m[c]=i+1-n;
	}
	ll ans=1e10;
	if(m.count(-ca))ans=min(ans,m[-ca]);
	for(i=n-1;i>=0;--i)
	{
		ll z=n-i;
		if(a[i]==1)--ca;
		else ++ca;
		if(!m.count(-ca))continue;
		ans=min(ans,z+m[-ca]);
	}
	cout<<ans<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}