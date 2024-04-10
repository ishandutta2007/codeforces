#ifdef LOCAL
// #define testing  
#endif
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


mt19937 rng;
#define rand() ((int)(rng() >> 1))
#ifdef testing
namespace h {
    vector<int> p;
};
#endif

int n;
void init() {
#ifdef testing
    n = rand() % 10 + 1;
    h::p.resize(n);
    rep(i, 0, n) h::p[i] = i + 1;
    shuffle(all(h::p), rng);
    cout << db(n) << endl;
    cout << db(h::p) << endl;
#else
    cin >> n;
#endif
}

int ask(const vector<int>& a) {
    assert(sz(a) == n);
    cout << "? ";
    for (auto i: a) cout << i << ' ';
    cout << endl;
#ifdef testing
    vector<int> pos(3 * n, -1);
    int ans = 0;
    rep(i, 0, n) {
        int s = a[i] + h::p[i];
        if (pos[s] == -1) {
            pos[s] = i;
        } else {
            ans = pos[s] + 1;
            break;
        }
    }
    cout << db(ans) << endl;
    return ans;
#else
    int x;
    cin >> x;
    return x;
#endif
}

void answer(const vector<int>& p) {
    assert(sz(p) == n);
    cout << "! " ;
    for (auto i: p) cout << i << ' ';
    cout << endl;
#ifdef testing
    if (p == h::p) {
        cout << "OK" << endl;
        return ;
    }
    cout << "NO" << endl;
    exit(0);
#else
#endif
}

void solve() {
    init();
    vector<int> diff(n);
    int u = 1, v = n;
    rep(the_diff, -(n - 1), n) {
        vector<int> a(n, v);
        a.back() = u;
        int x = ask(a);
        if (x) {
            diff[x - 1] = the_diff;
        }
        if (u < n) ++u;
        else --v;
    }
    int mi = *min_element(all(diff));
    clog << db(mi) << endl;
    rep(i, 0, n) diff[i] -= mi - 1;
    answer(diff);
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    // freopen(".log", "w", stderr); 
#endif
    cin.tie(0)->sync_with_stdio(0);
#ifdef testing
    while (true) solve();
#else
    solve();
#endif
    
    return 0;
}

// vim: foldmethod=marker