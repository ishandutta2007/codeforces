#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

vector<pair<bool, llong>> proc(const vector<llong>& a) {
    vector<pair<bool, llong>> ans;
    ans.emplace_back(true, 0);
    rep(i, len(a)) {
        if (!ans.back().first) {
            ans.emplace_back(false, -1);
            continue;
        }
        if (a[i] < ans.back().second) {
            ans.emplace_back(false, -1);
            continue;
        }
        ans.emplace_back(true, a[i] - ans.back().second);
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB("TEST");
        int n; cin >> n;
        vector<llong> a(n);
        rep(i, n) cin >> a[i];
        auto from_left = proc(a);
        if (from_left.back().first and from_left.back().second == 0) {
            cout << "YES\n";
            continue;
        }
        reverse(a.begin(), a.end());
        auto from_right = proc(a);
        reverse(a.begin(), a.end());
        
        bool ok = false;
        rep(i, n - 1) {
            DB(i);
            auto [lok, l_rem] = from_left[i];
            auto [rok, r_rem] = from_right[n - i - 2];
            clog << db(lok) << db(rok) << endl;
            clog << db(l_rem) << db(r_rem) << endl;
            if (!lok or !rok) continue;
            llong u = a[i + 1], v = a[i];
            clog << db(u) << db(v) << endl;
            if (u < l_rem) continue;
            u -= l_rem;
            if (v < u) continue;
            v -= u;
            if (v != r_rem) continue;
            ok = true;
            break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    
    return 0;
}

// vim: foldmethod=marker