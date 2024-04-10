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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    
    // 2 * (c11 + c10) >= c11 + c10 + c01 + c00
    // <=> c11 + c10 >= c01 + c00
    // <=> c10 - c01 >= c00 - c11
    // c11 + c01 >= c10 + c00
    // <=> c01 - c10 >= c00 - c11
    // -(c11 - c00) <= c01 - c10 <= c11 - c00
    
    int n;
    cin >> n;
    vector<int> groups[4];
    rep(i, 0, n) {
        string s;
        int val;
        cin >> s >> val;
        int id = (s[0] - '0') * 2 + s[1] - '0';
        groups[id].push_back(val);
    }
    
    if (sz(groups[1]) > sz(groups[2])) swap(groups[1], groups[2]);
    rep(i, 0, 4) {
        sort(all(groups[i]), greater<>());
    }
    
    vector<ll> gsum[4];
    rep(i, 0, 4) {
        gsum[i].resize(sz(groups[i]) + 1);
        rep(f, 0, sz(groups[i]))
            gsum[i][f + 1] = gsum[i][f] + groups[i][f];
    }
    
    ll ans = 0;
    rep(cnt00, 0, sz(groups[0]) + 1) {
        int diff11_00 = sz(groups[3]) - cnt00;
        if (diff11_00 < 0) continue;
        ll cur_ans = gsum[3].back() + gsum[0][cnt00];
        clog << db(cur_ans) << endl;
        cur_ans += gsum[1].back() + gsum[2][sz(groups[1]) + min(sz(groups[2]) - sz(groups[1]), diff11_00)];
        clog << db(cnt00) << db(diff11_00) << db(cur_ans) << endl;
        ans = max(ans, cur_ans);
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker