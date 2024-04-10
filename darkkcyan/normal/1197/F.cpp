#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
// DEBUGING TEMPLETE
// ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "[" #val " = " << (val) << "] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        clog << "{" << endl;
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        clog << "}" << endl;
    }
};
#else
#define clog                                                                   \
    if (0) cerr
#define DB(...)
#endif

template <class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type
operator<<(ostream &out, const Con &con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template <size_t i, class T>
ostream &print_tuple_utils(ostream &out, const T &tup) {
    if constexpr (i == tuple_size<T>::value) return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

#define defop(type, op)                                                        \
    friend inline type operator op(type u, const type &v) {                    \
        return u op## = v;                                                     \
    }                                                                          \
    type &operator op##=(const type &o)

template <int mod> struct modint {
    int x;
    modint(int x_ = 0) : x(x_) {}
    modint(ll x_) : x(int(x_ % mod)) {}

    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) { return *this = modint(1ll * x * o.x); }

    friend print_op(modint) { return out << u.x; }
};

using mint = modint<998'244'353>;

template <int n, int m> struct matrix {
    mint data[n][m];

    mint *operator[](int id) { return data[id]; }
    const mint *operator[](int id) const { return data[id]; }
    
    friend print_op(matrix) {
        out << "[";
        rep(i, 0, n) {
            out << vector<mint>(u.data[i], u.data[i] + m) << "; ";
        }
        return out << "]";
    }
};

template <int x, int y, int z>
inline matrix<x, z> operator*(const matrix<x, y> &u, const matrix<y, z> &v) {
    matrix<x, z> ans;
    rep(i, 0, x) rep(f, 0, z) rep(g, 0, y) { ans[i][f] += u[i][g] * v[g][f]; }
    return ans;
}

template <int n, int m>
matrix<n, m> operator+(const matrix<n, m> &u, const matrix<n, m> &v) {
    matrix<n, m> ans;
    rep(i, 0, n) rep(f, 0, m) ans[i][f] = u[i][f] + v[i][f];
    return ans;
}

template <int n> static matrix<n, n> iden() {
    matrix<n, n> ans{};
    for (int i = n; i--;) ans[i][i] = 1;
    return ans;
}

int mex(const vector<int> &num) {
    static int timer = 0;
    static int mark[6]{};

    ++timer;
    for (auto i : num) mark[i] = timer;
    int ans = 0;
    while (mark[ans] == timer) ++ans;
    return ans;
}

const int max_single_state = 4;
const int max_state = max_single_state * max_single_state * max_single_state;

struct state {
    int s;
    state(int s_) : s(s_) {}
    state(int x, int y, int z) : s(z << 4 | y << 2 | x) {}

    operator int() const { return s; }

    int operator[](int idx) const { return (s >> idx >> idx) & 3; }
};

struct strip {
    int len;
    vector<pair<int, int>> existed;
};

int n;
vector<strip> strips;
int fmat[3][3];

matrix<max_state, max_state> cal_coef(int cur_col) {
    matrix<max_state, max_state> ans{};

    rep(x, 0, max_single_state) rep(y, 0, max_single_state)
        rep(z, 0, max_single_state) {
        vector<int> reachable;
        if (fmat[cur_col][0]) reachable.push_back(x);
        if (fmat[cur_col][1]) reachable.push_back(y);
        if (fmat[cur_col][2]) reachable.push_back(z);

        int nx = mex(reachable);
        ans[state(nx, x, y)][state(x, y, z)] += 1;
    }

    return ans;
}

const int maxlg = 40;

matrix<max_state, max_state> base_coef[3], base_coef_all;
matrix<max_state, max_state> pw[maxlg];

void precal() {
    rep(i, 0, 3) base_coef[i] = cal_coef(i);
    base_coef_all = base_coef[0] + base_coef[1] + base_coef[2];
    rep(i, 0, 3) {
        clog << db(i) << db(base_coef[i]) << endl;
    }
    clog << db(base_coef_all) << endl;

    pw[0] = base_coef_all;
    rep(i, 0, maxlg - 1) pw[i + 1] = pw[i] * pw[i];
}

vector<mint> cal_grundy(strip s) {
    DB();
    matrix<max_state, 1> cur{};
    cur[state(3, 3, 3)][0] = 1;
    int cur_pos = 0;
    ranges::sort(s.existed);

    auto upd = [&](int d) {
        assert(d >= 0);
        for (int i = 0; d > 0; d >>= 1, ++i) {
            if (d & 1) cur = pw[i] * cur;
        }
    };

    for (auto [p, c] : s.existed) {
        DB();
        int d = p - cur_pos - 1;
        upd(d);
        cur = base_coef[c] * cur;
        cur_pos = p;
        clog << db(p) << db(c) << endl;
        rep(x, 0, max_single_state) rep(y, 0, max_single_state) rep(z, 0, max_single_state) {
            if (cur[state(x, y, z)][0].x) {
                clog << db(x) << db(y) << db(z) << db(cur[state(x, y, z)][0]) << endl;
            }
        }
    }
    upd(s.len - cur_pos);
    {
        DB();
        rep(x, 0, max_single_state) rep(y, 0, max_single_state) rep(z, 0, max_single_state) {
            if (cur[state(x, y, z)][0].x) {
                clog << db(x) << db(y) << db(z) << db(cur[state(x, y, z)][0]) << endl;
            }
        }
    }

    vector<mint> res(max_single_state);

    rep(x, 0, max_single_state) rep(y, 0, max_single_state)
        rep(z, 0, max_single_state) {
        res[x] += cur[state(x, y, z)][0];
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    strips.resize(n);
    for (auto &i : strips) cin >> i.len;

    int m;
    cin >> m;
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --c;
        strips[x].existed.emplace_back(y, c);
    }

    rep(i, 0, 3) rep(f, 0, 3) cin >> fmat[i][f];
    precal();

    vector<mint> cur_dp(max_single_state);

    cur_dp[0] = 1;
    for (const auto &s : strips) {
        DB();
        auto g = cal_grundy(s);
        vector<mint> new_dp(max_single_state);
        rep(prv, 0, max_single_state) rep(cur, 0, max_single_state) {
            new_dp[prv ^ cur] += cur_dp[prv] * g[cur];
        }
        cur_dp = new_dp;
        clog << db(new_dp) << endl;
        clog << db(g) << endl;
    }

    cout << cur_dp[0];

    return 0;
}