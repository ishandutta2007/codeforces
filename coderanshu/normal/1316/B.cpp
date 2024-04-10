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

int _runtimeTerror_()
{
	ll n,i,j;
	string s;
	cin>>n>>s;
	ll z=1;string t=s,ans=s,x="",check;
	ll count=0;
	for(i=0;i<n-1;++i)
	{
		x+=s[i];
		t.erase(t.begin());
		check=t;
		if((n-(i+2)+1)%2!=0)
		{
			string l=x;
			reverse(all(l));
			for(auto j:l)check.pb(j);
		}
		else
		{
			for(auto j:x)check.pb(j);
		}
		if(check<ans)
		{
			ans=check;z=i+2;
		}
	}
	/*reverse(all(s));
	if(ans>s)
	{
		ans=s;z=n;
	}*/
	cout<<ans<<endl<<z<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}