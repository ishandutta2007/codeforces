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
	ll n,m;cin>>n>>m;
	if(m<n-1 || m>2*(n+1))
	{
		cout<<-1;return 0;
	}
	if(m<=n)
	{
		for(int i=0;i<n-1;++i)
			cout<<"01";
		cout<<"0";
		if(m==n)cout<<1;return 0;
	}
	int a[n+1];
	for(int i=0;i<n+1;++i)a[i]=1;
	m-=n+1;
	for(int i=0;i<m;++i)++a[i];
	if(a[0]==1)cout<<1;
	if(a[0]==2)cout<<11;
	for(int i=0;i<n;++i)
	{
		cout<<0;
		for(int j=0;j<a[i+1];++j)cout<<1;
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