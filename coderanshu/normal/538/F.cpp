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
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin >> a[i];
    vector<int64_t> ans(n+1);
    for(int i=1;i<n;++i)
    {
        for(int j=1;;++j)
        {
            int l,r;
            if(j == 1)
                r = n-1;
            else
                r = (i+j-2)/(j-1) - 1;
            l = (i+j-1) / j;
            if(l < j)
                break;
            if(r >= l)
                ans[l] += a[j-1] > a[i],ans[r+1] -= a[j-1] > a[i];
            int u = (i+j-1)/j;
            if(u <= j)
                break;
            ans[j] += a[u-1] > a[i], ans[j+1] -= a[u-1] > a[i];
        }
    }
    for(int i=1;i<=n-1;++i)
    {
        ans[i] += ans[i-1];
        cout<<ans[i]<<" ";
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