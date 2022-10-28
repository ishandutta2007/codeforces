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
#define pi 3.1415926536

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
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,n,i,num;
	bool ans;
	cin>>t;
	map<ll,ll>m;
	vector<ll> v;
	while(t--)
	{
		cin>>n;
		m.clear();
		v.clear();
		ans=true;
		for(i=0;i<4*n;i++)
		{
			cin>>num;
			m[num]++;
		}
		for(auto j:m)
		{
			if(j.S%2!=0)
			{
				ans=false;break;
			}
			else
			{
				for(auto k=0;k<j.S/2;k++)v.pb(j.F);
			}
		}
		if(!ans)
		{
			cout<<"NO\n";continue;
		}
		ll x=v.size();
		ll check=v[0]*v[x-1];
		for(i=0;i<x;i++)
		{
			if(v[i]*v[x-1-i]!=check)
			{
				ans=false;break;
			}
		}
		if(ans)cout<<"YES\n";
		else cout<<"NO\n";

	}
	return 0;
}