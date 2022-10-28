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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,n,num;
	map<ll,ll> m;
	vector<ll> v;
	for(i=2;i<=(ll)2e9;i*=2)
		v.pb(i);
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>num;
		m[num]++;
	}
	ll ans=0;
	for(auto j:m)
	{
		bool found=false;
		for(auto k:v)
		{
			if(k>j.F)
			{
				if(k==2*j.F)
				{
					if(m[j.F]>1)
					{
						found=true;break;
					}
				}
				else if(k>j.F && m.count(k-j.F))
				{
					found=true;break;
				}
			}
		}
		if(!found)ans+=j.S;
	}
	cout<<ans;
	return 0;
}