#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T, class Ctor = less<T>>
using ordered_set = tree<T, null_type, Ctor, rb_tree_tag, tree_order_statistics_node_update>;


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

const int maxalpha = 4;
const int maxmod = 11;
unordered_map<char, int> alpha = {
    {'A', 0},
    {'T', 1},
    {'G', 2},
    {'C', 3}
};

ordered_set<int> sets[maxalpha][maxmod][maxmod];
string s;
int q;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> s;
    int n = sz(s);
    rep(i, 0, n) {
        rep(m, 1, maxmod) {
            sets[alpha[s[i]]][m][i % m].insert(i);
        }
    }
    
    cin >> q;
    
    while (q--) {
        DB();
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            char ch;
            cin >> p >> ch;
            --p;
            int oalpha = alpha[s[p]];
            int nalpha = alpha[ch];
            s[p] = ch;
            if (oalpha == nalpha) continue;
            rep(m, 1, maxmod) {
                sets[oalpha][m][p % m].erase(p);
                sets[nalpha][m][p % m].insert(p);
            }
        } else {
            int l, r;
            string patt;
            cin >> l >> r >> patt;
            --l;
            clog << db(l) << db(r) << db(patt) << endl;
            int ans = 0;
            rep(i, 0, sz(patt)) {
                DB();
                int calpha = alpha[patt[i]];
                int cur_mod = (i + l) % sz(patt);
                clog << db(i) << db(calpha) << db(cur_mod) << endl;
                auto& cur_set = sets[calpha][sz(patt)][cur_mod];
                auto cur_ans = cur_set.order_of_key(r) - cur_set.order_of_key(l);
                clog << db(cur_set) << endl;
                clog << db(cur_ans) << endl;
                ans += (int)cur_ans;
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker