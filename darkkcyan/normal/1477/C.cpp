#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

struct point {
    int id;
    llong xx, yy;
    point() = default;
};

bool operator<(const point& u, const point& v) {
    if (u.xx == v.xx) return u.yy < v.yy;
    return u.xx < v.xx;
}

bool operator==(const point& u, const point& v) {
    return u.xx == v.xx and u.yy == v.yy;
}

template<class T>
int sign(const T& u) { return u < 0 ? -1 : u > 0; }
llong scross(const point& u, const point& v) {
    return sign(u.xx * v.yy - u.yy * v.xx);
}

point operator-(const point& u, const point& v) {
    return {-1, u.xx - v.xx, u.yy - v.yy};
}

template<class Iter>
vector<point> half_hull(Iter beg, Iter end) {
    vector<point> ans;
    ans.push_back(*beg);
    for (auto it = next(beg); it != end; ++it) {
        while (len(ans) > 2 and scross(ans.back() - *it, ans.rbegin()[1] - *it) < 0) ans.pop_back();
        ans.push_back(*it);
    }
    
    return ans;
}

vector<point> hull(vector<point> poly) {
    auto upper = half_hull(poly.begin(), poly.end());
    auto lower = half_hull(poly.rbegin(), poly.rend());
    upper.pop_back();
    lower.pop_back();
    upper.insert(upper.end(), lower.begin(), lower.end());
    return upper;
}

llong sqr(llong x) { return x * x; }

llong dist2(const point& u, const point& v) {
    return sqr(u.xx - v.xx) + sqr(u.yy - v.yy);
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<point> poly(n);
    rep(i, n) {
        cin >> poly[i].xx >> poly[i].yy;
        poly[i].id = i;
    }
    // sort(poly.begin(), poly.end()); 
    auto start = min_element(poly.begin(), poly.end());
    vector<point> ans;
    ans.push_back(*start);
    poly.erase(start);
    
    while (len(poly)) {
        // auto h = hull(poly); 
        auto furthest = max_element(poly.begin(), poly.end(), [&](const point& u, const point& v) {
                return dist2(u, ans.back()) < dist2(v, ans.back());
                });
        ans.push_back(*furthest);
        poly.erase(furthest);
    }
    for (auto it: ans) cout << it.id + 1 << ' ';
    
    return 0;
}

// vim: foldmethod=marker