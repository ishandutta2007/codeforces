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
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> g(n+1);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }
    set<int> can,unvis;
    for(int i=2;i<=n;++i)
        unvis.insert(i);

    if(sz(g[1]) > n - 1 - k)
    {
        cout<<"impossible\n";return 0;
    }
    auto bfs = [&](set<int> &unvis,int s)
    {
        vector<int> q{s};
        unvis.erase(s);
        while(!q.empty())
        {
            vector<int> tmp;
            for(auto &j:q)
            {
                vector<int> w;
                for(auto &k:g[j])
                    if(unvis.count(k))
                        unvis.erase(k),w.push_back(k);
                for(auto &k:unvis)
                    tmp.push_back(k);
                unvis.clear();
                for(auto &k:w)
                    unvis.insert(k);
            }
            q = tmp;
        }
    };
    bfs(unvis,1);
    if(!unvis.empty())
    {
        cout<<"impossible\n";return 0;
    }
    for(int i=2;i<=n;++i)
        unvis.insert(i);
    int cmp = 0;
    for(int i=2;i<=n;++i)
        if(unvis.count(i))
            bfs(unvis,i),++cmp;
    if(cmp > k)
        cout<<"impossible\n";
    else
        cout<<"possible\n";
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