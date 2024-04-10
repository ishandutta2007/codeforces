#include <bits/stdc++.h>
using namespace std;

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

int main() {
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> cnt(n + 1);
        rep(i, 0, n) {
            int u;
            cin >> u;
            a[i] = u;
            cnt[u]++;
        }
        
        int l = 0, r = 0;
        int delta = -n;
        tuple<int, int, int> ans = {INT_MAX, 0, 0};
        for (r = 1; r <= n + 1; ++r) {
            while (l < r and (delta - 2 * cnt[l]) >= k) {
                delta -= 2 * cnt[l++];
            }
            clog << db(delta) << db(l) << db(r) << endl;
            if (delta >= k) ans = min(ans, {r - l, l, r});
            if (r <= n) delta += 2 * cnt[r];
        }
        
        int min_len;
        tie(min_len, l, r) = ans;
        cout << l << ' ' << r - 1<< '\n';
        for (l = 0; l < n and k > 1; ) {
            delta = 0;
            for (r = l; r < n; ++ r) {
                delta += get<1>(ans) <= a[r] and a[r] < get<2>(ans) ? 1 : -1;
                if (delta > 0) break;
            }
            cout << l + 1 << ' ' << r + 1 << '\n';
            l = r + 1;
            --k;
        }
        cout << l + 1 << ' ' << n << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker