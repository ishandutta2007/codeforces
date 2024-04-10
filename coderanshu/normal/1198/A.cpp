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
ll n,I;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,num;
	map<ll,ll> m;
	cin>>n>>I;
	ll k=8*I/n;
	for(i=0;i<n;++i)
	{
		cin>>num;
		m[num]++;
	}
	vector<ll> v;
	for(auto j:m)
		v.pb(j.S);
	m.clear();
	ll sz=v.size();
	if(k>20)
	{
		cout<<"0";return 0;
	}
	k=power(2,k);
	if(sz<=k)
	{
		cout<<0;return 0;
	}
	ll sum=0,ans;
	for(i=0;i<k;++i)sum+=v[i];
	ans=sum;
	for(i=k;i<sz;++i)
	{	
		sum+=v[i]-v[i-k];
		ans=max(ans,sum);
	} 
	cout<<n-ans;
	return 0;
}