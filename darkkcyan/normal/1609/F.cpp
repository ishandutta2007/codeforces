#pragma GCC optimize ("Ofast", "unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct SumSegtree {
    int n;
    vector<int> it;
    vector<int> lazy;
    SumSegtree(int n_): n(n_), it(4 * n), lazy(8 * n) {}
    
    void push(int i, int l, int r) {
        if (!lazy[i]) return ;
        it[i] += lazy[i] * (r - l);
        // if (r - l > 1) {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        // }
        lazy[i] = 0;
    }
    
    void add(int from, int to, int val, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            lazy[i] += val;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        add(from, to, val, 2 * i, l, mid);
        add(from, to, val, 2 * i + 1, mid, r);
        it[i] = it[2 * i] + it[2 * i + 1];
    }
    
    void add(int from, int to, int val) {
        clog << "add sum" << db(from) << db(to) << db(val) <<endl;
        add(from, to, val, 1, 0, n);
    }
};
 
struct XorSegtree {
    int n;
    vector<int> it;
    vector<char>  lazy;
    XorSegtree(int n_): n(n_), it(4 * n), lazy(8 * n) {}
    
    inline void push(int i, int l, int r) {
        if (lazy[i]) {
            it[i] = r - l - it[i];
            // if (r - l > 1) {
                lazy[2 * i] = !lazy[2 * i];
                lazy[2 * i + 1] = !lazy[2 * i + 1];
            // }
            lazy[i] = false;
        }
    }
    
    inline void flip(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            lazy[i] = !lazy[i];
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        flip(from, to, 2 * i, l, mid);
        flip(from, to, 2 * i + 1, mid, r);
        it[i] = it[2 * i] + it[2 * i + 1];
    }
    
    inline void flip(int from, int to) {
        clog << "flip " << db(from) << db(to) <<endl;
        flip(from, to, 1, 0, n);
    }
    void reset() {
        memset(it.data(), 0, sizeof(int) * 4 * n);
        memset(lazy.data(), 0, sizeof(char) * 4 * n);
    }
};
 
const int maxn = 1010101;
// #ifdef LOCAL
// const int maxbit = 10;
// #else
const int maxbit = 60;
// #endif
int n;
ll a[maxn];

ll solve() {
    vector<int> pc(n);
    rep(i, 0, n) pc[i] = __builtin_popcountll(a[i]);
    ll ans  = 0;
    
    ll cur_sum = 0;
    static vector<int> mi_stk, mx_stk;
    mi_stk.reserve(n);
    mx_stk.reserve(n);
    mi_stk.push_back(-1);
    mx_stk.push_back(-1);
    vector<vector<tuple<int, int, int>>> updates(maxbit);
    rep(i, 0, n) {
        while (mi_stk.back() != -1 and a[mi_stk.back()] >= a[i]) {
            int p = mi_stk.back();
            mi_stk.pop_back();
            cur_sum -= p - mi_stk.back();
            // sst.add(mi_stk.back() + 1, p + 1, -1);
            updates[pc[p]].emplace_back(i, mi_stk.back() + 1, p + 1);
        }
        while (mx_stk.back() != -1 and a[mx_stk.back()] <= a[i]) {
            int p = mx_stk.back();
            mx_stk.pop_back();
            cur_sum -= p - mx_stk.back();
            // sst.add(mx_stk.back() + 1, p + 1, -1);
            updates[pc[p]].emplace_back(i, mx_stk.back() + 1, p + 1);
        }
        // sst.add(mi_stk.back() + 1, i + 1, 1);
        // sst.add(mx_stk.back() + 1, i + 1, 1);
        cur_sum += i - mi_stk.back();
        cur_sum += i - mx_stk.back();
        int u = mi_stk.back();
        int v = mx_stk.back();
        if (u > v) swap(u, v);
        updates[pc[i]].emplace_back(i, u + 1, v + 1);
        mi_stk.push_back(i);
        mx_stk.push_back(i);
        // ans += sst.it[1];
        ans += cur_sum;
    }
    
    vector<int> order(maxbit);
    rep(i, 0, maxbit) order[i] = i;
    sort(all(order), [&](int u, int v) {
            return sz(updates[u]) < sz(updates[v]);
            });
    
    XorSegtree xst(n);
    for (auto bit: order) {
        // cerr << db(bit) << endl;
        auto& curup = updates[bit];
        int prv = 0;
        auto upd = [&](int cur) {
            ll all_xor = xst.it[1];
            ll len = cur - prv;
            ans -= all_xor * len;
            prv = cur;
        };
        for (auto& [i, l, r]: curup) {
            if (i != prv) {
                upd(i);
            }
            xst.flip(l, r);
        }
        upd(n);
        if (bit == order.back()) break;
        for (int i = sz(curup); i--; ) {
            auto [_, l, r] = curup[i];
            xst.flip(l, r);
        }
    }
    return ans / 2;
}

// #define gentest

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    // freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
#ifndef gentest
    cin >> n;
    rep(i, 0, n) cin >> a[i];
#else
    n = (int)1e6;
    mt19937_64 rng;
    rep(i, 0, n) {
        a[i] = (1ll << (i % 60)) - 1;
        assert(a[i] >= 0);
    }
#endif
    cout << solve();
    
    return 0;
}

// vim: foldmethod=marker