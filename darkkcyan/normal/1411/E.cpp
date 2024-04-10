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

const int maxch = 26;
const int maxbit = 60;
int n;
ll t;
string s;
ll cnt[maxbit];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    cin >> s;
    rep(i, 0, n - 2) cnt[s[i] - 'a'] ++;
    
    t -= 1ll << (s[n - 1] - 'a');
    t += 1ll << (s[n - 2] - 'a');
    
    rep(i, 0, maxch) {
        t += cnt[i] << i;
    }
    
    clog << db(t) << endl;
    if (t < 0 or (t & 1)) {
        cout << "No";
        return 0;
    }
    
    for (int bit = maxbit; bit--; ) {
        if (!((t >> bit) & 1)) continue;
        ll get[maxbit];
        memset(get, 0, sizeof(get));
        
        ll need = 1;
        for (int i = bit - 1; i >= 0 and need; --i) {
            ll can_get = min(cnt[i], need);
            get[i] = can_get;
            need -= can_get;
            need <<= 1;
        }
        
        if (need) {
            cout << "No";
            return 0;
        }
        for (int i = bit - 1; i >= 0; --i) cnt[i] -= get[i];
    }
    cout << "Yes\n";
    
    return 0;
}

// vim: foldmethod=marker