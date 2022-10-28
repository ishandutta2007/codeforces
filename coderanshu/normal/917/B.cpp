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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

const int N = 105;

int dp[N][N][26][2];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    vector<vector<pii>> g(n+1);
    while(m--)
    {
        int x,y;
        char c;
        cin>>x>>y>>c;
        g[x].push_back({y,c-'a'});
    }
    function<int(int,int,int,int)> dfs = [&](int l,int r,int ch,int pl)
    {
        int win = pl ^ 1;
        if(dp[l][r][ch][pl] != -1)
            return dp[l][r][ch][pl];
        if(pl == 0)
        {
            for(auto &[j,k]:g[l])
            {
                if(k >= ch)
                {
                    auto tmp = dfs(j,r,k,pl^1);
                    if(tmp == pl)
                        win = pl;
                }
            }
        }
        else
        {
            for(auto &[j,k]:g[r])
            {
                if(k >= ch)
                {
                    auto tmp = dfs(l,j,k,pl^1);
                    if(tmp == pl)
                        win = pl;
                }
            }
        }
        dp[l][r][ch][pl] = win;
        return win;
    };
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<"AB"[dfs(i,j,0,0)];
        }
        cout<<"\n";
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