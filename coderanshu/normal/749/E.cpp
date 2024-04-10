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


const int N = 100005;
template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};
// call fenw.build(n);

fenwick<ll> fenw,cnt;

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];  
    fenw.build(n);
    cnt.build(n);
    long double ans = 0;
    int64_t den = n * 1ll *(n + 1)/2;
    for(int i=1;i<=n;++i)
    {
        int64_t u = fenw.get(a[i]);
        int64_t d = cnt.query(a[i],n);
        ans += u * (n - i + 1) / 2.0 / den;
        u = fenw.query(a[i],n);
        ans += (d * den - u * (n - i + 1)) * 1.0 / den;
        ans += (u * (n - i + 1)) / 2.0 / den;
        fenw.update(a[i],i);
        cnt.update(a[i],1);
    }
    cout<<fixed<<setprecision(15);
    cout<<ans<<"\n";
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