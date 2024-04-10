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
	ll n,m,i,j,k;
	cin>>n>>m>>k;
	ll a[n],b[m];
	for(i=0;i<n;++i)cin>>a[i];
	for(i=0;i<m;++i)cin>>b[i];
	map<ll,ll> m1,m2;
	for(i=0;i<n;++i)
	{
		if(a[i]==1)
		{
			ll count=0;
			while(i<n && a[i]==1){++count;++i;}
			for(ll j=1;j<=count;++j)
				m1[j]+=count-j+1;
		}
	}
	for(i=0;i<m;++i)
	{
		if(b[i]==1)
		{
			ll count=0;
			while(i<m && b[i]==1){++count;++i;}
			for(ll j=1;j<=count;++j)
				m2[j]+=count-j+1;
		}
	}
	ll z=sqrt(k);ll ans=0;bool boo=false;
	if(z*z==k){boo=true;--z;}
	for(i=1;i<=z;++i)
	{
		if(k%i==0)
		{
			ans+=m1[i]*m2[k/i]+m2[i]*m1[k/i];
			//cout<<ans;
		}
	}
	if(boo)
	{
		z=sqrt(k);
		ans+=m1[z]*m2[z];
	}
	cout<<ans<<endl;
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