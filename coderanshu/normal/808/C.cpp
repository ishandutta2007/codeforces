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
	ll n,w,i,check=0;
	cin>>n>>w;
	vector<pair<ll,ll>> v(n);
	vector<ll> ans(n,0);
	for(i=0;i<n;++i){cin>>v[i].F;check+=v[i].F/2+v[i].F%2;v[i].S=i;ans[i]+=v[i].F/2+v[i].F%2;}
	sort(all(v));
	if(check>w)
	{
		cout<<-1;return 0;
	}
	w-=check;
	for(i=n-1;i>=0;--i)
	{
		if(w==0)break;
		ll k=ans[v[i].S];
		ans[v[i].S]+=min(v[i].F-k,w);
		w-=min(v[i].F-k,w);
	}
	for(i=0;i<n;++i)
		cout<<ans[i]<<" ";
	cout<<endl;
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