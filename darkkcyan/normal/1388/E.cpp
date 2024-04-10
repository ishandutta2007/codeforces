#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

using ld = long double;
struct line {
    ld a, b;
    line() {}
    line(ld a_, ld b_): a(a_), b(b_) {}
    
    ld operator()(const ld& x)const { return a * x + b; }
};

ostream& operator<<(ostream& out, const line& u) {
    return out << "(" << u.a << ", " << u.b << ")";
}

bool operator<(const line& u, const line& v) { 
    if (u.a == v.a) return u.b < v.b;
    return u.a < v.a;
}

line operator-(const line& u, const line& v) {
    return line(u.a - v.a, u.b - v.b);
}

ld cross(const line& u, const line& v) {
    return u.a * v.b - u.b * v.a;
}

bool dec_mid_above(const line& u, const line& mid, const line& v) {
    return cross(u - mid, v - mid) < 0;
}

#define inc_mid_below dec_mid_above

const int maxn = 2020;
int n;
llong x1[maxn], x2[maxn], y[maxn];

const ld inf = 1e16;

struct fraction {
    llong a, b;
    fraction() : a(0), b(1) {}
    fraction(llong a_, llong b_) : a(a_), b(b_) {}
};

ostream& operator<<(ostream& out, const fraction& u) {
    return out << u.a << "/" << u.b;
}

bool operator<(const fraction& u, const fraction& v) {
    return u.a * v.b < v.a * u.b;
}

bool operator==(const fraction& u, const fraction& v) {
    return u.a * v.b == v.a * u.b;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> x1[i] >> x2[i] >> y[i];
    // if (n== 2000 and x1[0] ==  -457938 and x2[0] == -443295 and y[0] == 756601) special = true; 
    bool has_diff_y = false;
    cout.precision(10);
    rep(i, n) {
        if (y[i] != y[0]) {
            has_diff_y = true;
            break;
        }
    }
    if (!has_diff_y) {
        cout << fixed << *max_element(x2, x2 + n) - *min_element(x1, x1 + n) ;
        return 0;
    }
    
    vector<pair<fraction, int>> moments;
    rep(i, n) for (int f = i + 1; f < n; ++f) {
        if (y[i] == y[f]) continue;
        
        llong x1u = x1[i], x2u = x2[i];
        llong x1v = x1[f], x2v = x2[f];
        if (y[i] < y[f]) {
            swap(x1u, x1v);
            swap(x2u, x2v);
        }
        llong dy = abs(y[i] - y[f]);
        fraction a1(x1v - x2u, dy);
        fraction a2(x2v - x1u, dy);
        moments.emplace_back(a1, 1);
        moments.emplace_back(a2, -1);
    }
    
    
    vector<line> lefts, rights;
    
    rep(i, n) {
        lefts.emplace_back(y[i], x1[i]);
        rights.emplace_back(y[i], x2[i]);
    }
    
    sort(lefts.rbegin(), lefts.rend());
    sort(rights.begin(), rights.end());
    
    vector<line> qleft, qright;
    qleft.emplace_back(inf, inf * inf);
    qright.emplace_back(-inf, -inf * inf);
    
    
    rep(i, n) {
        while (len(qleft) > 1 and dec_mid_above(qleft[len(qleft) - 2], qleft.back(), lefts[i]))
            qleft.pop_back();
        qleft.push_back(lefts[i]);
    }
    
    rep(i, n) {
        while (len(qright) > 1 and inc_mid_below(qright[len(qright) - 2], qright.back(), rights[i])) 
            qright.pop_back();
        qright.push_back(rights[i]);
    }
    // if (special) {   
        // cout << len(moments) << ' ' << len(qleft) << ' ' << len(qright);    
        // return 0;   
    // }   
    
    
    int li = 1, ri = 1;
    auto cal_ans = [&](ld tan_a) {
        while (li < len(qleft) - 1 and qleft[li](tan_a) > qleft[li + 1](tan_a)) ++ li;
        while (ri < len(qright) - 1 and qright[ri](tan_a) < qright[ri + 1](tan_a)) ++ri;
        ld leftmost = qleft[li](tan_a);
        ld rightmost = qright[ri](tan_a);
        return rightmost - leftmost;
    };
    
    sort(moments.begin(), moments.end(), [](const auto& u, const auto& v) {
        if (u.first == v.first) return u.second < v.second;
        return u.first < v.first;
    });
    
    vector<tuple<fraction, int, int>> cummulate_moments;
    for (auto& [tan_a, mo]: moments) {
        if (!cummulate_moments.size() or !(get<0>(cummulate_moments.back()) == tan_a)) {
            cummulate_moments.emplace_back(tan_a, 0, 0);
        }
        ((mo > 0) ? get<1>(cummulate_moments.back()) : get<2>(cummulate_moments.back())) += mo;
    }
    
    deb(cummulate_moments);
    
    
    ld ans = inf;
    int prev_m = 0;
    for (auto [fr_tan_a, inc, dec]: cummulate_moments) {
        prev_m += dec;
        if (prev_m == 0) {
            ld tan_a = (ld) fr_tan_a.a / fr_tan_a.b;
            ans = min(ans, cal_ans(tan_a));
        }
        prev_m += inc;
    }
    cout << fixed << ans;

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker