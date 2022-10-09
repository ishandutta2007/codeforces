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

struct Point {
    ld x, y;
    ld length2 () const {
        return x * x  + y * y;
    }
    ld length() const {
        return sqrtl(length2());
    }
};

Point operator-(const Point& u, const Point& v) {
    return {u.x - v.x, u.y - v.y};
}
ld cross(const Point& u, const Point& v) {
    return u.x * v.y - u.y * v.x;
}

ld sign_dist(const Point& from, const Point& to1, const Point& to2) {
    ld area = cross(to1 - from, to2 - from);
    return area / (to2 - to1).length();
}

const int iter = 100;
ld solve(ld y1, ld y2, ld yw, ld xb, ld yb, ld r) {
    ld left_range;
    {
        ld lo = 0, hi = xb;
        rep(it, 0, iter) {
            ld mid = (lo + hi) / 2;
            if (sign_dist({0, y2}, {2 * mid - xb, yb}, {mid, yw - r}) > r + eps) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        left_range = hi;
    }
    clog << db(left_range) << endl;
    ld reflect_x = 2 * left_range - xb;
    ld touch_y = yw - r - left_range * (yw - r - yb) / (left_range - reflect_x);
    clog << db(touch_y) << endl;
    if (touch_y - r < y1) return -1;
    return left_range;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    ld y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    auto ans = solve(y1, y2, yw, xb, yb, r);
    if (ans < 0) cout << -1;
    else cout << fixed << setprecision(10) << ans;
    
    return 0;
}

// vim: foldmethod=marker