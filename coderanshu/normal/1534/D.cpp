// Har Har Mahadev
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


int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<vector<int>> ans(n+1,vector<int>(n+1));
    auto query = [&](int q)
    {
        cout<<"? "<<q<<"\n"<<flush;
        for(int i=1;i<=n;++i)
            cin>>ans[q][i];
    };
    query(1);
    int odd = 0;
    vector<int> o,e;
    for(int i=2;i<=n;++i)
    {
        odd += ans[1][i] & 1;
        if(ans[1][i] & 1)
            o.push_back(i);
        else
            e.push_back(i);
    }
    int even = n - 1 - odd;
    vector<int> want;
    if(sz(o) < sz(e))
        want = o;
    else
        want = e;
    for(auto &j:want)
        query(j);
    vector<pii> edges;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            if(ans[i][j] == 1)
                edges.push_back({min(i,j),max(i,j)});
    }
    sort(all(edges));
    edges.resize(unique(all(edges)) - edges.begin());
    cout<<"!\n";
    assert(sz(edges) == n-1);
    for(auto [j,k]:edges)
    {
        cout<<j<<" "<<k<<"\n";
    }
    cout<<flush;
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