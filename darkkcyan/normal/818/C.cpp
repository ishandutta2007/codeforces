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

struct Sofa {
    int x1, y1, x2, y2;
    void normalize() {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
    }
    
    bool is_hor() const {
        return y1 == y2;
    }
    
    bool is_ver() const {
        return x1 == x2;
    }
};
const int maxn = 201010;
int n, m, d;
int cnt_l, cnt_r, cnt_t, cnt_b;

Sofa s[maxn];
int sum_l[maxn], sum_r[maxn], sum_t[maxn], sum_b[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> d >> n >> m;
    rep(i, 0, d) {
        cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
        s[i].normalize();
        sum_l[s[i].x1]++;
        sum_r[s[i].x2]++;
        sum_t[s[i].y1]++;
        sum_b[s[i].y2]++;
    }
    cin >> cnt_l >> cnt_r >> cnt_t >> cnt_b; 
    
    rep(i, 0, n) sum_l[i + 1] += sum_l[i];
    rep(i, 0, m) sum_t[i + 1] += sum_t[i];
    for (int i = n + 1; i--; ) sum_r[i] += sum_r[i + 1];
    for (int i = m + 1; i--; ) sum_b[i] += sum_b[i + 1];
    
    rep(i, 0, d) {
        int cur_l = sum_l[s[i].x2 - 1];
        int cur_r = sum_r[s[i].x1 + 1];
        int cur_t = sum_t[s[i].y2 - 1];
        int cur_b = sum_b[s[i].y1 + 1];
        if (s[i].is_ver()) {
            --cur_t;
            --cur_b;
        }
        if (s[i].is_hor()) {
            --cur_l;
            --cur_r;
        }
        clog << db(i) << db(cur_l) << db(cur_r) << db(cur_t) << db(cur_b) << endl;
        if (cnt_l == cur_l and cnt_r == cur_r and cnt_t == cur_t and cnt_b == cur_b) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    
    return 0;
}

// vim: foldmethod=marker