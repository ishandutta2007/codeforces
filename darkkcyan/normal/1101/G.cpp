#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

using uint = unsigned int ;
constexpr int maxbit = 32;

struct Basis {
    array<uint, maxbit> basis;
    Basis() {
        basis.fill(0);
    }
    
    void add(uint num) {
        for (int bit = maxbit; bit--; ) {
            if ((num >> bit) & 1) {
                if (!basis[bit]) {
                    basis[bit] = num;
                    return ;
                }
                num ^= basis[bit];
            }
        }
    }
    
    bool can_make(uint num) const {
        for (int bit = maxbit; num and bit--; ) {
            if ((num >> bit) & 1) num ^= basis[bit];
        }
        return num == 0;
    }
    
    int bas_len() const {
        int ans = 0;
        rep(i, 0, maxbit) ans += !! basis[i];
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    uint pref_xor = 0;
    Basis bas;
    rep(i, 0, n) {
        uint x; cin >> x;
        pref_xor ^= x;
        bas.add(pref_xor);
    }
    if (pref_xor == 0) {
        cout << "-1";
    } else {
        cout << bas.bas_len();
    }
    
    
    return 0;
}

// vim: foldmethod=marker