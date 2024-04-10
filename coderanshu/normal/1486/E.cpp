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

const int N = 100005;

vector<pii> v[N];
int n,m;

ll ans[N],dp[N];

set<pll> ac[N];

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    for(int i=1;i<=n;++i)
    {
        ans[i] = INF;
        dp[i] = INF;
    }
    ans[1] = 0;
    dp[1] = 0;
    set<pair<pll,int>> s;
    // s.insert()
    auto add = [&](int v,int cost,ll val)
    {
        ll x = val + cost*cost;
        vector<pll> er;
        for(auto [j,k]:ac[v])
        {
            if(j<=x && k<=2*cost)
                return ;
            if(j>=x && k>=2*cost)
                er.pb({j,k});
        }
        if(!ac[v].empty())
            s.erase({*ac[v].begin(),v});
        for(auto j:er)
            ac[v].erase(j);
        ac[v].insert({x,2*cost});
        s.insert({*ac[v].begin(),v});
    };
    auto add2 = [&](int v,int cost,int u)
    {
        ll val = INF;
        for(auto [j,k]:ac[u])
        {
            ll x = cost*cost + j + k * cost;
            if(x < dp[v])
                amin(val,x);
        }
        if(val == INF)
            return ;
        if(dp[v] != INF)
            s.erase({{dp[v],0},v});
        dp[v] = val;
        s.insert({{dp[v],0},v});
    };
    s.insert({{0,0},1});
    while(!s.empty())
    {   
        auto x = *s.begin();
        s.erase(s.begin());
        // cout<<x<<"\n";
        if(x.F.S == 0)
        {
            for(auto [j,k]:v[x.S])
            {
                // k->factor    
                add(j,k,x.F.F);
            }
        }
        else
        {
            for(auto [j,k]:v[x.S])
            {
                add2(j,k,x.S);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(dp[i] == INF)
            dp[i] = -1;
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
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