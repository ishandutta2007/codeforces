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

struct DSU {
    vector<int> par;
    int comp_cnt;
    DSU(int n) : par(n, -1), comp_cnt(n) {}

    int find_set(int u) { return par[u] < 0 ? u : par[u] = find_set(par[u]); }

    void join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v)
            return;
        if (-par[u] < -par[v])
            swap(u, v);
        par[u] += par[v];
        par[v] = u;
        --comp_cnt;
    }

    bool same_set(int u, int v) { return find_set(u) == find_set(v); }
};

int main() {
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
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        int ans = 0;
        for (auto &i : a) {
            if (i == 0) {
                ++i;
                ++ans;
            }
        }

        auto are_connected = [&] {
            DSU dsu(n + 30);
            rep(i, 0, n) rep(bit, 0, 30) {
                if ((a[i] >> bit) & 1)
                    dsu.join(i, n + bit);
            }
            rep(i, 1, n) if (!dsu.same_set(0, i)) return false;
            return true;
        };
        auto print_ans = [&] {
            cout << ans << '\n';
            for (auto i : a)
                cout << i << ' ';
            cout << '\n';
        };
        if (are_connected()) {
            print_ans();
            continue;
        }
        
        bool found = false;
        rep(i, 0, n) {
            ++a[i];
            if (are_connected()) {
                ++ans;
                found = true;
                break;
            }
            --a[i];
        }
        if (found) {
            print_ans();
            continue;
        }

        vector<int> mx_last = {0};
        rep(i, 1, n) {
            int u = a[mx_last[0]] & -a[mx_last[0]];
            int v = a[i] & -a[i];
            if (u == v)
                mx_last.push_back(i);
            else if (u < v)
                mx_last = {i};
        }
        clog << db(mx_last) << endl;
        found = false;
        for (auto t : mx_last) {
            DSU dsu2(n + 30);
            --a[t];
            clog << db(t) << db(a) << endl;
            rep(i, 0, n) {
                rep(bit, 0, 30) {
                    if ((a[i] >> bit) & 1)
                        dsu2.join(i, n + bit);
                }
            }
            bool connected = true;
            rep(i, 1, n) if (!dsu2.same_set(i, 0)) {
                connected = false;
                break;
            }
            if (connected) {
                found = true;
                ++ans;
                break;
            }
            ++a[t];
        }
        if (found) {
            print_ans();
            continue;
        }
        assert(mx_last.size() > 1);
        --a[mx_last[0]];
        ++a[mx_last[1]];
        ans += 2;
        print_ans();
    }

    return 0;
}