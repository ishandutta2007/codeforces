#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,q,i;
	cin>>n>>q;
	ll m=0;
	vector<ll> v(n);
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		m=max(m,v[i]);
	}
	for(i=0;i<n;++i)
	{
		if(v[i]==m)break;
	}
	vector<pair<ll,ll>> ans; 
	ll moves=i;
	vector<ll> z;
	for(ll j=i;j<n;j++)z.pb(v[j]);
	for(ll j=0;j<i;j++)
	{
		ans.pb({v[j],v[j+1]});
		if(v[j]>v[j+1])
		{
			z.pb(v[j+1]);
			v[j+1]=max(v[j],v[j+1]);
		}
		else
		{
			z.pb(v[j]);
			v[j+1]=max(v[j],v[j+1]);
		}
	}
	//for(auto j:z)cout<<j<<endl;
	//	cout<<endl;
	while(q--)
	{
		ll mi;
		cin>>mi;
		if(ans.size()>=mi)cout<<ans[mi-1].F<<" "<<ans[mi-1].S<<endl;
		else
		{
			mi-=ans.size();
			ll temp=mi%(n-1);
			if(temp==0)temp=n-1;
			cout<<m<<" "<<z[temp]<<endl;
		}
	}
	return 0;
}