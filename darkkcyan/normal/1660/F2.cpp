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
 
struct BIT {
    vector<int> data;
    BIT(int len): data(len + 10) {}
    int get(int i) {
        int ans = 0;
        for (++i; i > 0 ; i -= i & -i) ans += data[i];
        return ans;
    }
    
    void upd(int i, int v) {
        for (++i; i < sz(data); i += i & -i) data[i] += v;
    }
};

int jalsol_orz() {
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
        string s;
        cin >> s;
        vector<int> pref_sum(n + 1);
        rep(i, 0, n) {
            pref_sum[i + 1] = pref_sum[i] + (s[i] == '+' ? 1 : -1);
        }
        
        auto [mi, ma] = minmax_element(all(pref_sum));
        vector<BIT> bit(3, *ma - *mi + 1);
        clog << db(pref_sum) << endl;
        ll ans = 0;
        
        bit[0].upd(*ma - 0, 1);
        rep(i, 0, n) {
            auto val = pref_sum[i + 1];
            int m3 = val % 3;
            if (m3 < 0) m3 += 3;
            auto cnt = bit[m3].get(*ma - val);
            ans += cnt;
            bit[m3].upd(*ma - val, 1);
            clog << db(i) << db(val) << db(m3) << db(cnt) << endl;
        }
        cout << ans << '\n';
    }
    
    return 0;
}