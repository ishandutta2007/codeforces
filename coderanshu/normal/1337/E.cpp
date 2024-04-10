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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
ll n,m;
ll dp[3002][3002],dp2[3002][3002],pw[3002];
string s,t;
ll solve(ll pos1,ll pos2)
{
	if(pos1+1<m-pos2)
		return 0LL;
	if(pos2==m)return pw[pos1+1];
	if(pos1==-1)
		return 0;
	if(dp[pos1][pos2]!=-1)return dp[pos1][pos2];
	ll ret=0;
	if(pos1+1==m-pos2)
		return dp2[pos1][pos2];
	if(s[pos1]==t[pos2])
	{
		ret+=solve(pos1-1,pos2+1);
		ret%=MM;
	}
	ret+=solve(pos1-1,pos2);
	return dp[pos1][pos2]=ret;
}
int _runtimeTerror_()
{
	mem1(dp2);
	mem1(dp);
	cin>>s>>t;
	ll i,j;
	n=sz(s),m=sz(t);
	ll ans=0;
	for(i=0;i<n;++i)
	{
		for(j=0;j<m-i;++j)
		{
			dp2[i][j]=0;
			if(i==0)
				dp2[i][j]=2*(s[i]==t[j]);
			else
			{
				if(s[i]==t[j])
					dp2[i][j]+=dp2[i-1][j+1];
				if(s[i]==t[j+i])
					dp2[i][j]+=dp2[i-1][j];
			}
			dp2[i][j]%=MM;
			//cout<<dp2[i][j]<<" ";
		}
		//cout<<endl;
	}
	//cout<<dp2[1][0]<<endl;
	for(i=0;i<n;++i)
	{
		ans+=solve(i,0);
		//cout<<ans<<endl;
		ans%=MM;
	}
	cout<<ans<<endl;
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
	pw[0]=1;
	for(int i=1;i<=3000;++i)
		pw[i]=pw[i-1]*2%MM;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}