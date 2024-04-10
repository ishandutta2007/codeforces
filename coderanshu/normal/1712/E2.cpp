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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif

const int N = 2e5 + 5;

vector<ll> divs[N];

template<typename T=long long>
struct fenwick {
    vector<T> bit;
    int n;
    fenwick(int x) {
        n = x;
        bit.resize(x + 1, T(0));
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
    // kth element
    int getKth(T k) {
        int ans = 0;
        T cnt = 0;
        for(int i=20;i>=0;--i) {
            if(ans + (1 << i) <= n && cnt + bit[ans + (1 << i)] < k) {
                ans += (1 << i);
                cnt += bit[ans];
            }
        }
        if(ans == n) {
            return -1;
        }
        return ans + 1;
    }
    void insert(int x) {
        update(x, 1);
    }
    void erase(int x) {
        update(x, -1);
    }
};

int _runtimeTerror_()
{
    for(int i=1;i<=2e5;++i) {
        for(int j=2*i;j<=2e5;j+=i) {
            divs[j].push_back(i);
        }
    }
    int Q;
    cin >> Q;
    vector<vector<array<int, 2>>> queries(N);
    vector<ll> ans(Q);
    for(int i=0;i<Q;++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
        ll len = (r - l + 1);
        ans[i] = len * (len - 1) * (len - 2) / 6;
        if(2 * l <= r) {
            ans[i] -= r / 6 - (2 * l + 5) / 6 + 1;
        }
        int f = 5 * l / 2;
        if(2 * f / 5 < l) {
            ++f;
        }
        if(f <= r) {
            ans[i] -= r / 15 - (f + 14) / 15 + 1;
        }
    }
    debug(ans);
    fenwick<ll> fenw(N);
    for(int i=1;i<=2e5;++i) {
        auto &u = divs[i];
        int cur = 1;
        for(int j=sz(u)-2;j>=0;--j) {
            fenw.update(1, cur);
            fenw.update(u[j] + 1, -cur);
            ++cur;
        }
        for(auto &[l, id]:queries[i]) {
            ans[id] -= fenw.get(l);
        }
    }
    for(int i=0;i<Q;++i) {
        cout << ans[i] << "\n";
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
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}