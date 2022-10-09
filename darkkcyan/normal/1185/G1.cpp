#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

#define defop(type, op) \
    friend inline type operator op (type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o)
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx) : x((int)(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) <0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 7>;

const int maxn = 51;
const int maxt = 2501;

const int maxval = maxn * 2;
mint choose[maxval][maxval];
mint fac[maxval];
void precal() {
    rep(i, 0, maxval) {
        choose[i][0] = 1;
        rep(f, 1, i + 1)
            choose[i][f] = choose[i - 1][f] + choose[i - 1][f - 1];
    }
    
    fac[0] = 1;
    rep(i, 1, maxval) fac[i] = fac[i - 1] * i;
}


int n, total_time;
vector<int> a[3];

mint dp01[maxt][maxn][maxn];
mint dp2[maxt][maxn];

mint dw[maxn][maxn][maxn][maxn];  // count way

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> total_time;
    
    rep(i, 0, n) {
        int t, g; cin >> t >> g;
        --g;
        a[g].push_back(t);
    }
    
    dp01[0][0][0] = 1;
    rep(i, 0, sz(a[0])) {
        int x = a[0][i];
        for (int t = maxt - x; t--; ) {
            rep(rest, 0, i + 1) {
                dp01[t + x][rest + 1][0] += dp01[t][rest][0];
            }
        }
    }
    
    rep(i, 0, sz(a[1])) {
        int x = a[1][i];
        for (int t = maxt - x; t--; ) {
            rep(c0, 0, sz(a[0]) + 1) {
                rep(rest, 0, i + 1) {
                    dp01[t + x][c0][rest + 1] += dp01[t][c0][rest];
                }
            }
        }
    }
    
    dp2[0][0] = 1;
    rep(i, 0, sz(a[2])) {
        int x = a[2][i];
        for (int t = maxt - x; t --; ) {
            rep(rest, 0, i + 1) {
                dp2[t + x][rest + 1] += dp2[t][rest];
            }
        }
    }
    
    rep(i, 0, sz(a[0]) + 1) dw[max(i - 1, 0)][i][0][0] = 1;
    rep(i, 1, sz(a[1]) + 1) {
        rep(f, 0, sz(a[0]) + 1) {
            int adj_same_prev = max(f - 1, 0);
            auto cur = dw[adj_same_prev][f][0][0];
            rep(cnt_gr, 1, i + 1) {
                int new_adj = i - cnt_gr;
                rep(to_prev_same, 0, adj_same_prev + 1) {
                    int rest = f ? 2 : 1;
                    if (cnt_gr < to_prev_same) continue;
                    auto nw = choose[adj_same_prev][to_prev_same] * choose[rest][cnt_gr - to_prev_same] * choose[i - 1][cnt_gr - 1];
                    dw[adj_same_prev - to_prev_same + new_adj][f][i][0] += cur * nw;
                }
            }
        }
    }
    rep(f, 0, sz(a[0]) + 1)
    rep(g, 0, sz(a[1]) + 1)
    rep(adj_same_prev, 0, f + g + 1) {
        auto cur = dw[adj_same_prev][f][g][0];
        int rest = f + g + 1 - adj_same_prev;
        if (cur.x == 0) continue;
        clog << db(f) << db(g) << db(adj_same_prev) << db(cur) << endl;
        rep(i, max(1, adj_same_prev), sz(a[2]) + 1) {
            // auto nw = choose[rest][i - adj_same_prev] * choose[i][adj_same_prev]; 
            auto nw = choose[rest][i - adj_same_prev];
            dw[0][f][g][i] += cur * nw;
        }
    }
    
    mint ans = 0;
    rep(t01, 0, total_time + 1) {
        int t2 = total_time - t01;
        rep(i, 0, sz(a[0]) + 1) 
        rep(f, 0, sz(a[1]) + 1) 
        rep(g, 0, sz(a[2]) + 1) {
            if (dp01[t01][i][f].x == 0) continue; 
            if (dp2[t2][g].x == 0) continue; 
            clog << db(t01) << db(t2) << db(i) << db(f) << db(g) << endl;
            clog << db(dp01[t01][i][f]) << endl;
            clog << db(dp2[t2][g]) << endl;
            auto cur_ans = dp01[t01][i][f] * dp2[t2][g] * dw[0][i][f][g];
            cur_ans *= fac[i] * fac[f] * fac[g];
            ans += cur_ans;
        }
    }
    cout << ans;
            
    
    return 0;
}

// vim: foldmethod=marker