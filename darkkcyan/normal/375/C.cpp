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

const int maxn = 22;
const int max_mask = 1 << 9;
const int inf = 1e5;
int n, m;
string board[maxn];

vector<pair<int, int>> bomb_pos, tres_pos;
vector<int> tres_val;

int cal_mask(int c, int r1, int r2) {
    if (r1 > r2) swap(r1, r2);
    int ans = 0;
    int i = 0;
    for (auto [tr, tc]: tres_pos) {
        if (tr == r1 and tc <= c) ans |= 1 << i;
        ++i;
    }
    for (auto [br, bc]: bomb_pos) {
        if (br == r1 and bc <= c) ans |= 1 << i;
        ++i;
    }
    return ans;
}

int mask_val(int mask) {
    int ans = 0;
    rep(i, 0, sz(tres_val)) 
        if ((mask >> i) & 1) ans += tres_val[i];
    return ans;
}

int dist[maxn][maxn][max_mask];

struct State {
    int r, c;
    int mask;
    
    int& get_dist() const {
        return dist[r][c][mask];
    }
    
    friend ostream&operator<<(ostream& out, const State& u) {
        return out << "(" << u.r << ", " << u.c << ", " << bitset<8>(u.mask) << ", " <<u.get_dist() << ")";
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int sr = -1, sc = -1;
    rep(i, 0, n) {
        cin >> board[i];
        rep(f, 0, m) {
            if (board[i][f] == 'S') {
                sr = i;
                sc = f;
            }
            if (isdigit(board[i][f])) {
                int tres_id = board[i][f] - '1';
                while (sz(tres_pos) <= tres_id) tres_pos.emplace_back();
                tres_pos[tres_id] = {i, f};
            }
            if (board[i][f] == 'B') {
                bomb_pos.emplace_back(i, f);
            }
        }
    }
    
    clog << db(tres_pos) << endl;
    clog << db(bomb_pos) << endl;
    tres_val.resize(tres_pos.size());
    for (auto& i: tres_val) cin >> i;
    
    rep(i, 0, n) rep(f, 0, m) rep(mask, 0, max_mask) dist[i][f][mask] = inf;
    
    State start = {sr, sc, 0};
    queue<State> qu;
    
    for (start.get_dist() = 0, qu.push(start); qu.size(); qu.pop()) {
        auto u = qu.front();
        clog << db(u) << endl;
        rep(dir, 0, 4) {
            int nr = u.r + dr[dir];
            int nc = u.c + dc[dir];
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (board[nr][nc] != '.' and board[nr][nc] != 'S') continue;
            auto new_mask = u.mask ^ (dc[dir] == 0 ? cal_mask(u.c, u.r, nr) : 0);
            State v = {nr, nc, new_mask};
            if (v.get_dist() != inf) continue;
            v.get_dist() = u.get_dist() + 1;
            qu.push(v);
        }
    }
    
    int ans = 0;
    rep(mask, 0, (1 << sz(tres_val))) {
        ans = max(ans, mask_val(mask) - dist[sr][sc][mask]);
    }
    cout << ans;
    return 0;
}

// vim: foldmethod=marker