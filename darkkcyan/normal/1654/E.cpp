#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main

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
    if (0)                                                                     \
    cerr
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
    if constexpr (i == tuple_size<T>::value)
        return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

const int maxn = 101010;
const int thres = 320;
const int max_val = thres * maxn;

int n;
int a[maxn];

map<int, int> big_dp[maxn];


int solve_one_dir() {
    int ans = 1;
    rep(d, 0, thres) {
        vector<int> vals;
        rep(i, 0, n) {
            int shift = a[i] - d * i;
            vals.push_back(shift);
        }
        sort(all(vals));
        for (int l = 0, r = 0; l < n; l = r) {
            while (r < n and vals[r] == vals[l]) ++r;
            ans = max(ans, r - l);
        }
    }

    rep(i, 0, n + 1) { big_dp[i].clear(); }

    rep(i, 0, n) {
        for (int f = i - 1, c = 1; c < thres + 10 and f >= 0; ++c, --f) {
            if (a[f] > a[i])
                continue;
            int diff = a[i] - a[f];
            if (diff < 0)
                continue;
            if (diff % c > 0)
                continue;
            auto &cur_dp = big_dp[i][diff / c];
            int prev_dp = 1;
            if (big_dp[f].count(diff / c))
                prev_dp = big_dp[f][diff / c];
            cur_dp = max(cur_dp, prev_dp + 1);
            ans = max(cur_dp, ans);
        }
    }
    return ans;
}

int solve() {
    int ans = solve_one_dir();
    reverse(a, a + n);
    ans = max(ans, solve_one_dir());
    clog << db(ans) << endl;
    return n - ans;
}

int brute() {
    int ans = 0;
    rep(mask, 0, (1 << n)) {
        vector<pair<int, int>> val;
        rep(i, 0, n) if ((mask >> i) & 1) val.push_back({a[i], i});
        if (sz(val) <= 2) {
            ans = max(ans, sz(val));
            continue;
        }
        if ((val[1].first - val[0].first) % (val[1].second - val[0].second)) {
            continue;
        }

        int d = (val[1].first - val[0].first) / (val[1].second - val[0].second);
        bool ok = true;
        rep(i, 1, sz(val)) {
            if (val[i].first - d * (val[i].second - val[i - 1].second) !=
                val[i - 1].first) {
                ok = false;
                break;
            }
        }
        if (ok)
            ans = max(ans, __builtin_popcount(mask));
    }
    clog << db(ans) << endl;
    return n - ans;
}

mt19937 rng;
int rand(int l, int r) { return l + (int)(rng() % (r - l + 1)); }
void check() {
    n = rand(1, 20);
    rep(i, 0, n) a[i] = rand(1, 100000);
    auto ans = solve();
    auto exp = brute();
    cout << n << ' ' << db(ans) << db(exp) << endl;
    if (ans == exp) {
        cout << "OK " << endl;
        return;
    }
    cout << "NO" << endl;
    cout << n << endl;
    rep(i, 0, n) cout << a[i] << ' ';
    cout << endl;
    exit(0);
}

int jalsol_orz() {
#ifdef LOCAL
    // while (1) check();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    cout << solve() << '\n';
#ifdef LOCAL
    cout << db(brute()) << endl;
#endif

    return 0;
}