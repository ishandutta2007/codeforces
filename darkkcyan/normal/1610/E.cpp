#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main

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

inline int solve(int n, vector<ll> a) {
    int max_gud = 1;
    rep(i, 0, n - 1) {
        ll u = a[i];
        auto it = upper_bound(all(a), u);
        int cur_gud = (int)(it - (a.begin() + i));
        if (it == a.end()) {
            clog << db(i) << db(cur_gud) << endl;
            max_gud = max(max_gud, cur_gud);
            continue;
        }
        ++cur_gud;
        ll v = *it;
        while (true) {
            ll nxt = 2 * v - u;
            clog << db(u) << db(v) << db(nxt) << endl;
            it = lower_bound(all(a), nxt);
            if (it == a.end()) break;
            ++cur_gud;
            v = *it;
        }
        clog << db(i) << db(cur_gud) << endl;
        max_gud = max(max_gud, cur_gud);
    }
    return n - max_gud;
}

bool is_gud(const vector<ll> a) {
    if (sz(a) <= 2) return true;
    ll sum = accumulate(all(a), 0);
    int cnt_small = 0;
    int cnt_big = 0;
    for (auto x: a) {
        if (x * sz(a) > sum) ++cnt_big;
        else if (x * sz(a) < sum) ++ cnt_small;
    }
    return cnt_big <= cnt_small;
}

int brute(int n, vector<ll> a) {
    int ans = n;
    rep(mask, 0, (1 << n)) {
        vector<ll> out;
        rep(i, 0, n) {
            if ((mask >> i) & 1) continue;
            out.push_back(a[i]);
        }
        
        bool ok = true;
        rep(sub, 0, (1 << sz(out))) {
            vector<ll> b;
            rep(i, 0, sz(out)) {
                if ((sub>> i) & 1) b.push_back(out[i]);
            }
            if (!is_gud(b)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            clog << db(out) << endl;
            ans = min(ans, __builtin_popcount(mask));
        }
    }
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void gen() {
    int n = rand() % 5 + 1;
    vector<ll> a(n);
    rep(i, 0, n) a[i] = rand() % 100 + 1;
    sort(all(a));
    auto ans = solve(n, a);
    auto exp = brute(n, a);
    if (ans == exp) {
        cout << "OK" << endl;
        return ;
    }
    
    ofstream inp("main.inp");
    inp << "1\n";
    inp << n << endl;
    for (auto i: a) inp <<  i << ' ';
    inp << endl;
    inp << db(ans) << endl;
    inp << db(exp) << endl;
    exit(0);
}

int jalsol_orz() {
    // while (1) gen();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto & i: a) cin >> i;
        cout << solve(n, a) << '\n';
#ifdef LOCAL
        cout << db(brute(n, a)) << '\n';
#endif
    }
    
    return 0;
}

// vim: foldmethod=marker