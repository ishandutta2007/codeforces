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
#define llevel 20
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
vector<int> zFunction(string &s)
{
	int n=sz(s),l,r,i;
	vector<int> z(n);
	z[0]=n;
	l=r=0;
	for(i=1;i<n;++i)
	{
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[z[i]+i])
			++z[i];
		if(i+z[i]-1>r)
		{
			l=i;r=i+z[i]-1;
		}
	}
	return z;
}
int _runtimeTerror_()
{
	string s;
	cin>>s;
	vector<int> z=zFunction(s);
	int n=sz(s),i,x=0;
	set<int> sett;
	for(i=n-1;i>0;--i)
	{
		if(z[i]==n-i)
		{
			sett.insert(z[i]);
		}
	}
	for(i=1;i<n;++i)
	{
		if(z[i]==n-i)--z[i];
		x=max(x,z[i]);
	}
	auto it=sett.lower_bound(x);
	if(*it==x);
	else if(it==sett.begin())x=0;
	else
	{
		--it;x=*it;
	}
	if(x==0)
		cout<<"Just a legend";
	else
		cout<<s.substr(0,x);
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
	return 0;
}