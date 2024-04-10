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
    int n, Q;
    cin >> n >> Q;
    fenwick<int> row(n), col(n);
    vector<int> r(n + 1), c(n + 1);
    auto add = [&](int x, int y) {
        ++r[x];
        ++c[y];
        row.update(x, (r[x] == 1));
        col.update(y, (c[y] == 1));
    };
    auto del = [&](int x, int y) {
        --r[x];
        --c[y];
        row.update(x, (r[x] == 0) * -1);
        col.update(y, (c[y] == 0) * -1);
    };
    auto check = [&](int x1, int x2, int y1, int y2) {
        bool good = row.query(x1, x2) == x2 - x1 + 1;
        good = good || (col.query(y1, y2) == y2 - y1 + 1);
        return good ? "Yes": "No";
    };
    for(int i=1;i<=Q;++i) {
        int tt, x1, x2, y1, y2;
        cin >> tt;
        if(tt == 1) {
            cin >> x1 >> y1;
            add(x1, y1);
        }
        else if(tt == 2) {
            cin >> x1 >> y1;
            del(x1, y1);
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << check(x1, x2, y1, y2) << "\n";
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
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}