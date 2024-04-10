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

using i128 = __int128;

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a)
            cin >> i;

        sort(all(a));

        ll sum = accumulate(all(a), 0ll);

        auto cal_pos_k = [&](auto k) {
            return (a[0] + k) * (sum - a[0] + k * (n - 1)) - k * k * (n - 1);
        };

        if (cal_pos_k(-a[0] + 1) < cal_pos_k(-a[0] + 2)) {
            cout << "INF\n";
            continue;
        }

        if (cal_pos_k(i128(1e9)) < cal_pos_k(i128(1e9) + 1)) {
            cout << "INF\n";
        }

        auto cal_neg_k = [&](auto k) {
            return (a.back() + k) * (sum - a.back() + k * (n - 1)) -
                   k * k * (n - 1);
        };

        if (cal_neg_k(-a.back() - 1) < cal_neg_k(-a.back() - 2)) {
            cout << "INF\n";
            continue;
        }
        if (cal_neg_k(-i128(1e9)) < cal_neg_k(-i128(1e9) - 1)) {
            cout << "INF\n";
            continue;
        }

        auto cal_mid_k = [&](ld k, ll sum_pref, ll sum_suff, int cnt_pref,
                             int cnt_suff, ll max_pref, ll min_suff) {
            auto ans = (max_pref + k) * (sum_suff + k * cnt_suff) +
                       (min_suff + k) * (sum_pref + k * cnt_pref) -
                       (max_pref + k) * (min_suff + k) - k * k * (n - 1);
            clog << db(k) << db(sum_pref) << db(sum_suff) << db(cnt_pref)
                 << db(cnt_suff) << db(max_pref) << db(min_suff) << db(ans)
                 << endl;
            return ans;
        };

        // auto true_cal = [&](ld k) {
            // vector<int> dsu(n, -1);
            // function<int(int)> find_set = [&](int u) {
                // return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
            // };
            // auto join = [&](int u, int v) {
                // u = find_set(u);
                // v = find_set(v);
                // if (u == v)
                    // return false;
                // if (-dsu[u] < -dsu[v])
                    // swap(u, v);
                // dsu[u] += dsu[v];
                // dsu[v] = u;
                // return true;
            // };
// 
            // vector<tuple<ld, int, int>> edges;
            // rep(i, 0, n) rep(f, i + 1, n) {
                // edges.emplace_back(a[i] * a[f] + k * (a[i] + a[f]), i, f);
            // }
            // sort(all(edges));
            // ld mst = 0;
            // for (auto [c, u, v] : edges) {
                // if (join(u, v))
                    // mst += c;
            // }
            // return mst;
        // };
// 
        // for (ld k = -20; k <= 20; k += 0.2) {
            // clog << db(k) << db(true_cal(k)) << endl;
        // }

        auto tern_search = [&](auto func, ld l, ld r) {
            rep(iter, 0, 70) {
                ld mid1 = l + (r - l) / 3;
                ld mid2 = r - (r - l) / 3;
                if (func(mid1) < func(mid2)) {
                    l = mid1;
                } else {
                    r = mid2;
                }
            }
            clog << db(l) << db(func(l)) << endl;
            return func(l);
        };

        ld ans = max(cal_neg_k(-a.back()), cal_pos_k(-a[0]));

        ll sum_pref = 0, sum_suff = sum;
        int cnt_pref = 0, cnt_suff = n;
        rep(i, 0, n - 1) {
            sum_suff -= a[i];
            --cnt_suff;

            ll k = -a[i];

            if (i > 0) {
                ll cur_ans = (a[0] + k) * (sum_suff + cnt_suff * k) +
                             (a.back() + k) * (sum_pref + cnt_pref * k) -
                             (a[0] + k) * (a.back() + k) - k * k * (n - 1);
                ans = max(ans, (ld)cur_ans);
            }
            ++cnt_pref;
            sum_pref += a[i];
            auto cur_ans = tern_search(
                [&](ld x) -> ld {
                    return cal_mid_k(x, sum_pref, sum_suff, cnt_pref, cnt_suff,
                                     a[0], a.back());
                },
                -a[i + 1], -a[i]);
            ans = max(ans, cur_ans);
        }
        cout << (ll)round(ans) << '\n';
    }

    return 0;
}