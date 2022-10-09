// #define inter  
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

const int maxbit = 31;
using uint = unsigned int;
int n, k;
vector<uint> __hidden;
int __cnt_query;

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void init() {
#ifndef inter
    cin >> n >> k;
#else 
    n = rand() % 7 + 3;
    k = rand() % n + 1; 
    __hidden.resize(n); 
    rep(i, 0, n) __hidden[i] = rand() % 10 + 1; 
    n = 7; 
    k = 6; 
    __hidden = {1,6,4,2,3,5,4}; 
#endif
    __cnt_query = 0;
}

uint ask_and(int u, int v) {
    cout << "and " << u << ' ' << v << endl;
    ++__cnt_query;
#ifndef inter
    uint ans; cin >> ans;
    return ans;
#else 
    return __hidden[u - 1] & __hidden[v - 1];
#endif
}

uint ask_or(int u, int v) {
    cout << "or " << u << ' ' << v << endl;
    ++__cnt_query;
#ifndef inter
    uint ans; cin >> ans;
    return ans;
#else 
    return __hidden[u - 1] | __hidden[v - 1];
#endif
}

void answer(uint ans) {
    cout << "finish " << ans << endl;
#ifndef inter
#else
    auto x = __hidden;
    sort(all(__hidden));
    if (__hidden[k - 1] != ans) {
        cout << "FAILED" << endl;
        cout << n << ' ' << k << endl;
        cout << x << endl;
        cout << db(ans) << endl;
        exit(0);
    }
    if (__cnt_query > 2 * n) {
        cout << "FAILED" << endl;
        cout << db(__cnt_query) << db(2 * n) << endl;
        exit(0);
    }
    cout << "OK" << endl;
#endif
}

tuple<int, int, int> num[1 << 6];
void precal() {
    rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) {
        int mask = 0;
        mask = mask << 1 | (a | b);
        mask = mask << 1 | (b | c);
        mask = mask << 1 | (c | a);
        
        mask = mask << 1 | (a & b);
        mask = mask << 1 | (b & c);
        mask = mask << 1 | (c & a);
        
        num[mask] = {a, b, c};
    }
}

tuple<uint, uint, uint> find(int or12, int or23, int or32, int and12, int and23, int and31) {
    uint a = 0, b = 0, c = 0;
    for (int bit = maxbit; bit--; ) {
        int mask = 0;
        mask = mask << 1 | ((or12 >> bit) & 1);
        mask = mask << 1 | ((or23 >> bit) & 1);
        mask = mask << 1 | ((or32 >> bit) & 1);
        
        mask = mask << 1 | ((and12 >> bit) & 1);
        mask = mask << 1 | ((and23 >> bit) & 1);
        mask = mask << 1 | ((and31 >> bit) & 1);
        auto [ba, bb, bc] = num[mask];
        a = a << 1 | ba;
        b = b << 1 | bb;
        c = c << 1 | bc;
    }
    return {a, b, c};
}

void solve() {
    init();
    vector<int> a(n);
    vector<int> or_c(n), and_c(n);
    uint or01 = ask_or(1, 2);
    uint and01 = ask_and(1, 2);
    uint or12 = ask_or(2, 3);
    uint and12 = ask_and(2, 3);
    uint or20 = ask_or(3, 1);
    uint and20 = ask_and(3, 1);
    tie(a[0], a[1], a[2]) = find(or01, or12, or20, and01, and12, and20);
    rep(i, 3, n) {
        uint cur_or = ask_or(i, i + 1);
        uint cur_and = ask_and(i, i + 1);
        for (int bit = maxbit; bit--; ) {
            int pb = (a[i - 1] >> bit) & 1;
            int ob = (cur_or >> bit) & 1;
            int ab = (cur_and >> bit) & 1;
            rep(cur_bit, 0, 2) {
                if ((pb | cur_bit) == ob and (pb & cur_bit) == ab) {
                    a[i] = a[i] << 1 | cur_bit;
                    break;
                }
            }
        }
    }
    sort(all(a));
    answer(a[k - 1]);
}

int main() {
    precal();
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    solve();  
    // while (1) {  
        // solve();  
        // cout << "====" << endl;  
    // }  
    
    return 0;
}

// vim: foldmethod=marker