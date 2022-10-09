#include <bits/stdc++.h>
using namespace std;
 
// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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
 
struct point {
    int x, y;
};
bool operator<(const point& u, const point& v) {
    return u.x == v.x ? u.y < v.y : u.x < v.x;
}

point operator+(const point& u, const point& v) {
    return {u.x + v.x, u.y + v.y};
}

point dir[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

const int maxn = 201010;
int n;
point a[maxn];


int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n) cin >> a[i].x >> a[i].y;
    
    set<point> has;
    rep(i, 0, n) {
        has.insert(a[i]);
    }
    
    map<point, point> root;
    queue<point> qu;
    rep(i, 0, n) {
        rep(d, 0, 4) {
            auto t = a[i] + dir[d];
            if (!has.count(t)) {
                root[t] = t;
                qu.push(t);
                clog << t.x << ' ' << t.y << endl;
            }
        }
    }
    
    for (; qu.size(); qu.pop()) {
        auto u = qu.front();
        auto ru = root[u];
        rep(d, 0, 4) {
            auto v = u + dir[d];
            if (root.count(v)) continue;
            if (!has.count(v)) continue;
            root[v] = ru;
            qu.push(v);
        }
    }
    rep(i, 0, n) {
        auto ans = root[a[i]];
        cout << ans.x << ' ' << ans.y << '\n';
    }
    
    return 0;
}