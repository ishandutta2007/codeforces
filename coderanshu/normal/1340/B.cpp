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

string s[2002];
string x[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
ll count(string t,int id)
{
	ll val=0,i;
	for(i=0;i<7;++i)
	{
		if(t[i]=='1' && x[id][i]=='0')
			return -1;
		else if(t[i]=='0' && x[id][i]=='1')
			++val;
	}
	return val;
}
const int N=2005;
ll dp[N][N];
int _runtimeTerror_()
{
	mem1(dp);
	ll n,i,k,kk,j;
	cin>>n>>k;
	for(i=0;i<n;++i)
		cin>>s[i];
	reverse(s,s+n);
	//cout<<count(s[0],8)<<endl;
	// reverse kar lio
	for(i=0;i<n;++i)
	{
		for(j=0;j<=k;++j)
		{
			for(kk=9;kk>=0;--kk)
			{
				ll xx=count(s[i],kk);
				if(xx!=-1)
				{
					if(xx<=j)
					{
						if(i>0)
						{
							if(dp[i-1][j-xx]!=-1)
							{
								dp[i][j]=kk;break;
							}
						}
						else 
						{
							if(xx==j)
							{
								dp[i][j]=kk;break;
							}
						} 
					}
				}
			}
		}
	}
	if(dp[n-1][k]==-1)
	{
		cout<<-1;return 0;
	}
	vector<int> ans;
	ans.pb(dp[n-1][k]);
	ll rem=k-count(s[n-1],dp[n-1][k]);
	for(i=n-2;i>=0;--i)
	{
		ans.pb(dp[i][rem]);
		rem=rem-count(s[i],dp[i][rem]);
	}
	for(auto j:ans)
		cout<<j;
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
	cerr<<"\n"<<_time_;
	return 0;
}