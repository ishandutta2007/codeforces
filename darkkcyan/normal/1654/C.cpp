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

bool check1(const vector<ll> &a) {
    multiset<ll> se(all(a));
    while (sz(se) > 1) {
        auto u = *se.begin();
        se.erase(se.begin());
        auto it = se.find(u + 1);
        if (it != se.end()) {
            u += *it;
            se.erase(it);
            se.insert(u);
        } else if (*se.begin() == u) {
            se.erase(se.begin());
            u *= 2;
            se.insert(u);
        } else {
            return false;
        }
    }
    return true;
}

bool solve(vector<ll> a) {
    ll s = accumulate(all(a), 0ll);
    multiset<ll> se(all(a));
    ll small = s;
    ll cnt_big = 0, cnt_small = 1;
    while (true) {
        clog << db(small) << db(cnt_small) << db(cnt_big) << endl;
        while (cnt_small) {
            auto it = se.find(small);
            if (it == se.end()) break;
            se.erase(it);
            --cnt_small;
        }
        while (cnt_big) {
            auto it = se.find(small + 1);
            if (it == se.end()) break;
            se.erase(it);
            --cnt_big;
        }
        if (cnt_big == 0 and cnt_small == 0) return true;
        if (cnt_small == 0) {
            small ++;
            swap(cnt_small, cnt_big);
        }
        if (small == 1 and cnt_small) return false;
        if (small & 1) {
            small /= 2;
            cnt_big = cnt_big * 2 + cnt_small;
        } else {
            small /= 2;
            cnt_small = cnt_small * 2 + cnt_big;
        }
    }
    return false;
}

mt19937_64 rng;
ll rand(ll l, ll r) {
    return l + (ll)(rng() % (r - l + 1));
}

void check() {
    ll w = rand(1, 10000);
    int n = (int)rand(1, 20);
    vector<ll> a = {w};
    while (n--) {
        int pos = (int)rand(0, sz(a) - 1);
        swap(a[pos], a.back());
        if (a.back() == 1) continue;
        auto t = a.back();
        a.back() /= 2;
        a.push_back((t + 1) / 2);
    }
    cout << w << endl;
    cout << sz(a) << endl;
    cout << a << endl;
    auto ans = solve(a);
    if (!ans) {
        cout << "NAH" << endl;
        exit(0);
    }
    cout << "OK" << endl;
}

int jalsol_orz() {
#ifdef LOCAL
    // while (1) check();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        clog << db(ntest) << endl;
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a)
            cin >> i;
        clog << db(a) << endl;
        cout << (solve(a) ? "YES" : "NO") << '\n';
    }

    return 0;
}