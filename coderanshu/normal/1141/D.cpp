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

int _runtimeTerror_()
{
	ll n,i;
	string l,r;
	cin>>n>>l>>r;
	int q1,q2;
	vector<int> a[26],b[26],rem1,rem2;
	for(i=0;i<n;++i)
	{
		if(l[i]=='?')rem1.pb(i+1);
		else a[l[i]-'a'].pb(i+1);
	}
	for(i=0;i<n;++i)
	{
		if(r[i]=='?')rem2.pb(i+1);
		else b[r[i]-'a'].pb(i+1);
	}
	vector<pair<int,int>> ans;
	for(i=0;i<26;++i)
	{
		int cm=min(sz(a[i]),sz(b[i]));
		for(int k=0;k<cm;++k)
		{
			ans.pb({a[i][k],b[i][k]});
		}
		for(int k=cm;k<sz(a[i]);++k)
			rem1.pb(a[i][k]);
		for(int k=cm;k<sz(b[i]);++k)
			rem2.pb(b[i][k]);
	}
	reverse(all(rem2));
	int kk=sz(rem1);
	for(i=0;i<kk;++i)
	{
		if(l[rem1[i]-1]=='?' || r[rem2[i]-1]=='?')
			ans.pb({rem1[i],rem2[i]});
	}
	cout<<sz(ans)<<endl;
	for(auto j:ans)
		cout<<j.F<<" "<<j.S<<endl;
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