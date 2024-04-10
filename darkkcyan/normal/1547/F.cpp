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

int l2(int num) {
    return 31 - __builtin_clz(num);
}

struct SQ {
    vector<pair<int, int>> head, tail;
    SQ(): head{{0, 0}}, tail{{0, 0}} {}
    
    void add(int x) {
        tail.push_back({__gcd(tail.back().first, x), x});
    }
    
    void rem() {
        if (sz(head) > 1) {
            head.pop_back();
            return ;
        }
        while (sz(tail) > 1) {
            int num = tail.back().second;
            tail.pop_back();
            head.push_back({__gcd(head.back().first, num), num});
        }
        head.pop_back();
    }
    
    int val() const {
        return __gcd(head.back().first, tail.back().first);
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
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        
        int l = 0, r = n;
        auto check = [&](int cycle) {
            SQ sq;
            rep(i, 0, cycle) {
                sq.add(a[i]);
            }
            
            int v = sq.val();
            rep(i, 1, n) {
                sq.rem();
                int f = (i + cycle - 1) % n;
                sq.add(a[f]);
                if (sq.val() != v) return false;
            }
            return true;
        };
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l - 1 << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker