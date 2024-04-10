#ifdef LOCAL
// #define inter
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
int rand_range(int a, int b) {
    return rand() % (b - a + 1) + a;
}
int n;
struct secret {
    vector<int> arr;
    int qr_cnt;
    secret() {
        arr.resize(n);
        rep(i, 0 , n) arr[i] = rand() % n;
        qr_cnt = n + 2;
    }
};
secret s;
void init() {
#ifdef inter
    n = 1 << rand_range(2, 4);
    s = secret();
    cout << db(n) << endl;
    cout << db(s.arr) << endl;
#else
    cin >> n;
#endif
}

int ask(const string& cmd, int i, int j) {
    cout << cmd << ' ' << i << ' ' << j << endl;
#ifdef inter
    --s.qr_cnt;
    assert(s.qr_cnt >= 0);
    int ans = -1;
    if (cmd == "AND") {
        ans = s.arr[i - 1] & s.arr[j - 1];
    }
    if (cmd == "XOR") {
        ans = s.arr[i - 1] ^ s.arr[j - 1];
    }
    if (cmd == "OR") {
        ans = s.arr[i - 1] | s.arr[j - 1];
    }
    assert(ans != -1);
    cout << "= " << ans << endl;
    return ans;
#else
    int ans;
    cin >> ans;
    return ans;
#endif
}

void answer(const vector<int>& a) {
    cout << "! ";
    for (auto i: a) cout << i << ' ';
    cout << endl;
#ifdef inter
    cout << a << endl;
    cout << s.arr << endl;
    assert(a == s.arr);
#endif
}

int l2(int num) {
    return 31 - __builtin_clz(num);
}

bool bit_of(int x, int b) {
    return (x >> b) & 1;
}

void solve() {
    init();
    int x12 = ask("XOR", 1, 2);
    int x23 = ask("XOR", 2, 3);
    int x13 = x12 ^ x23;
    clog << db(x13) << endl;
    int a12 = ask("AND", 1, 2);
    int a23 = ask("AND", 2, 3);
    int a13 = ask("AND", 1, 3);
    vector<int> ans(n);
    for (int mx_bit = l2(n); mx_bit --; ) {
        if (bit_of(x12, mx_bit) == 0) {
            int c = bit_of(a12, mx_bit);
            int d = c ^ bit_of(x13, mx_bit);
            ans[0] |= c << mx_bit;
            ans[1] |= c << mx_bit;
            ans[2] |= d << mx_bit;
        } else if (bit_of(x23, mx_bit) == 0) {
            int c = bit_of(a23, mx_bit);
            int d = c ^ bit_of(x13, mx_bit);
            ans[0] |= d << mx_bit;
            ans[1] |= c << mx_bit;
            ans[2] |= c << mx_bit;
        } else {
            assert(bit_of(x13, mx_bit) == 0);
            int c = bit_of(a13, mx_bit);
            int d = c ^ bit_of(x12, mx_bit);
            ans[0] |= c << mx_bit;
            ans[1] |= d << mx_bit;
            ans[2] |= c << mx_bit;
        }
    }
    for (int i = 3; i < n; ++i) {
        ans[i] = ask("XOR", 1, i + 1) ^ ans[0];
    }
    answer(ans);
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin); 
    // freopen("main.out", "w", stdout);  
    // freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
#ifdef inter
    while (true) {
        cout << string(10, '-') << endl;
        solve();
        cout << "OK" << endl;
    }
#else
    solve();
#endif
    
    
    return 0;
}

// vim: foldmethod=marker