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
	cin>>n;ll a[n],b[n],i;
	for(i=0;i<n;++i)cin>>a[i];
	for(i=0;i<n;++i)cin>>b[i];
		ll o=0,x=0;
	for(i=0;i<n;++i)
	{
		if(a[i]==1 && b[i]==1)continue;
		if(a[i]==1)o++;
		if(b[i]==1) x++;
	}
	if(o==0 || (o==0 && x==0))
	{
		cout<<-1;
	}
	else if(o>0 && x==0)
	{
		cout<<1;
	}

	else
	{
		cout<<x/o+1;
	}
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