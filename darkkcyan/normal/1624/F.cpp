#ifdef LOCAL
#define testing
#endif
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

int n;
struct secret {
    int x;
    int qr_left;
} s;

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}
void init() {
#ifdef testing
    n = rand(2, 10);
    s.x = rand(1, n - 1);
    s.qr_left = 10;
    cout << db(n) << db(s.x) << endl;
#else
    cin >> n;
#endif
}

int ask(int c) {
    cout << "+ " << c << endl;
#ifdef testing
    assert(1 <= c and c < n);
    --s.qr_left;
    if (s.qr_left == 0) {
        cout << "WA: query count exceeded" << endl;
        exit(0);
    }
    s.x += c;
    cout << db(s.x) << db(s.x / n) << endl;
    return s.x / n;
#else
    int ans;
    cin >> ans;
    return ans;
#endif
}

void answer(int num) {
    cout << "! " << num << endl;
#ifdef testing
    cout << db(s.x) << endl;
    if (num != s.x) {
        cout << "WA" << endl;
        exit(0);
    }
#endif
}

void solve() {
    init();
    int l = 1, r = n;
    while (r - l > 1) {
        int mid = (r + l + 1) / 2;
        int lower_div = l / n;
        int upper_div = lower_div + 1;
        int dest = upper_div * n - mid;
        clog << db(lower_div) << db(upper_div) << db(dest) << endl;
        int t = ask(dest);
        l += dest;
        r += dest;
        mid += dest;
        clog << db(l) << db(r) << db(mid) << db(t) << endl;
        if (t == upper_div) {
            l = mid;
        } else {
            r = mid;
        }
        clog << db(l) << db(r) << endl;
    }
    answer(l);
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin); 
    // freopen("main.out", "w", stdout);  
    // freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
#ifdef testing
    while (1) {
        cout << string(10, '-') << endl;
        solve();
    }
#else
    solve();
#endif
    
    return 0;
}

// vim: foldmethod=marker