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
#define level 20
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
	ll n;cin>>n;
	ll i,a[n];
	for(i=0;i<n;++i)cin>>a[i];
	if(n==1)
	{
		cout<<-1;return 0;
	}
	sort(a,a+n);
	map<ll,ll> s;
	for(i=1;i<n;++i)
	{
		s[a[i]-a[i-1]]++;
	}
	if(s.size()>2)
	{
		cout<<0<<endl;return 0;
	}
	if(s.size()==1)
	{
		if(n==2)
		{
			if(a[1]==a[0])cout<<1<<endl<<a[0];
			else 
			{
				cout<<2+((a[1]-a[0])%2==0)<<endl;
				cout<<a[0]-s.begin()->F;
				if((a[1]-a[0])%2==0)cout<<" "<<(a[1]+a[0])/2;
				cout<<" "<<a[1]+s.begin()->F;
			}
		}
		else if(s.count(0))
		{
			cout<<1<<endl<<a[0];
		}
		else
		{
			cout<<2<<endl<<a[0]-s.begin()->F<<" "<<a[n-1]+s.begin()->F;
		}
	}
	else 
	{	
		auto it=s.begin();
		ll k=it->F,l=it->S;++it;ll z=it->F;ll m=it->S;
		if(m!=1)
		{
			cout<<0<<endl;return 0;
		}
		if(2*k==z)
		{
			cout<<1<<endl;
			for(i=1;i<n;++i)
			{
				if(a[i]-a[i-1]==z)
				{
					cout<<(a[i]+a[i-1])/2;
				}
			}
		}
		else
			cout<<0<<endl;
	}
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