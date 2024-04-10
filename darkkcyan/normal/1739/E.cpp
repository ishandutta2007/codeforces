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

namespace detail { // adapt to your "private" namespace
template <typename F> struct FinalAction {
    FinalAction(F f) : clean_{f} {}
    ~FinalAction() {
        if (enabled_) clean_();
    }
    void disable() { enabled_ = false; };

  private:
    F clean_;
    bool enabled_{true};
};
} // namespace detail

template <typename F> detail::FinalAction<F> finally(F f) {
    return detail::FinalAction<F>(f);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int ntest = 1;
    while (ntest--) {
        int n;
        cin >> n;
        string board[2];
        rep(i, 0, 2) { cin >> board[i]; }

        const int inf = (int)1e7;
        vector dp(n + 1, vector(2, vector(2, inf)));

        dp[0][0][0] = 0;
        rep(col, 0, n) {
            rep(cur_row, 0, 2) {
                rep(del_ahead, 0, 2) {
                    char c = board[!cur_row][col];
                    if (del_ahead) {
                        board[!cur_row][col] = '0';
                    }
                    auto save_next_col = finally([&] {
                        board[!cur_row][col] = c;
                    });

                    int cur_val = dp[col][cur_row][del_ahead];
                    if (board[!cur_row][col] == '0') {
                        int &t = dp[col + 1][cur_row][0];
                        t = min(t, cur_val);
                        continue;
                    }
                    
                    
                    int &t2 = dp[col + 1][cur_row][0];
                    t2 = min(t2, cur_val + 1);
                    
                    if (col + 1 < n and board[cur_row][col + 1] == '1') {
                        int &t1 = dp[col + 1][!cur_row][1];
                        t1 = min(t1, cur_val + 1);
                    } else {
                        int &t = dp[col + 1][!cur_row][0];
                        t = min(t, cur_val);
                    }
                }
            }
            clog << db(col) << db(dp[col + 1]) << endl;
        }
        int ans = inf;
        rep(cur_row, 0, 2) rep(del_ahead, 0, 2) ans = min(ans, dp[n][cur_row][del_ahead]);
        assert(ans < inf);
        cout << ranges::count(board | views::join, '1') - ans << '\n';
    }

    return 0;
}