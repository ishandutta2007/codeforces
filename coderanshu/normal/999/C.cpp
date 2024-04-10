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
	ll n,k,i;
	string s;
	cin>>n>>k>>s;
	int count[26]={0};
	for(i=0;i<n;++i)
		count[s[i]-'a']++;
	int sum=0;
	for(i=0;i<26;++i)
	{
		sum+=count[i];
		if(sum>=k)break;
	}
	if(i==26)
	{
		cout<<endl;return 0;
	}
	sum-=count[i];
	k-=sum;
	int zz=i;
	string t;
	for(int j=0;j<n;++j)
	{
		if(s[j]-'a'<i)continue;
		t.pb(s[j]);
	}
	for(i=0;i<sz(t);++i)
	{
		if(t[i]-'a' ==zz && k>0)
		{
			--k;continue;
		}
		cout<<t[i];
	}
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