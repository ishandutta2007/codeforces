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
    cin >> n;
    vector<int> d(n);
    for(int i=0;i<n;++i)
        cin >> d[i];
    vector<pii> ans;

    vector<int> have(d[n-1]+1),deg(d[n-1]+1);
    iota(all(have),1);

    int l = 0,r = n-1;
    while(l <= r)
    {
        for(int j=l+1;j<r;++j)
            d[j] -= d[l];
        for(int i=0;i<d[l];++i)
        {
            for(int j=i+1;j<d[l];++j)
            {
                ans.push_back({have[i],have[j]});
                ++deg[have[i]];
                ++deg[have[j]];
            }
            for(int j=d[l];j<sz(have);++j)
            {
                if(have[i] == have[j])
                    continue;
                ans.push_back({have[i],have[j]});
                ++deg[have[j]-1],++deg[have[i]-1];
            }
        }
        if(l+1 <= r-1)
        {
            vector<int> t;
            for(int i=0;i<d[r-1]+1;++i)
                t.push_back(have[d[l]+i]);
            have = t;
        }
        ++l,--r;
    }
    sort(all(deg));
    deg.resize(unique(all(deg))-deg.begin());
    debug(deg);
    cout << sz(ans) << "\n";
    for(auto [j,k]:ans)
        cout << j << " " << k << "\n";
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