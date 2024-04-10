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

int runtimeTerror()
{
	ll n,i,j;
	string s;
	cin>>n>>s;
	vector<ll> vmax(n,0),vmin(n,0);
	ll dec=0,inc=0,inc2,dec2;
	for(i=0;s[i];++i)
	{
		if(s[i]=='>')
			dec++;
	}
	dec2=dec;
	inc2=dec+2;
	vmax[0]=dec+1;
	vector<ll> check;
	for(i=0;s[i];++i)
	{
		if(s[i]=='<')
		{
			vmax[i+1]=inc2;++inc2;
		}
		if(s[i]=='>')
		{
			j=i;
			while(i<n-1 && s[i]=='>')++i;
			check.pb(i-j);--i;
		}
	}
	ll in=0,t=0,l;
	for(i=0;i<n;++i)
	{
		if(s[i]=='>')
		{
			t+=check[in];++in;l=t;
			while(i<n-1 && s[i]=='>')
			{
				vmax[i+1]=l;--l;++i;
			}
		}
	}
	t=n+1;in=0;
	vmin[0]=dec2+1;check.clear();
	for(i=0;i<n;++i)
	{
		if(s[i]=='>')
		{
			vmin[i+1]=dec2;--dec2;
		}
		if(s[i]=='<')
		{
			j=i;
			while(i<n-1 && s[i]=='<')++i;
			check.pb(i-j);--i;
		}
	}
	for(i=0;i<n;++i)
	{
		if(s[i]=='<')
		{
			t-=check[in];++in;
			l=t;
			while(i<n-1 && s[i]=='<')
			{
				vmin[i+1]=l;++l;++i;
			}
		}
	}
	for(auto j:vmin)cout<<j<<" ";
		cout<<endl;
	for(auto j:vmax)cout<<j<<" ";
		cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tests=1;
	cin>>tests;
	while(tests--)
		runtimeTerror();
	return 0;
}