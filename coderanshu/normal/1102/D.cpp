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
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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
	ll n,x,y,i;
	string s;
	cin>>n>>s;
	ll k=n/3;
	int a[3]={0};
	for(auto j:s)
		a[j-'0']++;
	if(a[0]>k)
	{
		for(i=n-1;i>=0;--i)
		{
			if(a[0]==k)break;
			if(s[i]=='0')
			{
				--a[0];
				if(a[2]<k)
				{
					++a[2];s[i]='2';
				}
				else if(a[1]<k)
				{
					++a[1];s[i]='1';
				}
			}
		}
	}
	if(a[2]>k)
	{
		for(i=0;i<n;++i)
		{
			if(a[2]==k)break;
			if(s[i]=='2')
			{
				--a[2];
				if(a[0]<k)
				{
					++a[0];s[i]='0';
				}
				else if(a[1]<k)
				{
					++a[1];s[i]='1';
				}
			}
		}
	}
	if(a[1]>k)
	{
		for(i=0;i<n;++i)
		{
			if(a[1]==k)break;
			if(s[i]=='1')
			{
				if(a[0]<k)
				{
					--a[1];
					++a[0];s[i]='0';
				}
			}
		}
		for(i=n-1;i>=0;--i)
		{
			if(a[1]==k)break;
			if(s[i]=='1')
			{
				if(a[2]<k)
				{
					--a[1];
					++a[2];
					s[i]='2';
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<endl<<_time_;
	return 0;
}