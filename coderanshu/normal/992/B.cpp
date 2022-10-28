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
	ll l,r,x,y,pro,i,count,j;
	cin>>l>>r>>x>>y;
	if(y%x)
	{
		cout<<0;return 0;
	}
	pro=y/x;
	map<ll,ll> m;
	vector<ll> v;
	for(i=2;i<=sqrt(pro);i++)
	{
		if(pro%i==0)
		{
			count=0;
			while(pro%i==0)
			{
				count++;pro/=i;
			}
			m[i]=count;v.pb(i);
		}
	}
	if(pro!=1)
	{
		m[pro]=1;v.pb(pro);
	}
	ll sz=v.size(),t1,t2;
	ll check=(1<<sz);
	ll ans=0;
	for(i=0;i<check;i++)
	{
		t1=t2=1;
		for(j=0;j<sz;j++)
		{
			if(i&(1<<j))t1*=power(v[j],m[v[j]]);
			else t2*=power(v[j],m[v[j]]);
		}
		if(min(t1,t2)*x>=l && max(t1,t2)*x<=r)
			++ans;
	}
	cout<<ans;
	return 0;
}