
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
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

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
const int inf = 1e9;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    if (k & 1) {
        rep(i, 0, n) {
            rep(f, 0, m) cout << "-1 ";
            cout << '\n';
        }
        return 0;
    }
    
    vector<vector<array<int, 4>>> cost(n, vector<array<int, 4>>(m));
    rep(i, 0, n) rep(f, 0, m - 1) {
        int x; cin >> x;
        cost[i][f][3] = x;
        cost[i][f + 1][1] = x;
    }
    
    rep(i, 0, n - 1) rep(f, 0, m) {
        int x; cin >> x;
        cost[i][f][2] = x;
        cost[i + 1][f][0] = x;
    }
    
    k /= 2;
    
    vector ans(n, vector<ll>(m));
    
    rep(_, 0, k) {
        vector new_ans(n, vector<ll>(m, inf));
        rep(r, 0, n) {
            rep(c, 0, m) {
                rep(dir, 0, 4) {
                    int nr = r + dr[dir], nc = c + dc[dir];
                    if (nr < 0 or nc < 0 or nr >= n or nc >= m) continue;
                    new_ans[r][c] = min(new_ans[r][c], ans[nr][nc] + 2 * cost[r][c][dir]);
                }
            }
        }
        ans = move(new_ans);
    }
    
    rep(i, 0, n) {
        rep(f, 0, m) {
            cout << ans[i][f] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker