#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

bool solve() {
    DB("test");
    int n, m; cin >> n >> m;
    deb(n, m);
    vector<string> grid(n + 2);
    rep1(i, n) {
        cin >> grid[i];
        grid[i] = "#" + grid[i] + "#";
    }
    
    grid[0] = grid[n + 1] = string(m + 2, '#');
    
    rep1(i, n) rep1(f, m) {
        if (grid[i][f] != 'B') continue;
        rep(dir, 4) {
            int nr = i + dr[dir], nc = f + dc[dir];
            if (grid[nr][nc] == 'B') continue;
            if (grid[nr][nc] == 'G') return false;
            grid[nr][nc] = '#';
        }
    }
    
    queue<pair<int, int>> qu;
    vector<vector<bool>> reachable(n + 2, vector<bool>(m + 2, false));
    
    if (grid[n][m] == '.') {
        qu.emplace(n, m);
        reachable[n][m] = true;
    }
    
    for (; qu.size(); qu.pop()) {
        auto [r, c] = qu.front();
        
        rep(dir, 4) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr < 0 or nr > n + 1 or nc < 0 or nc > m + 1)  continue;
            if (reachable[nr][nc]) continue;
            if (grid[nr][nc] == '#') continue;
            reachable[nr][nc] = true;
            qu.emplace(nr, nc);
        }
    }
    
    for (auto s: grid) {
        deb(s);
    }
    
    rep1(r, n) rep1(c, m) {
        if (grid[r][c] == '.') continue;
        if (grid[r][c] == 'G') {
            if (!reachable[r][c]) return false;
            continue;
        }
        deb(r, c, grid[r][c]);
        assert(!reachable[r][c]);
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cout << (solve() ? "Yes\n" : "No\n");
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker