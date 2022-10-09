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

struct DS {
    multiset<int> values;
    int delta;
    
    DS(): delta(0) {}
    
    void inc(int x) {
        delta += x;
    }
    
    void add(int num) {
        num -= delta;
        values.insert(num);
    }
    
    void erase(int num) {
        values.erase(values.find(num - delta));
    }
    
    int get_min() const {
        if (!values.size()) return INT_MAX;
        return *values.begin()+ delta;
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        int n, k; cin >> n >> k;
        vector<int> a(k);
        vector<int> t(n);
        rep(i, 0, k) {
            cin >> a[i];
            --a[i];
        }
        
        rep(i, 0, k) {
            cin >> t[a[i]];
        }
        
        DS min_pref, min_suff;
        for (int i = n; i--; ) {
            if (t[i]) min_suff.add(t[i]);
            min_suff.inc(1);
        }
        
        rep(i, 0, n) {
            min_suff.inc(-1);
            int cur_ans = min(min_suff.get_min(), min_pref.get_min());
            cout << cur_ans << ' ';
            if (t[i]) {
                min_suff.erase(t[i]);
                min_pref.add(t[i]);
            }
            min_pref.inc(1);
        }
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker