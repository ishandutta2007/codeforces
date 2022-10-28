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

map<int64_t,int> dp[62];

int get(int i,int mask)
{
    if(i == 0)
        return 0;
    if(dp[i].count(mask))
        return dp[i][mask];
    set<int> s;
    auto mex = [&]()
    {
        for(int i=0;;++i)
            if(!s.count(i))
                return i;
    };
    for(int j=1;j<=i;++j)
    {
        if(mask&(1LL<<j))
            continue;
        s.insert(get(i-j,mask|(1LL<<j)));
    }
    dp[i][mask] = mex();
    return dp[i][mask];
}

int _runtimeTerror_()
{
    vector<int> ans = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
    // cout<<"ans = {0,";
    // for(int i=1;i<=60;++i)
    // {
    //     ans[i] = get(i,0);
    //     cout<<ans[i]<<",";
    // }
    // cout<<"};\n";
    int n;
    cin>>n;
    int x = 0;
    while(n--)
    {
        int u;
        cin>>u;
        x ^= ans[u];
    }
    cout<<(!x?"YES":"NO")<<"\n";
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