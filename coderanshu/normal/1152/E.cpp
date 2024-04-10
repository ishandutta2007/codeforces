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
    vector<int> b(n+1),c(n+1);
    vector<int> u;
    for(int i=1;i<=n-1;++i)
    {
        cin>>b[i];
        u.emplace_back(b[i]);
    }
    for(int i=1;i<=n-1;++i)
    {
        cin>>c[i];
        u.emplace_back(c[i]);
    }
    sort(u.begin(),u.end());
    u.resize(unique(all(u)) - u.begin());

    vector<bool> done(n+1,false);
    vector<vector<pii>> g(sz(u) + 2);
    for(int i=1;i<=n-1;++i)
    {
        if(c[i] < b[i])
        {
            cout<<"-1\n";return 0;
        }
        b[i] = lower_bound(all(u),b[i]) - u.begin() + 1;
        c[i] = lower_bound(all(u),c[i]) - u.begin() + 1;
        g[b[i]].push_back({c[i],i});
        g[c[i]].push_back({b[i],i});
    }
    vector<int> odd;
    for(int i=1;i<=sz(u);++i)
    {
        if(sz(g[i]) & 1)
            odd.push_back(i);
    }
    if(sz(odd) != 0 && sz(odd) != 2)
    {
        cout<<"-1\n";return 0;
    }
    if(sz(odd) == 2)
    {
        g[odd[0]].push_back({odd[1],n});
        g[odd[1]].push_back({odd[0],n});
    }
    vector<int> ans;
    vector<int> st{1};
    while(!st.empty())
    {
        int ver = st.back();
        while(!g[ver].empty() && done[g[ver].back().S])
            g[ver].pop_back();
        if(g[ver].empty())
        {
            ans.push_back(ver);
            st.pop_back();
            continue;
        }
        int to = g[ver].back().F;
        done[g[ver].back().S] = true;
        st.push_back(to);
        g[ver].pop_back();
    }
    debug(ans);
    if(sz(ans) != n + sz(odd)/2)
    {
        cout<<"-1\n";return 0;
    }
    if(sz(odd) == 0)
    {
        for(auto &j:ans)
            cout<<u[j-1]<<" ";
        cout<<"\n";
        return 0;
    }
    debug(ans);
    debug(odd);
    for(int i=0;i<sz(ans)-1;++i)
    {
        if((ans[i] == odd[0] && ans[i+1] == odd[1]) || (ans[i] == odd[1] && ans[i+1] == odd[0]))
        {
            for(int j=i+1;j<(sz(ans));++j)
                cout<<u[ans[j]-1]<<" ";
            for(int j=1;j<=i;++j)
                cout<<u[ans[j]-1]<<" ";
            return 0;
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