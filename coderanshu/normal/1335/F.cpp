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
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> cnt(n,vector<pii>(m,make_pair(0,0))),dp(n,vector<pii>(m)),new_dp(n,vector<pii>(m));
    vector<vector<char>> a(n,vector<char>(m)),is(n,vector<char>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>is[i][j];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='L')
                dp[i][j] = {i,j-1};
            else if(a[i][j]=='R')
                dp[i][j] = {i,j+1};
            else if(a[i][j]=='D')
                dp[i][j] = {i+1,j};
            else
                dp[i][j] = {i-1,j};
        }
    }
    for(int l=0;l<20;++l)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                new_dp[i][j] = dp[dp[i][j].F][dp[i][j].S];
            }
        }
        swap(dp,new_dp);
    }
    int ans = 0,black = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            ++cnt[dp[i][j].F][dp[i][j].S].F;
            if(is[i][j]=='0')
                ++cnt[dp[i][j].F][dp[i][j].S].S;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(cnt[i][j].F)
                ++ans;
            if(cnt[i][j].S)
                ++black;
        }
    }
    cout<<ans<<" "<<black<<"\n";
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}