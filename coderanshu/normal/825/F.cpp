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
#define popcount(x) __builtin_popcountll(x)
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
int fuck[8005][8005];
void getfuck(string &s,int idx)
{
    size_t n=s.length();
    //vector<int> v(n);
    fuck[idx][0]=0;
    int curLen=0,i=1;
    for(;i<n;)
    {
        if(s[i]==s[curLen])
            fuck[idx][i]=++curLen,++i;
        else
        {
            if(curLen==0)
                fuck[idx][i]=0,++i;
            else
                curLen=fuck[idx][curLen-1];
        }
    }
    //cout<<"fuck vector:\n";
    //for(auto j:v)
    //    cout<<j<<" ";
    //cout<<endl;
    //return v;
}
int numlen[8005];
int dp[8005];
int _runtimeTerror_()
{
	string s;
	cin>>s;
	int n=sz(s);
	string t=s;
	int i,j;
	for(i=0;i<n;++i)
	{
		getfuck(t,i);
		t.erase(t.begin());
	}
	numlen[0]=1;
	for(i=1;i<=8001;++i)
	{
		if(i/10)
			numlen[i]=numlen[i/10]+1;
		else numlen[i]=1;
	}
	dp[0]=0;
	for(i=1;i<=n;++i)
	{
		dp[i]=INT_MAX;
		for(j=1;j<=i;++j)
		{
			int pr=i-j+1;
			int len=i-j+1;
			int pmk=fuck[j-1][len-1];
			if(len%(len-pmk)==0)
				pr=len-pmk;
			amin(dp[i],dp[j-1]+numlen[len/pr]+pr);
		}
	}
	cout<<dp[n]<<endl;
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