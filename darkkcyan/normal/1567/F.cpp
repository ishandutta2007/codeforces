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
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const int maxn = 1010;

int n, m;
string grid[maxn];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int comp[maxn][maxn];
int ans[maxn][maxn];

void do_fill(int r, int c, int num) {
    queue<pair<int, int>> qu;
    for (comp[r][c] = num, qu.emplace(r, c); qu.size(); qu.pop()) {
        tie(r, c) = qu.front();
        rep(cdr, -1, 2) rep(cdc, -1, 2) {
            if (cdr == 0 and cdc == 0) continue;
            int nr = r + cdr;
            int nc = c + cdc;
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (grid[nr][nc] == 'X') continue;
            if (comp[nr][nc] != num) {
                comp[nr][nc] = num;
                qu.emplace(nr, nc);
            }
        }
    }
}

int comp_col[maxn * maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n) cin >> grid[i];
    rep(i, 0, n) rep(f, 0, m) {
        if (grid[i][f] != 'X') continue;
        int cnt_nei = 0;
        rep(dir, 0, 4) cnt_nei += grid[i + dr[dir]][f + dc[dir]] == '.';
        if (cnt_nei & 1) {
            cout << "NO\n";
            return 0;
        }
    }
    
    int cur_comp = 0;
    rep(i, 0, n) rep(f, 0, m) {
        if (grid[i][f] == 'X') continue;
        if (comp[i][f]) continue;
        do_fill(i, f, ++cur_comp);
    }
    
    
    memset(comp_col, -1, sizeof(comp_col));
    comp_col[1] = 0;
    
    rep(i, 0, n) {
        int prv = 1;
        rep(f, 0, m) {
            if (grid[i][f] == 'X') {
                // ans[i][f] = -1; 
                continue;
            }
            if (comp_col[comp[i][f]] == -1) {
                comp_col[comp[i][f]] = !comp_col[prv];
            }
            ans[i][f] = (comp_col[comp[i][f]] ^ (f & 1)) ? 1 : 4;
            prv = comp[i][f];
        }
    }
    rep(i, 0, n) rep(f, 0, m) 
        if (grid[i][f] == 'X') rep(dir, 0, 4)  
            if (grid[i + dr[dir]][f + dc[dir]] == '.') 
                ans[i][f] += ans[i + dr[dir]][f + dc[dir]]; 
    cout << "YES\n";
    rep(i, 0, n) {
        rep(f, 0, m) cout << ans[i][f] << ' ' ;
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker