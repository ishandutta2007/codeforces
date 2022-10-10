#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-6;
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

template<class Num>
int sign(Num x) {
    return x < 0 ? -1 : x > 0;
}

const ld pi = acos(-1);
const ld pi2 = pi * 2;
const ld inf = 1e15;

struct point {
    ld x, y;
    ld l2() const {
        return x * x + y * y;
    }
    
    ld length() const {
        return sqrtl(l2());
    }
    
    point fix_length(ld len = 1) const {
        auto l = length();
        return {x * len / l, y * len / l};
    }
    
    ld angle() const {
        return atan2(y, x);
    }
    point operator-() {
        return {-x, -y};
    }
    friend print_op(point) {
        return out << "(" << fixed << setprecision(10) << u.x << ", " << fixed << setprecision(10) << u.y << ")";
    }
};

bool operator<(const point& u, const point& v) {
    if (u.x == v.x) return u.y < v.y;
    return u.x < v.x;
}

point operator+(const point& u, const point& v) {
    return {u.x + v.x, u.y + v.y};
}
point operator-(const point& u, const point& v) {
    return {u.x - v.x, u.y - v.y};
}
point operator*(const point& u, ld scalar) {
    return {u.x * scalar, u.y * scalar};
}

ld cross(const point& u, const point& v) {
    return u.x * v.y - u.y * v.x;
}

ld dot(const point& u, const point& v) {
    return u.x * v.x + u.y * v.y;
}
bool operator==(const point& u, const point& v) {
    return abs(u.x - v.x) < eps and abs(u.y - v.y) < eps;
}



struct seg {
    point a, b;
    
    bool contains(const point& u) const {
        auto au = u - a;
        auto bu = u - b;
        return dot(au, bu) < eps and abs(cross(au, bu)) < eps;
    }
    
    friend print_op(seg) {
        return out << "[" << u.a << ", " << u.b << "]";
    }
};

point line_intersect(const seg& u, const seg& v) {
    auto udir = u.b - u.a;
    auto vdir = v.b - v.a;
    // solving equation u.a + t1 * udir == v.a + t2 * vdir
    // <=> t1 * udir.x - t2 * vdir.x == v.a.x - u.a.x
    // and t1 * udir.y - t2 * vdir.y == v.a.y - u.a.y
    ld d = cross(udir, -vdir);
    if (abs(d) <= eps) return {inf, inf};
    auto t = v.a - u.a;
    ld dx = cross(t, -vdir);
    auto t1 = dx / d;
    return u.a + udir * t1;
}

using polygon = vector<point>;

const int maxn = 1010;

bool in_polygon(const polygon& poly, const point& p) {
    ld sum_ang = 0;
    auto prv_ang = (poly.back() - p).angle();
    auto prv = poly.back();
    for (auto& u: poly) {
        if (seg{prv, u}.contains(p)) return true;
        auto cur_ang = (u - p).angle();
        sum_ang += cur_ang - prv_ang;
        prv_ang = cur_ang;
        prv = u;
    }
    return abs(sum_ang) > eps;
}

ld query(polygon poly, const seg& s) {
    const ld big = 1e9;  // because all coor are not greater then 1e5
    DB();
    auto root = (s.a - s.b).fix_length(big) + s.b;
    
    clog << db(s) << endl;
    clog << db(root) << endl;
    ld ans = 0;
    auto prv = poly.back();
    vector<pair<point, int>> inter;
    for (auto& u: poly) {
        seg cur_seg{u, prv};
        auto t = line_intersect(s, cur_seg);
        if (t.x >= inf) {
            if (abs(cross(s.a - u, s.b - u)) < eps) {
                bool u_closer = dot(prv - u, root - u) < 0;
                if (u_closer) {
                    inter.emplace_back(u, -1);
                    inter.emplace_back(prv, 1);
                } else {
                    inter.emplace_back(prv, -1);
                    inter.emplace_back(u, 1);
                }
            }
        } else if (cur_seg.contains(t)) {
            inter.emplace_back(t, sign(cross(root - prv, u - prv)));
        }
        prv= u;
        clog << db(u) << db(prv) << db(t) << db(ans) << endl;
    }
    clog << db(inter) << endl;
    sort(all(inter));
    // rotate(inter.begin(), min_element(all(inter)), inter.end());
    inter.erase(unique(all(inter)), inter.end());
    while (sz(inter) and inter.back() == inter[0]) inter.pop_back();
    cerr.precision(10);
    clog << db(inter) << endl;
    for (auto [u, sgn]: inter) {
        ans += (u - root).length() * sgn;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    polygon poly(n);
    for (auto& p: poly) {
        cin >> p.x >> p.y;
        // p.x *= 100;
        // p.y *= 100;
    }
    rotate(poly.begin(), min_element(all(poly)), poly.end());
    if (cross(poly.back() - poly[0], poly[1] - poly[0]) < 0) {
        reverse(all(poly));
    }
    
    while (m--) {
        point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        // a.x *= 100;
        // a.y *= 100;
        // b.x *= 100;
        // b.y *= 100;
        auto ans = query(poly, {a, b});
        cout << fixed << setprecision(10) << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker