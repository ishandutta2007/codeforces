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

struct BIT {
    vector<int> data;
    BIT() = default;
    BIT(int len): data(len + 10, 0) {}
    int get(int i) const {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += data[i];
        return ans;
    }
    void upd(int i, int v) {
        for (++i; i < sz(data); i += i & -i) data[i] += v;
    }
};

struct Query {
    int a, t, x;
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Query> queries(n);
    for (auto& [a, t, x]: queries) cin >> a >> t >> x;
    vector<int> xvals(n);
    rep(i, 0, n) xvals[i] = queries[i].x;
    sort(all(xvals));
    xvals.erase(unique(all(xvals)), xvals.end());
    for (auto& [a, t, x]: queries) {
        x = (int)(lower_bound(all(xvals), x) - xvals.begin());
    }
    
    vector<vector<int>> tvals(sz(xvals));
    for (auto& [a, t, x]: queries) {
        tvals[x].push_back(t);
    }
    
    vector<BIT> bits;
    for (auto& tv: tvals) {
        sort(all(tv));
        tv.erase(unique(all(tv)), tv.end());
        bits.emplace_back(sz(tv));
    }
    
    for (auto& [a, t, x]: queries) {
        t = (int)(lower_bound(all(tvals[x]), t) - tvals[x].begin());
        switch (a) {
            case 1:
                bits[x].upd(t, 1);
                break;
            case 2:
                bits[x].upd(t, -1);
                break;
            case 3:
                cout << bits[x].get(t) << '\n';
                break;
            default:
                assert(false);
                break;
        }
    }
    
    return 0;
}

// vim: foldmethod=marker