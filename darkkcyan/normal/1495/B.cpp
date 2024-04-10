#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 2);
    rep1(i, n) cin >> a[i];
    a[0] = a[n + 1] = n + 10;
    
    struct Peak {
        int pos, left, right;
        
        int max_side() const {
            return max(left, right);
        }
    };
    vector<Peak> peaks;
    rep1(i, n) {
        if (a[i] < a[i - 1] or a[i] < a[i + 1]) {
            if (i != 1 and i != n) continue;
        }
        int left = 0, right = 0;
        for (int f = i - 1; f > 0; --f) {
            if (a[f] > a[f + 1]) break;
            ++left;
        }
        for (int f = i + 1; f <= n; ++f) {
            if (a[f] > a[f - 1]) break;
            ++right;
        }
        peaks.push_back({i, left, right});
    }
    
    sort(be(peaks), [&](const Peak& u, const Peak& v) {
            return u.max_side() > v.max_side();
            });
    
    while (len(peaks) and peaks.back().max_side() != peaks[0].max_side()) peaks.pop_back();
    if (len(peaks) != 1) {
        cout << 0;
        return 0;
    }
    
    auto cur = peaks[0];
    clog << db(cur.pos) << db(cur.left) << db(cur.right) << endl;
    if (cur.left == 0 or cur.right == 0) {
        cout << 0;
        return 0;
    }
    
    rep(_, 2) {
        int u = cur.left, v = cur.right;
        swap(cur.left, cur.right);
        if (v % 2 == 0) --v;
        if (u > v) continue;
        cout << 0;
        return 0;
    }
    cout << 1;
    
    return 0;
}

// vim: foldmethod=marker