#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

bool brute(ll u, ll v) {
    DB();
    if (u > v) return false;
    vector<ll> trace(v + 1, -1);
    queue<ll> qu;
    for (qu.push(u), trace[u] = u ; qu.size(); qu.pop()) {
        u = qu.front();
        if (u == v) {
            for (ll x = v; x != u; x = trace[x]) clog << x << endl;
            clog << u << endl;
            return true;
        }
        for (ll s = u; s > 0; s = (s - 1) & u) {
            assert((u & s) == s);
            ll nv = u + s;
            if (nv > v) continue;
            if (trace[nv] != -1) continue;
            trace[nv] = u;
            qu.push(nv);
        }
    }
    return false;
}

bool solve(ll u, ll v) {
    DB(); 
    if (u > v) return false;
    clog << bitset<7>(u) << ' ' << bitset<7>(v) << endl;
    int cntu = __builtin_popcountll(u);
    int cntv = __builtin_popcountll(v);
    
    if (cntu < cntv) return false;
    
    int diff = cntu - cntv;
    bool first = true;
    int high_v = 63 - __builtin_clzll(v);
    clog << db(high_v) << endl;
    for (int i = 33; i-- and diff; ) {
        if (!((u >> i) & 1) ) continue;
        if (first) {
            clog << db(i) << endl;
            if (i == high_v) {
                v -= 1ll << i;
                u -= 1ll << i;
                high_v = 63 - __builtin_clzll(v);
                
                continue;
            }
            u += 1ll << i;
            first = false;
            continue;
        }
        u -= 1ll << i;
        --diff;
    }
    clog << db(u) << db(v) << db(diff) << endl;
    clog << bitset<7>(u) << ' ' << bitset<7>(v) << endl;
    if (diff) return false;
    for (int i = 33; i--; ) {
        if (!((u >> i) & 1)) continue;
        high_v = 63 - __builtin_clzll(v);
        clog << db(i) << db(high_v) << endl;
        if (i > high_v) return false;
        for (int t = i; t < high_v; ++t) u += 1ll << i;
        v -= 1ll << high_v;
    }
    return true;
}

void print_ans(bool ans) {
    cout << (ans ? "YES\n" : "NO\n");
}

void stress() {
    mt19937 rng;
#define rand() ((int)(rng() >> 1))
    while (true) {
        ll u = rand() % 100 + 1, v = rand() % 100 + 1;
        ll exp = brute(u, v);
        ll ans = solve(u, v);
        if (exp == ans) {
            cout << "OK" << endl;
            continue;
        }
        cout << "FAILED" << endl;
        ofstream inp("main.inp");
        inp << "1\n" << u << ' ' << v << endl;
        inp << ans << endl << exp << endl;
        inp.close();
        exit(0);
    }
}

int main(void) {
    // stress();      
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        ll u, v; cin >> u >> v;
        print_ans(solve(u, v));
#ifdef LOCAL
        print_ans(brute(u, v));
        cout << endl;
#endif
    }
    
    return 0;
}

// vim: foldmethod=marker