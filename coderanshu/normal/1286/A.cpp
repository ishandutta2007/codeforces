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
#define INF 1e9
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
const int N=102;
int a[N],dp[N][N][N][2],n;
int solve(int pos,int o,int e,int pr)
{
	if(pos==n)return 0;
	if(pr!=-1 && dp[pos][o][e][pr]!=-1)return dp[pos][o][e][pr];
	if(a[pos])
	{
		int x=solve(pos+1,o,e,a[pos]&1);
		int l=a[pos]&1;
		return dp[pos][o][e][pr]=x+((1-l)==pr);
	}
	int x=-1,y=-1;
	if(o)x=solve(pos+1,o-1,e,1)+(pr==0);
	if(e)y=solve(pos+1,o,e-1,0)+(pr==1);
	dp[pos][o][e][pr]=INF;
	if(x!=-1)
		dp[pos][o][e][pr]=min(x,dp[pos][o][e][pr]);
	if(y!=-1)
		dp[pos][o][e][pr]=min(y,dp[pos][o][e][pr]);
	return dp[pos][o][e][pr];
}
int _runtimeTerror_()
{
	cin>>n;
	int o=(n+1)/2,e=n/2,i;
	mem1(dp);
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]==0)continue;
		if(a[i]&1)--o;
		else --e;
	}
	cout<<solve(0,o,e,-1);
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