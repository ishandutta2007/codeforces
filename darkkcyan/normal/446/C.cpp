// #pragma GCC optimize ("Ofast")
#define NDEBUG
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

const int maxn = 301010;
#define defop(type, op) \
    inline friend type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 

template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x(int(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x-= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 9>;
struct Mat {
    vector<vector<mint>> data;
    Mat() = default;
    Mat(size_t n, size_t m): data(n, vector<mint>(m)) {}
    Mat(const vector<vector<mint>>& d): data(d) {}
    vector<mint>& operator[](size_t row) { return data[row]; }
    const vector<mint>& operator[](size_t row) const { return data[row]; }
    size_t nrow() const { return data.size(); }
    size_t ncol() const { return data[0].size(); }
    static Mat iden(size_t n) {
        Mat res(n, n);
        while (n--) res[n][n] = 1;
        return res;
    }
    friend Mat operator*(const Mat& u, const Mat& v) {
        assert(u.ncol() == v.nrow());
        Mat res(u.nrow(), v.ncol());
        rep(i, 0, (int)u.nrow())
        rep(k, 0, (int)u.ncol()) {
            auto x = u[i][k];
            rep(f, 0, (int)v.ncol())
                res[i][f] += x * v[k][f];
        }
        return res;
    }
    Mat pow(ll exp) const {
        assert(nrow() == ncol());
        Mat ans = iden(nrow()), base = *this;
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
    defop(Mat, +) {
        assert(nrow() == o.nrow());
        assert(ncol() == o.ncol());
        rep(i, 0, nrow()) rep(f, 0, ncol())
            data[i][f] += o[i][f];
        return *this;
    }
};

vector<Mat> coef;
vector<array<mint, 2>> base;
void precal() {
    coef.reserve(maxn);
    coef.push_back(Mat::iden(3));
    coef.emplace_back(Mat({{1, 1, 0}, {1, 0, 0}, {1, 0, 1}}));
    while (sz(coef) < maxn) {
        coef.push_back(coef.back() * coef[1]);
    }
    
    base.push_back({1, 0});
    while (sz(base) < maxn)  {
        // base.push_back(coef[1] * base.back());
        array<mint, 2> res = {
            base.back()[0] + base.back()[1],
            base.back()[0]
        };
        base.emplace_back(move(res));
    }
}

struct Segtree {
    int n;
    vector<mint> data;
    vector<array<mint, 2>> lazy;
    Segtree(int len): n(len), data(n * 4), lazy(n * 4, {0, 0}) {}
    
    void push(int i, int l, int r) {
        if (lazy[i][0].x == 0 and lazy[i][1].x == 0) return ;
        // data[i] += (coef[r - l] * lazy[i])[2][0];
        // data[i] += cal_mul_cell(coef[r - l], lazy[i], 2, 0);
        data[i] += coef[r - l][2][0] * lazy[i][0] + coef[r - l][2][1] * lazy[i][1];
        clog << db(i) << db(l) << db(r) << db(lazy[i]) << db(data[i]) << endl;
        if (r - l > 1) {
            int mid = (l + r) / 2;
            clog << db(mid) << db(coef[mid - l].data) << endl;
            lazy[2 * i][0] += lazy[i][0];
            lazy[2 * i][1] += lazy[i][1];
            lazy[2 * i + 1][0] += lazy[i][0] * coef[mid - l][0][0] + lazy[i][1] * coef[mid - l][0][1];
            lazy[2 * i + 1][1] += lazy[i][0] * coef[mid - l][1][0] + lazy[i][1] * coef[mid - l][1][1];
            clog << db(lazy[2 * i]) << db(lazy[2 * i + 1]) << endl;
        }
        lazy[i] = {0, 0};
    }
    
    void upd(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            clog << db(i) << db(l) << db(r) << db(base[l - from]) << endl;
            lazy[i][0] += base[l - from][0];
            lazy[i][1] += base[l - from][1];
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd(from, to, 2 * i, l, mid);
        upd(from, to, 2 * i + 1, mid, r);
        data[i] = data[2 * i] + data[2 * i + 1];
    }
    
    mint get(int from, int to, int i, int l, int  r) {
        push(i, l, r);
        if (from >= r or l >= to) return 0;
        if (from <= l and r <= to) return data[i];
        int mid = (l + r) / 2;
        return get(from, to, 2 * i, l, mid) + get(from, to, 2 * i + 1, mid, r);
    }
    
    void upd(int from, int to) {
        upd(from, to, 1, 0, n);
    }
    
    mint get(int from, int to) {
        return get(from, to, 1, 0, n);
    }
};

// #define gentest
int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
#ifdef gentest
    constexpr bool gt = true;
#else
    constexpr bool gt = false;
#endif
    rep(i, 0, 10) {
        clog << db(i) << db(base[i]) << endl;
        clog << db(coef[i].data) << endl;
    }
    
    int n, q;
    if constexpr (gt) {
        n = 300000;
        q = 300000;
    } else {
        cin >> n >> q;
    }
    vector<mint> a(n + 1);
    mt19937 rng;
    rep(i, 1, n + 1) {
        int x;
        if constexpr(gt) {
            x = (int)(rng() % 1000000000 + 1);
        } else {
            cin >> x;
        }
        a[i] = x + a[i - 1];
    }
    Segtree st(n);
    while (q--) {
        int t, l, r;
        if constexpr (gt) {
            t = int(rng() & 1) + 1;
            l = (int)(rng() % n) + 1;
            r = (int)(rng() % n) + 1;
            if (l > r) swap(l, r);
        } else {
            cin >> t >> l >> r;
        }
        --l;
        if (t == 1) {
            st.upd(l, r);
        } else {
            cout << st.get(l, r) + a[r] - a[l] << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker