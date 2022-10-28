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
    int n;
    cin>>n;
    vector<int> p(n+1);
    int good = -1;
    vector<bool> vis(n+1,false);
    vector<vector<int>> c;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        if(p[i] == i)
            good = i;
    }
    for(int i=1;i<=n;++i)
    {
        if(p[i] == i || vis[i])
            continue;
        vector<int> t;
        int cur = i;
        while(!vis[cur])
        {
            t.pb(cur);
            vis[cur] = true;
            cur = p[cur];
        }
        c.pb(t);
    }
    vector<pii> ans;
    auto get = [&](vector<int> c,int req)
    {
        if(sz(c) == 2)
        {
            assert(req != -1);
            // x y z
            ans.pb({c[0],req});
            ans.pb({req,c[1]});
            ans.pb({req,c[0]});
            return ;
        }
        ans.pb({c.back(),c[0]});
        // c[0] bekaar
        for(int i=1;i<sz(c)-2;++i)
            ans.pb({c.back(),c[i]});
        int sb = c[sz(c)-2];
        ans.pb({sb,c[0]});
        ans.pb({sb,c.back()});
        ans.pb({c[0],c.back()});

    };
    auto merge = [&](vector<int> a,vector<int> b)
    {
        ans.pb({a.back(),b.back()});
        for(int i=0;i<sz(a)-1;++i)
            ans.pb({b.back(),a[i]});
        for(auto &j:b)
            ans.pb({a.back(),j});
        // ig done
    };
    while(sz(c) >= 2)
    {
        auto x = c.back();
        c.pop_back();
        auto y = c.back();
        c.pop_back();
        merge(x,y);
    }
    if(sz(c) == 1)
    {
        if(sz(c[0]) > 2)
            get(c[0],-1);
        else
        {
            for(int i=1;i<=n;++i)
            {
                if(c[0][0] != i && c[0][1] != i)
                {
                    get(c[0],i);
                    break;
                }
            }
        }
    }
    assert(sz(ans) <= n+1);
    cout<<sz(ans)<<"\n";
    for(auto j:ans)
        cout<<j.F<<" "<<j.S<<"\n";
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