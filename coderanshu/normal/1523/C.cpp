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
    vector<int> a(n);
    vector<vector<int>> ans;
    for(int i=0;i<n;++i)
        cin>>a[i];
    ans.push_back({1});
    for(int i=1;i<n;++i)
    {
        if(a[i] == 1)
        {
            auto u = ans.back();
            u.push_back(1);
            ans.push_back(u);
            continue;
        }
        auto u = ans.back();
        while(!u.empty() && u.back() != a[i]-1)
            u.pop_back();
        assert(!u.empty());
        ++u.back();
        ans.push_back(u);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<sz(ans[i]);++j)
        {
            cout<<ans[i][j];
            if(j < sz(ans[i]) - 1)
                cout<<".";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}