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

bool has_bit(int num, int bit) { return (num >> bit) & 1; }

const int max_bit = 30;
const int inf = INT_MAX;
struct DS {
    int cur_min_val;
    array<int, max_bit> first_zero;
    array<int, max_bit> cnt_zero;
    int prv_val;
    DS() {
        cur_min_val = inf;
        first_zero.fill(-1);
        cnt_zero.fill(0);
        prv_val = -1;
    }
    
    void add(int num) {
        clog << "add " << db(num) << db(bitset<5>(num)) << endl;
        add_(num);
        clog << db(first_zero) << endl;
        clog << db(cnt_zero) << endl;
    }

    void add_(int num) {
        if (prv_val != -1) {
            cur_min_val = min(cur_min_val, num | prv_val);
        }
        prv_val = num;
        for (int i = max_bit; i--;) {
            int bit = has_bit(num, i);
            if (first_zero[i] != -1) {
                cur_min_val = min(cur_min_val, num | first_zero[i]);
            }
            if (bit) {
                if (cnt_zero[i] > 1) {
                    return;
                }
            } else {
                if (cnt_zero[i] > 1)
                    continue;
                if (cnt_zero[i] == 0) {
                    cnt_zero[i]++;
                    first_zero[i] = num;
                    continue;
                } else {
                    cnt_zero[i]++;
                    int u = num;
                    int v = first_zero[i];
                    cur_min_val = min(cur_min_val, u | v);
                    for (int f = i; f--;) {
                        cnt_zero[f] = 0;
                        if (!has_bit(u, f)) {
                            first_zero[f] = u;
                            ++cnt_zero[f];
                        }
                        if (!has_bit(v, f)) {
                            first_zero[f] = v;
                            ++cnt_zero[f];
                        }
                    }
                    return;
                }
            }
        }
    }
};


static const int blk_size = 300;
const int maxn = 101010;
struct Query {
    int l, r, id;
};
int n, q;
int a[maxn];
vector<Query> qr;

vector<int> solve() {
    vector<vector<Query>> blks((n + blk_size - 1) / blk_size);
    rep(i, 0, q) { blks[qr[i].l / blk_size].push_back(qr[i]); }

    vector<int> ans(q);
    rep(bid, 0, sz(blks)) {
        DB();
        clog << db(bid) << endl;
        auto &cur_blk = blks[bid];
        sort(all(cur_blk),
             [](const Query &u, const Query &v) { return u.r < v.r; });
        int cur_r = (bid + 1) * blk_size;
        DS ds;
        for (auto &[l, r, id] : cur_blk) {
            DB();
            clog << db(id) << db(l) << db(r) << db(id) << endl;
            for (; cur_r < r; ++cur_r) {
                ds.add(a[cur_r]);
            }
            clog << db(cur_r) << endl;
            auto ds2 = ds;
            for (int cur_l = min(r, (bid + 1) * blk_size); cur_l > l; --cur_l) {
                clog << db(cur_l) << endl;
                ds2.add(a[cur_l - 1]);
            }
            ans[id] = ds2.cur_min_val;
        }
    }
    return ans;
}


vector<int> brute() {
    vector<int> ans(q);
    for (auto [l, r, id] : qr) {
        ans[id] = inf;
        rep(i, l, r) rep(f, i + 1, r) { ans[id] = min(ans[id], a[i] | a[f]); }
    }
    return ans;
}

mt19937 rng;
int next(int l, int r) { return l + (int)(rng() % (r - l + 1)); }

void check() {
    ofstream inp("main.inp");
    inp << "1\n";
    n = next(2, 6);
    inp << n << endl;
    rep(i, 0, n) {
        a[i] = next(1, 30);
        inp << a[i] << ' ';
    }
    inp << endl;
    q = next(1, 10);
    inp << q << endl;
    qr.resize(q);
    rep(i, 0, q) {
        qr[i].l = next(1, n);
        qr[i].r = next(1, n);
        if (qr[i].l > qr[i].r)
            swap(qr[i].l, qr[i].r);
        inp << qr[i].l << ' ' << qr[i].r << endl;
        --qr[i].l;
        qr[i].id = i;
    }

    auto ans = solve();
    auto exp = brute();
    if (ans == exp) {
        cout << "OK" << endl;
        return;
    }
    cout << "FAILED" << endl;
    inp << db(ans) << endl;
    inp << db(exp) << endl;
    exit(0);
}

int jalsol_orz() {
#ifdef LOCAL
    while (true) check();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
            clog << db(i) << db(bitset<5>(a[i])) << endl;
        }

        cin >> q;
        qr.resize(q);
        rep(i, 0, q) {
            cin >> qr[i].l >> qr[i].r;
            qr[i].id = i;
            --qr[i].l;
        }
        for (auto i : solve())
            cout << i << '\n';
#ifdef LOCAL
        cout << string(10, '-') << endl;
        for (auto i : brute())
            cout << i << '\n';
        cout << string(10, '=') << endl;
#endif
    }

    return 0;
}