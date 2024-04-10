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
#define runSieve
bool notPrime[5000005];
ll divPrime[5000005];
void sieve(int n=5000000)
{
	int k=sqrt(n);
	memf(notPrime);
	notPrime[1]=true;
	for(int i=2;i<=k;++i)
	{
		if(!notPrime[i])
		{
			for(int k=i*i;k<=n;k+=i)
			{
				notPrime[k]=true;
				divPrime[k]=i;
			}
		}
	}
}
const int N=5000002;
ll dp[N],psum[N];
int _runtimeTerror_()
{
	ll a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<0<<endl;return 0;
	}
	cout<<psum[a]-psum[b]<<endl;
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
	cin>>TESTS;
	dp[1]=0;
	dp[2]=1;
	for(ll i=3;i<=5000000;++i)
	{
		if(!notPrime[i])dp[i]=1;
		else
			dp[i]=dp[i/divPrime[i]]+1;
	}
	psum[0]=0;
	for(ll i=1;i<=5000000;++i)
		psum[i]=dp[i]+psum[i-1];
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}