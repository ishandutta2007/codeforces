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

int n, s, x;
void init() {
    cin >> n >> s >> x;
}
pair<int, int> ask(int i) {
    cout << "? " << i << endl;
    int value, nxt;
    cin >> value >> nxt;
    return {value, nxt};
}

void answer(int num) {
    cout << "! " << num << endl;
}

void solve() {
    static mt19937 rng((ll)solve ^ time(0));
    init();
    int ans = INT_MAX;
    
    vector<int> ids;
    rep(i, 0, n) ids.push_back(i);
    shuffle(all(ids), rng);
    
    int try_iter = 1500;
    int finding_iter = 300;
    
    auto start_pos = ask(s);
    
    rep(i, 0, min(try_iter, n)) {
        auto [v, nxt] = ask(ids[i] + 1);
        if (v == x) {
            answer(x);
            return ;
        }
        if (v > x) ans = min(ans, v);
        else start_pos = max(start_pos, {v, nxt});
    }
    
    for (int i = finding_iter; i-- and start_pos.first < x and start_pos.second != -1; ) {
        start_pos = ask(start_pos.second);
    }
    
    if (start_pos.first >= x) ans = start_pos.first;
    if (ans == INT_MAX) answer(-1);
    else answer(ans);
}
    
int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    solve();
    
    return 0;
}

// vim: foldmethod=marker