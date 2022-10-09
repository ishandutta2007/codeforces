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

const int maxn = 200;
int dp[2][2][maxn][maxn];

bool solve(bool player, bool alice_par, int cnt_odd, int cnt_even) {
    int &ans = dp[player][alice_par][cnt_odd][cnt_even];
    if (ans != -1) return !!ans;

    if (!cnt_odd and !cnt_even) return (ans = ((player == 0) == (alice_par == 0)));
    if (!cnt_odd)
        return (ans = !solve(!player, alice_par, cnt_odd, cnt_even - 1));
    if (!cnt_even)
        return (ans = !solve(!player, alice_par ^ (player == 0), cnt_odd - 1, cnt_even));
    return (ans = !solve(!player, alice_par, cnt_odd, cnt_even - 1) or
                 !solve(!player, alice_par ^ (player == 0), cnt_odd - 1, cnt_even));
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    memset(dp, -1, sizeof(dp));
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        int cnt[2] = {0, 0};
        rep(i, 0, n) {
            int x;
            cin >> x;
            cnt[x & 1] ++;
        }
        
        int ans = solve(0, 0, cnt[1], cnt[0]);
        cout << (ans ? "Alice" : "Bob") << '\n';
    }

    return 0;
}