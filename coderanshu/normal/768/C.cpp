#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> dp(1024),new_dp(1024);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        ++dp[x];
    }
    for(int i=1;i<=k;++i)
    {
        fill(all(new_dp),0);
        int cur = 0;
        for(int j=0;j<1024;++j)
        {
            if(cur & 1)
                new_dp[j^x] += dp[j]/2, new_dp[j] += dp[j] - dp[j]/2;
            else
                new_dp[j^x] += (dp[j] + 1)/2, new_dp[j] += dp[j] - (dp[j] + 1)/2;
            cur += dp[j];
        }
        dp = new_dp;
    }
    int mn = 1024,mx = -1;
    for(int i=0;i<1024;++i)
        if(dp[i])
            amax(mx,i),amin(mn,i);
    cout<<mx<<" "<<mn<<"\n";
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