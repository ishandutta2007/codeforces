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
#define debug(...) 2401
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
    int n, q;
    cin >> n >> q;
    fenwick<ll> fenw(n);
    vector<ll> a(n + 1);
    set<array<ll, 4>> s = {{1, n, 1, 0}};

    auto upd = [&](int l, int r, int c) {
        auto it = s.upper_bound({l+1,-1,-1,-1});
        --it;
        auto u = *it;
        debug(u);
        if(u[0] < l) {
            s.erase(it);
            auto v = u;
            u[1] = l - 1;
            s.insert(u);
            v[0] = l;
            s.insert(v);
        }
        it = s.upper_bound({r + 1, -1, -1, -1});
        --it;
        u = *it;
        // debug("Hi");
        if(u[1] > r) {
            s.erase(it);
            auto v = u;
            u[0] = r + 1;
            s.insert(u);
            v[1] = r;
            s.insert(v);
        }
        // debug("Bhai");

        // split done
        while(true) {
            auto it = s.lower_bound({l, -1, -1, -1});
            if(it == s.end() || (*it)[0] > r) {
                break;
            }
            auto u = *it;
            // debug(u);
            fenw.update(u[0], u[3] + a[u[2]]);
            fenw.update(u[1] + 1, -u[3] - a[u[2]]);
            s.erase(it);
        }
        s.insert({l, r, c, -a[c]});
    };

    auto query = [&](int i) {
        ll ans = fenw.get(i);
        auto it = s.upper_bound({i+1,-1,-1,-1});
        --it;
        auto u = *it;
        ans += u[3] + a[u[2]];
        return ans;
    };

    for(int i=1;i<=q;++i) {
        string st;
        cin >> st;
        if(st == "Color") {
            int l, r, c;
            cin >> l >> r >> c;
            upd(l, r, c);
        }
        else if(st == "Add") {
            int c, x;
            cin >> c >> x;
            a[c] += x;
        }
        else {
            int i;
            cin >> i;
            cout << query(i) << "\n";
        }
        // debug(s);
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
    // cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}