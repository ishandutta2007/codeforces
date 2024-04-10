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
    vector<ll> a(n+1),b(n+1),c(n);
    iota(all(c),1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];

    sort(all(c),[&](int x,int y) {
        return a[x] < a[y];
    });
    auto good = [&](vector<int> &ans)
    {
        ll A = 0,B = 0;
        for(int i=1;i<=n;++i)
            A += a[i],B += b[i];
        for(int i:ans)
            A -= 2 * a[i],B -= 2 * b[i];
        return A < 0 && B < 0;
    };
    vector<int> ans;
    for(int i=0;i<n;i+=2)
        ans.push_back(c[i]);
    if(n % 2 == 0)
        ans.push_back(c.back());
    if(good(ans))
    {
        cout<<sz(ans)<<"\n";
        for(auto &j:ans)
            cout<<j<<" ";
        cout<<"\n";
        return 0;
    }
    ans.clear();
    for(int i=1;i<n;i+=2)
        ans.push_back(c[i]);
    if(n % 2 == 0)
        ans.push_back(c[0]);
    else
        ans.push_back(c.back());
    assert(good(ans));
    cout<<sz(ans)<<"\n";
    for(auto &j:ans)
        cout<<j<<" ";
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