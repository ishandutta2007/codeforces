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

const int N = 1000005;

int mx[N],smx[N],dp[N];
int p[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    int cur = 2;
    auto get_new = [&]()
    {
        mx[cur] = smx[cur] = -1;
        dp[cur] = 1;
        return cur++;
    };
    auto get_ans = [&]()
    {
        int ans = 0;
        if(mx[1] != -1)
            amax(ans,dp[mx[1]]);
        if(smx[1] != -1)
            amax(ans,dp[smx[1]]);
        return ans;
    };
    auto upd = [&](int u)
    {
        int prev = dp[u];
        dp[u] = dp[mx[u]];
        if(smx[u] != -1)
            dp[u] = max(dp[u],dp[smx[u]]+1);
        return dp[u] != prev;
    };
    p[1] = 0;
    for(int i=1;i<=n;++i)
    {
        int par;
        cin >> par;
        int ver = get_new();
        p[ver] = par;
        while(par)
        {
            if(mx[par] == -1)
            {
                mx[par] = ver;
                if(!upd(par))
                    break;
            }
            else if(smx[par] == -1 && mx[par] != ver)
            {
                int u = mx[par];
                if(dp[ver] > dp[u])
                    smx[par] = mx[par],mx[par] = ver;
                else
                    smx[par] = ver;
                if(!upd(par))
                    break;
            }
            else
            {
                if(smx[par] == ver)
                {
                    if(dp[ver] > dp[mx[par]])
                        swap(mx[par],smx[par]);
                }
                else if(ver != smx[par] && ver != mx[par])
                {
                    if(dp[ver] > dp[mx[par]])
                    {
                        smx[par] = mx[par];
                        mx[par] = ver;
                    }
                    else if(dp[ver] > dp[smx[par]])
                    {
                        smx[par] = ver;
                    }
                }
                if(!upd(par))
                    break;
            }
            par = p[par];
            ver = p[ver];
        }
        cout << get_ans() << " ";
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