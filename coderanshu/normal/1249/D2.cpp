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
    int n,k;
    cin>>n>>k;
    const int N = 2e5+2;
    vector<vector<pii>> add(N+1),del(N+1);
    for(int i=1;i<=n;++i)
    {
        int l,r;
        cin>>l>>r;
        add[l].push_back({r,i});
        del[r+1].push_back({r,i});
    }
    multiset<pii> cur;
    vector<int> ans;
    for(int i=1;i<=N-2;++i)
    {
        // debug(i,"Here");
        for(auto &j:add[i])
            cur.insert(j);
        for(auto &j:del[i])
        {
            cur.erase(cur.find(j));
        }
        // debug(cur);
        // debug(sz(cur));
        while(sz(cur) > k)
        {
            auto u = *cur.rbegin();
            ans.push_back(u.S);
            add[u.F+1].push_back({u.F,u.S});
            cur.erase(cur.find(u));
        }
    }
    cout<<sz(ans)<<"\n";
    for(auto &j:ans)
        cout<<j<<" ";
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