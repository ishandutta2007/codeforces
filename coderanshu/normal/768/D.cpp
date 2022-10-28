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
    int k,Q;
    cin>>k>>Q;
    vector<long double> dp(k+1),new_dp(k+1,0);
    dp[1] = 1.0;
    vector<long double> pr{0};
    pr.push_back(dp[k]);
    for(int i=2;;++i)
    {
        for(int j=1;j<=k;++j)
            new_dp[j] = 0;
        for(int j=1;j<=k;++j)
        {
            new_dp[j] += dp[j] * 1.0 * j / k;
            if(j+1<=k)
                new_dp[j+1] += dp[j] * 1.0 * (k-j) / k;
        }
        pr.push_back(new_dp[k]);
        dp = new_dp;
        if(new_dp[k] >= 0.5)
            break;
    }
    while(Q--)
    {
        int p;
        cin>>p;
        int lo = 1,hi = sz(pr), ans = 1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(2000 * pr[mid] >= p)
                ans = mid,hi = mid-1;
            else
                lo = mid+1;
        }
        cout<<ans<<"\n";
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