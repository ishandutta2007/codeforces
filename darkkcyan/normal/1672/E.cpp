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

struct solver {
    virtual int get_n() = 0;
    virtual int ask(int w) = 0;
    virtual void answer(int ans) = 0;

    void solve() {
        int n = get_n();
        int l = 1, r = n * 2001 - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (ask(mid) == 1) r = mid;
            else l = mid + 1;
        }
        
        int opt = l;
        rep(h, 2, n + 1) {
            int opt_w = l / h;
            int t = ask(opt_w);
            if (t == 0) continue;
            opt = min(opt, opt_w * t);
        }
        answer(opt);
    }
};

struct fixed_solver : public solver {
    vector<int> lens;
    int mx_len;
    int cnt_qr;
    int used_qr;
    fixed_solver(const vector<int> wl)
        : lens(wl), mx_len(*max_element(all(lens))), cnt_qr(sz(lens) + 30), used_qr(0) {
            cout << "TEST" << endl;
            cout << lens << endl;
        }

    virtual int get_n() override { 
        cout << ">> get n" << endl;
        cout << "<< " << sz(lens) << endl;
        return sz(lens);
    }
    
    int get(int w) {
        if (w < mx_len) {
            return 0;
        }
        int ans = 1;
        int cur_w = 0;
        for (auto l: lens) {
            if (cur_w + l + (!!cur_w) > w) {
                ++ans;
                cur_w = 0;
            }
            cur_w += l + !!cur_w;
        }
        return ans;
    }

    virtual int ask(int w) {
        cout << ">> ask " << w << ' '<< db(used_qr) << endl;
        assert(used_qr < cnt_qr);
        ++used_qr;
        int res = get(w);
        cout << "<< " << res << endl;
        return res;
    }
    
    virtual void answer(int ans) {
        cout << ">> answer: " << ans << endl;
        pair<int, int> opt;
        opt.first = opt.second = accumulate(all(lens), 0) + sz(lens) - 1;
        rep(w, 0, 2001 * sz(lens)) {
            int t = get(w);
            if (!t) continue;
            opt = min(opt, {w * t, w});
        }
        cout << "<< opt: " << opt << endl;
        assert(opt.first == ans);
    }
};

mt19937 rng;
int next(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}
struct random_test_solver : public fixed_solver {
    static vector<int> gen(int n) {
        vector<int> ans;
        rep(i, 0, n) ans.push_back(next(1, 10));
        return ans;
    }
    random_test_solver(int n = 2000): fixed_solver(gen(next(1, n))) {
    }
};

struct io_solver: public solver {
    virtual int get_n() override {
        int n;
        cin >> n;
        return n;
    }
    
    virtual int ask(int w) override {
        cout << "? " << w << endl;
        int ans;
        cin >> ans;
        return ans;
    }
    
    void answer(int ans) override {
        cout << "! " << ans << endl;
    }
};

int jalsol_orz() {
// #ifdef LOCAL
    // freopen("main.inp", "r", stdin);
    // freopen("main.out", "w", stdout);
    // freopen(".log", "w", stderr);
// #endif
    cin.tie(0)->sync_with_stdio(0);
    
    // fixed_ans_solver({5, 2, 7, 3, 5, 6}).solve();
    // while (true) {
        // random_test_solver(10).solve();
    // }
    io_solver().solve();

    return 0;
}