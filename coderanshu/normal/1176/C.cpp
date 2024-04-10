#pragma GCC optimize("Ofast")

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
	if(e&1) return b*power(b*b%m,(e-1)/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,(e-1)/2);
	return power(b*b,e/2);
}
ll hashIt(ll i)
{
	if(i==4)return 0;
	if(i==8)return 1;
	if(i==15)return 2;
	if(i==16)return 3;
	if(i==23)return 4;
	if(i==42)return 5;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,i;
	cin>>n;
	vector<ll> v(n);
	for(i=0;i<n;i++)cin>>v[i];
	ll a[6];
	mem0(a);
	ll k,ans=0;
	for(i=0;i<n;i++)
	{
		k=hashIt(v[i]);
		a[k]++;
		if(k>0 && a[k]>a[k-1])
		{
			a[k]--;++ans;
		}
	}
	ll m=2e16;
	for(i=0;i<6;i++)
		m=min(m,a[i]);
	for(i=0;i<6;i++)
	{
		ans+=a[i]-m;
	}
	cout<<ans;
	return 0;
}