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
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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

void find_pattern() {
    struct cus_cmp {
        bool operator()(const vector<bool>& u, const vector<bool>& v) const {
            int c1u = accumulate(all(u), 0);
            int c1v = accumulate(all(v), 0);
            if (c1u != c1v) return c1u < c1v;
            return u < v;
        }
    };
    const int maxlen = 10;
    set<vector<bool>, cus_cmp> signs[maxlen];
    
    signs[1] = {{0}};
    rep(len, 2, maxlen) {
        rep(op, 0, len - 1) {
            for (auto cur: signs[len - 1]) {
                auto t = !cur[op];
                cur[op] = t;
                cur.insert(cur.begin() + op, t);
                signs[len].insert(cur);
            }
        }
    }
    rep(len, 1, maxlen) {
        DB();
        clog << db(len) << endl;
        int cnt = 0;
        for (auto cur: signs[len]) {
            clog << setw(3) << ++cnt << cur << endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    vector<int> pos(n);
    rep(i, 0, n) pos[i] = i;
    sort(all(pos), [&](int u, int v) { return a[u] > a[v]; });
    
    ll sum = -accumulate(all(a), 0ll);
    clog << db(sum) << endl;
    
    vector<bool> picked(n);
    
    int pos_mod = (5 - n % 3) % 3;
    clog << db(pos_mod) << endl;
    ll ans = LLONG_MIN;
    int it = 0;
    for (int i = pos_mod; i <= n; i += 3) {
        while (it < i) {
            picked[pos[it]] = true;
            sum += 2 * a[pos[it]];
            ++it;
        }
        clog << db(it) << db(sum) << endl;
        
        if (n % 2 == 0 or (i != n / 2 and i - 1 != n / 2)) {
            ans = max(ans, sum);
            continue;
        }
        clog << "check alter" << endl;
        clog << db(picked) << endl;
        bool ok = false;
        rep(f, 0, n - 1) {
            if (picked[f] == picked[f + 1]) {
                ok = true;
                break;
            }
        }
        clog << db(ok) << endl;
        if (ok) {
            ans = max(ans, sum);
            continue;
        }
        ll cur_sum = sum - 2 * (a[pos[it - 1]] - a[pos[it]]);
        ans = max(ans, cur_sum);
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker