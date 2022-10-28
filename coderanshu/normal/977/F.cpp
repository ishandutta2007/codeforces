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
	
	ll n,i,mi,Max;
	cin>>n;
	ll a[n];
	map<ll,ll> m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		m[a[i]]=1+m[a[i]-1];
	}
	Max=m.begin()->S;mi=m.begin()->F;
	for(auto j=++m.begin();j!=m.end();j++)
	{
		if(j->S>Max)
		{
			Max=j->S;
			mi=j->F;
		}
	}
	vector<ll> indices;
	ll ans=mi;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]==ans)
		{
			indices.pb(i+1);ans--;
		}
	}
	reverse(all(indices));
	cout<<indices.size()<<endl;
	for(auto j:indices)
		cout<<j<<" ";
	return 0;
}