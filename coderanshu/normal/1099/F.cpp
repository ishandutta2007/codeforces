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
public:
    const static int N = 1000005;
    T bit[N],cnt[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            bit[i] = cnt[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
    }
    void update(int j,T val,T c)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val, cnt[j] += c;
    }
    pair<T,T> get(int r)
    {
        pair<T,T> u;
        for(;r;r-=r&-r) 
        {
            u.F += bit[r];
            u.S += cnt[r]; 
        }
        return u;
    }
    T query(ll x)
    {
        if(x < 0)
            return T(0);
        auto u = get(n);
        if(u.F <= x)
            return u.S;
        ll ans = 0,cur = 0;
        for(int i=20;i>=0;--i) 
        {
            if(cur + (1<<i) > n) 
                continue;
            ll f = bit[cur+(1<<i)], g = cnt[cur+(1<<i)];
            if(x >= f)
                x -= f,cur += (1<<i),ans += g;
        }
        if(x == 0)
            return ans;
        ans += x/(cur+1);
        return ans;
    }
};
// call fenw.build(n);

fenwick<ll> fenw;

vector<int> v[N];

int x[N],t[N],l[N];

ll ans = 0, T;

ll dfs(int s,ll up = 0)
{
    up += l[s];
    fenw.update(t[s],x[s] * 1ll * t[s],x[s]);
    ll mx = 0;
    vector<ll> got;
    for(auto &j:v[s])
    {
        got.push_back(dfs(j,up));
    }
    sort(all(got));
    if(!got.empty() && s != 1)
        got.pop_back();
    if(!got.empty())
        amax(mx,got.back());
    amax(mx,fenw.query(T - 2 * up));
    fenw.update(t[s],-x[s] * 1ll * t[s],-x[s]);
    return mx;
}

int _runtimeTerror_()
{
    int n;
    cin >> n >> T;
    fenw.build(fenwick<>::N-5);
    for(int i=1;i<=n;++i)
        cin >> x[i];
    for(int i=1;i<=n;++i)
        cin >> t[i];
    for(int i=2;i<=n;++i) 
    {
        int p;
        cin >> p >> l[i];
        v[p].push_back(i);
    }
    cout << dfs(1) << "\n";
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