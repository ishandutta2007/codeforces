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

const int maxn = 1111;
int n;
int a[maxn];

ll brute() {
    vector<int> s;
    rep(i, 0, n) {
        rep(f, 0, a[i]) s.push_back(i & 1 ? -1 : 1);
    }
    
    ll ans = 0;
    rep(start, 0, sz(s)) {
        ll cur = 0;
        rep(end, start, sz(s)) {
            cur += s[end];
            if (cur == 0) ++ans;
            if (cur < 0) break;
        }
    }
    return ans;
}


ll solve() {
    ll ans = 0;
    for (int start = 0; start < n; start += 2) {
        ll cur = a[start];
        ll lv = 0;
        ll cur_ans = 0;
        for (int end = start + 1; end < n; end += 2) {
            lv += a[end - 1];
            ll inter = max(0ll, cur - (lv - a[end]));
            cur_ans += min(inter, cur);
            cur = max(0ll, cur - max(inter - 1, 0ll));
            clog << db(start) << db(end) << db(inter) << db(cur) << db(cur_ans) << db(lv) << endl;
            lv -= a[end];
        }
        clog << db(start) << db(cur_ans) << endl;
        ans += cur_ans;
    }
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    n = rand() % 100 + 1; 
    rep(i, 0, n) {
        a[i] = rand() % 100 + 1;
    }
    auto ans = solve();
    auto exp = brute();
    if (ans == exp) {
        cout << "OK" << endl;
        return;
    }
    ofstream inp("main.inp");
    inp << n << endl;
    rep(i, 0, n) inp << a[i] << ' ';
    inp << endl;
    inp << db(ans) << db(exp) << endl;
    exit(0);
}

int main() {
    // while (1) check();  
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    
    cout << solve();
    
    return 0;
}

// vim: foldmethod=marker