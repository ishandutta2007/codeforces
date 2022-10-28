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

int runtimeTerror()
{
	ll n,m,i,j;
	cin>>n>>m;
	pair<ll,pair<ll,ll>> p[n];
	for(i=0;i<n;++i)
		cin>>p[i].F>>p[i].S.F>>p[i].S.S;
	ll lw=m-p[0].F;
	ll up=m+p[0].F;
	for(i=0;i<n;++i)
	{
		if(lw>p[i].S.S)
		{
			cout<<"NO\n";return 0;
		}
		if(up<p[i].S.F)
		{
			cout<<"NO\n";return 0;
		}
		if(p[i].S.F<=lw && p[i].S.S>=lw && p[i].S.S<=up)
			up=p[i].S.S;
		else if(p[i].S.F<=lw && p[i].S.S>=up);
		else if(p[i].S.F>=lw && p[i].S.S<=up)
		{
			lw=p[i].S.F;up=p[i].S.S;
		}
		else if(p[i].S.F>=lw && p[i].S.F<=up && p[i].S.S>=up)
			lw=p[i].S.F;
		if(i<n-1)
		{
			lw=lw-(p[i+1].F-p[i].F);
			up=up+(p[i+1].F-p[i].F);
		}

	}
	cout<<"YES\n";return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tests=1;
	cin>>tests;
	while(tests--)
		runtimeTerror();
	return 0;
}