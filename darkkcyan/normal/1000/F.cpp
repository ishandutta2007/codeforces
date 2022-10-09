#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main
 
// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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
 
const int inf = (int)1e8;
struct segtree {
    int len;
    vector<pair<int, int>> min_val;
    segtree(int len_): len(len_), min_val(len * 2, {inf, -1}) {}
    
    void upd(int pos, int val) {
        if (pos < 0 or pos >= len) return ;
        clog << db(pos) << db(val) << endl;
        pos += len;
        min_val[pos] = {val, pos - len};
        for (pos >>= 1; pos > 0; pos >>= 1) {
            min_val[pos] = min(min_val[2 * pos], min_val[2 * pos + 1]);
        }
    }
    pair<int, int> get(int l, int r) {
        pair<int, int> ans = {inf, -1};
        for (l += len, r += len; l < r; l >>= 1, r >>= 1) { 
            if (l & 1) ans = min(ans, min_val[l ++ ]);
            if (r & 1) ans = min(ans, min_val[--r]);
        }
        return ans;
    }
};

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i: a) cin >> i;
    struct Query {
        int l, id;
    };
    vector<vector<Query>> qr(n + 1);
    int q;
    cin >> q;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        --l;
        qr[r].push_back({l, i});
    }
    vector<int> ans(q);
    
    segtree st(n);
    vector<int> last_pos((int)5e5 + 10, -1);
    rep(r, 1, n + 1) {
        int x = a[r - 1];
        st.upd(last_pos[x], inf);
        st.upd(r - 1, last_pos[x]);
        last_pos[x] = r - 1;
        for (auto [l, id]: qr[r]) {
            auto [t, p] = st.get(l, r);
            clog << db(id) << db(l) << db(r) << db(t) << endl;
            if (t >= l) continue;
            ans[id] = a[p];
        }
    }
    for (auto i: ans) cout << i << '\n';
    
    return 0;
}