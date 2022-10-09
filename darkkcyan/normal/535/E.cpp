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

__int128 abs(__int128 x) {
    if (x < 0) return -x;
    return x;
}

#define def_op(type, op) \
    friend inline type operator op (type u, const type& v) { return u op##= v; } \
    type& operator op##= (const type& o) 
struct Frac {
    __int128 a, b;
    
    Frac(): a(0), b(1) {}
    Frac(ll x): a(x), b(1) {}
    Frac(ll u, ll v): a(u), b(v) {
        norm();
    }
    
    Frac& norm() {
        auto g = abs(__gcd(a, b));
        a /= g;
        b /= g;
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
        return *this;
    }
    
    def_op(Frac, +) {
        a = a * o.b + o.a * b;
        b *= o.b;
        return norm();
    }
    
    def_op(Frac, -) {
        a = a * o.b - o.a * b;
        b *= o.b;
        return norm();
    }
    
    def_op(Frac, *) {
        a *= o.a;
        b *= o.b;
        return norm();
    }
    
    def_op(Frac, /) {
        a *= o.b;
        b *= o.a;
        return norm();
    }
    
    friend bool operator ==(const Frac& u, const Frac& v) {
        return u.a * v.b == u.b * v.a;
    }
    
    friend ostream& operator<<(ostream& out, const Frac& u) {
        return out << (ll)u.a << "/" << (ll)u.b;
    }
};

template<class T>
int sign(const T& u) {
    return u < 0 ? -1 : u > 0;
}

int sign(const Frac& u) {
    return sign(u.a) * sign(u.b);
}


int cmp_frac(const Frac& u, const Frac& v) {
    int su = sign(u), sv = sign(v);
    if (su != sv) return su - sv;
    if (su == 0) return 0;
    int cr = sign(abs(u.a * v.b) - abs(u.b * v.a));
    if (su < 0) cr *= -1;
    return cr;
}

bool operator<(const Frac& u, const Frac& v) {
    return cmp_frac(u, v) < 0;
}

template<class T>
struct Line {
    T a, b;
    Line(): a(1), b(0) {}
    Line(const T& a_, const T& b_): a(a_), b(b_) {}
    
    Line dual() const {
        return {a, 0 - b};
    }
    
    T operator()(const T& u) {
        return a * u + b;
    }
    
    def_op(Line, -) {
        a -= o.a;
        b -= o.b;
        return *this;
    }
    
    friend ostream& operator<<(ostream& out, const Line& u) {
        return out << "(" << u.a << ", " << u.b << ")";
    }
    
    friend bool operator<(const Line& u, const Line& v) {
        int t = cmp_frac(u.a, v.a);
        if (t == 0) {
            return u.b < v.b;
        }
        return t < 0;
    }
};

template<class T>
using Point = Line<T>;

template<class T>
int scross(const Point<T>& u, const Point<T>& v) {
    auto t = u.a * v.b - u.b * v.a;
    // clog << "cross " << db(u) << db(v) << db(t) << endl; 
    return sign(t);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; 
    cin >> n;
    map<Line<Frac>, vector<int>> ids;
    Frac max_x;
    rep(i, 0, n) {
        ll u, v;
        cin >> u >> v;
        Frac x(1, u), y(-1, v);
        ids[Line(x, y)].push_back(i);
        max_x = max(max_x, x);
    }
    vector<Line<Frac>> lines;
    
    for (auto& [l, i]: ids) {
        while (sz(lines) and lines.back().a == l.a and lines.back().b < l.b) {
            lines.pop_back();
        }
        lines.push_back(l);
    }
    
    sort(all(lines), [&](const auto& u, const auto& v) {
            ll t = cmp_frac(u.a, v.a);
            if (t == 0) {
                t = cmp_frac(u.b, v.b);
                if (u.a == max_x) return t > 0;
                return t < 0;
            }
            return t < 0;
            });
    
    vector<Line<Frac>> hull;
    for (auto i: lines) {
        clog << i << endl;
        while (sz(hull) >= 2 and scross(hull.back() - i, hull.end()[-2] - i) < 0) {
            hull.pop_back();
        }
        hull.push_back(i);
    }
    
    Frac small(1, 100000LL);
    while (sz(hull) > 1 and cmp_frac(hull.back().dual()(small), hull.end()[-2].dual()(small)) > 0) {
        hull.pop_back();
    }
    
    vector<int> ans;
    for (auto h: hull) {
        for (auto i: ids[h]) ans.push_back(i);
    }
    sort(all(ans));
    for (auto i: ans) cout << i + 1 << ' ';
    
    return 0;
}

// vim: foldmethod=marker