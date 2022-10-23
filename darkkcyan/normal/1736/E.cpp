#ifdef LOCAL
#define testing
#endif
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

void upd(ll &x, ll y) {
    if (x < y) x = y;
}

ll brute(vector<int> a) {
    map<pair<vector<int>, int>, ll> dp;
    function<ll(vector<int>, int)> cal = [&](vector<int> cur, int pos) -> ll {
        auto [it, is_new] = dp.try_emplace({cur, pos}, 0);
        if (!is_new) return it->second;

        if (pos >= sz(cur)) return 0;

        it->second = max(it->second, cal(cur, pos + 1) + cur[pos]);
        rep(i, 0, sz(a) - 1) {
            auto u = cur[i];
            auto v = cur[i + 1];
            cur[i] = 0;
            cur[i + 1] = u;
            it->second = max(it->second, cal(cur, pos + 1) + cur[pos]);
            cur[i + 1] = 0;
            cur[i] = v;
            it->second = max(it->second, cal(cur, pos + 1) + cur[pos]);
            cur[i] = u;
            cur[i + 1] = v;
        }
        clog << db(cur) << db(pos) << db(it->second) << endl;
        return it->second;
    };
    return cal(a, 0);
}

const int maxn = 505;
const ll inf = (ll)1e15;
ll dp[maxn][maxn][maxn];

mt19937 rng;
int rand(int l, int r) { return l + (int)(rng() % (r - l + 1)); }

int main(int argc, char **argv) {
#ifdef testing
    if (argc == 1)
        while (1) {
            ofstream inp("main.inp");
            int n = rand(2, 8);
            inp << n << endl;
            rep(i, 0, n) { inp << rand(1, 20) << ' '; }
            inp.close();
            system("./main 1");
            ll exp;
            ifstream("main.out") >> exp;
            system("./main 2");
            ll ans;
            ifstream("main.out") >> ans;
            cout << db(ans) << db(exp) << endl;
            assert(ans == exp);
        }
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
#ifdef testing
    if (string(argv[1]) == "1") {
        a.erase(a.begin());
        cout << brute(a) << endl;
        return 0;
    }
#endif

    rep(pos, 0, maxn) {
        rep(cur_elm, 0, maxn) {
            rep(move_left, 0, maxn) { dp[pos][cur_elm][move_left] = -inf; }
        }
    }

    dp[0][0][0] = 0;
    rep(pos, 1, n + 1) {
        DB();
        vector max_move_left(maxn, vector<ll>(maxn, -inf));
        rep(prev_elm, 0, n + 1) {
            rep(move_left, 0, pos + 1) {
                ll cur = dp[pos - 1][prev_elm][move_left];
                if (cur < 0) continue;
                clog << db(pos) << db(prev_elm) << db(move_left) << db(cur)
                     << endl;
                upd(dp[pos][prev_elm][move_left], cur + a[prev_elm]);
                upd(max_move_left[max(prev_elm, pos - 1) + 1][move_left], cur);
            }
        }

        rep(nxt_elm, pos, n + 1) {
            rep(move_left, 0, pos + 1) {
                upd(max_move_left[nxt_elm][move_left],
                    max_move_left[nxt_elm - 1][move_left]);
            }
        }

        DB();
        rep(nxt_elm, pos, n + 1) {
            rep(move_left, 0, pos + 1) {
                int need = nxt_elm - pos;
                if (need > move_left + 1) continue;
                auto cur = max_move_left[nxt_elm][move_left];
                clog << db(nxt_elm) << db(move_left) << db(cur) << endl;
                if (cur < 0) continue;
                upd(dp[pos][nxt_elm][move_left + 1 - need], cur + a[nxt_elm]);
            }
        }
    }
    ll ans = -inf;
    rep(elm, 0, n + 1) {
        rep(move_left, 0, n + 1) {
            clog << db(elm) << db(dp[n][elm][move_left]) << endl;
            ans = max(ans, dp[n][elm][move_left]);
        }
    }
    cout << ans;
#ifdef LOCAL
    cout << endl;
    a.erase(a.begin());
    cout << db(brute(a)) << endl;
#endif

    return 0;
}