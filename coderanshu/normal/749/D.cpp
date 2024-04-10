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


const int N = 200005;

set<pii> g[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> bids;
    vector<int> a(n+1),b(n+1),last(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        g[a[i]].insert({i,b[i]});
        last[a[i]] = i;
    }
    vector<bool> vis(n+1,false);
    for(int i=n;i>=1;--i)
    {
        if(!vis[a[i]])
            bids.push_back(a[i]),vis[a[i]] = true;
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int k;
        cin>>k;
        set<int> rm;
        for(int i=0;i<k;++i)
        {
            int x;
            cin>>x;
            rm.insert(x);
        }
        vector<int> tmp;
        for(int i=0;i<sz(bids) && sz(tmp) < 2;++i)
        {
            if(!rm.count(bids[i]))
                tmp.push_back(bids[i]);
        }
        int id = 0;
        if(tmp.size() == 0)
            cout<<"0 0\n";
        else
        {
            if(tmp.size() == 2)
                id = last[tmp[1]];
            cout<<tmp[0]<<" "<<g[tmp[0]].lower_bound({id,-1})->S<<"\n";
        }

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