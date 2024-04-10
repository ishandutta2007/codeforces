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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1;
    rep(i, 1, n + 1) cin >> a[i];
    string s;
    cin >> s;

    const int inf = 1e9;
    vector del_cost(n + 1, vector(n + 1, vector<int>(n + 1, -inf)));
    
    rep(i, 0, n) {
        if (a[1] != -1) del_cost[i][i + 1][0] = a[1];
        del_cost[i][i + 1][1] = 0;
        del_cost[i][i][0] = 0;
    }
    
    auto chkmx = [&](int& num, int new_num) {
        return num = max(num, new_num);
    };
    
    rep(len, 2, n + 1) {
        rep(l, 0, n - len + 1) {
            int r = l + len;
            rep(mid, l + 1, r) {
                if (del_cost[l][mid][0] > -inf) {
                    rep(pl, 0, r - mid + 1) {
                        chkmx(del_cost[l][r][pl], del_cost[mid][r][pl] + del_cost[l][mid][0]);
                    }
                }
                if (del_cost[mid][r][0] > -inf) {
                    rep(pl, 0, mid - l + 1) {
                        chkmx(del_cost[l][r][pl], del_cost[l][mid][pl] + del_cost[mid][r][0]);
                    }
                }
            }
            if (s[l] == s[r - 1]) {
                rep(pl, 0, r - l) {
                    chkmx(del_cost[l][r][pl + 2], del_cost[l + 1][r - 1][pl]);
                }
            }
            rep(pl, 1, r - l + 1) {
                if (a[pl] != -1) {
                    chkmx(del_cost[l][r][0], del_cost[l][r][pl] + a[pl]);
                }
            }
        }
    }
    
    
    vector<int> dp(n + 1);
    rep(i, 0, n) {
        dp[i + 1] = dp[i];
        rep(f, 0, i + 1) {
            dp[i + 1] = max(dp[i + 1], dp[f] + del_cost[f][i + 1][0]);
        }
    }
    cout << dp[n];

    return 0;
}