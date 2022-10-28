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
vector<ll> v;
ll func(ll x)
{
	ll sub,sz=v.size(),count,pro;
	sub=(1<<sz);
	ll ans=x;
	if(x==0)return 0;
	for(ll i=1;i<sub;++i)
	{
		count=0;pro=1;
		for(ll j=0;j<sz;++j)
		{
			if(i&(1<<j))
			{
				count++;pro*=v[j];
			}
		}
		if(count%2)ans-=x/pro;
		else ans+=x/pro;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll test,a,t,m,x1,x2,i,k;
	cin>>test;
	while(test--)
	{
		v.clear();
		cin>>a>>m;
		t=__gcd(a,m);
		x1=a/t;x2=m/t;
		k=x2;
		for(i=2;i<=sqrt(x2);++i)
		{
			if(x2%i==0)
			{
				while(x2%i==0)x2/=i;
				v.pb(i);
			}
		}
		if(x2!=1)v.pb(x2);
		cout<<func(x1+k)-func(x1-1)-1<<endl;

	}
	return 0;
}