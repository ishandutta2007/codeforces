#include <bits/stdc++.h>
using namespace std;

#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define def_op(op, uop) \
    inline self_t& operator uop(const self_t& o) { CONCAT(op_helper, __LINE__)(o); return *this; } \
    friend inline self_t operator op (self_t lhs, const self_t & rhs) { return lhs uop rhs; } \
    inline void CONCAT(op_helper, __LINE__)(const self_t& o)
#define def_cmp_op(op, body) friend inline bool operator op(const self_t& u, const self_t& v) { return body; }
template<int mod>
struct ModInt {
    using self_t = ModInt<mod>;
    int x;
    ModInt(): x(0) {}
    ModInt(int v): x(v >= mod ? v - mod : v < 0 ? v + mod : v) {}
    ModInt(long long v): ModInt((int)(v % mod)) {}
    def_op(+, +=) {x += o.x; if (x >= mod) x -= mod;}
    def_op(-, -=) {x -= o.x; if (x < 0) x += mod;}
    def_op(*, *=) {x = (int)(1ll * x * o.x % mod); }
    def_op(/, /=) {x = o.pow(mod - 2, x).x; }
    self_t pow(long long exp, self_t ans = 1) const {
        self_t base = *this;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ans *= base;
            base *= base;
        }
        return ans;
    }
    def_cmp_op(==, u.x == v.x;)
    def_cmp_op(!=, u.x != v.x;) 
    def_cmp_op(<, u.x < v.x;) 
    friend ostream& operator<<(ostream& out, const self_t& u) { return out << u.x; }
};

using mint = ModInt<998'244'353>;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

const int maxn = 404;
int n, m;
vector<int> gr[maxn];

vector<int> bfs(int u) {
    vector<int> dst(n + 1, -1);
    dst[u] = 0;
    queue<int> qu;
    for (qu.push(u); qu.size(); qu.pop()) {
        u = qu.front();
        for (auto v: gr[u]) {
            if (dst[v] != -1) continue;
            dst[v] = dst[u] + 1;
            qu.push(v);
        }
    }
    return dst;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    vector<vector<int>> dst(n + 1);
    rep1(i, n) dst[i] = bfs(i);
    
    vector<vector<mint>> ans(n + 1, vector<mint>(n + 1));
    
    rep1(x, n) for (int y = x; y <= n; ++y) {
        DB();
        clog << db(x) << db(y) << endl;
        mint cur_ans = 1;
        int node_between = 0;
        rep1(u, n) {
            if (u == x or u == y) continue;
            DB();
            clog << db(u) << endl;
            // if (u == x or u == y) continue; 
            
            int cnt_pos = 0;
            int cnt_alter = 0;
            for (auto& v: gr[u]) {
                int dx = dst[x][u] - dst[x][v];
                int dy = dst[y][u] - dst[y][v];
                clog << db(v) << db(dx) << db(dy) << endl;
                if (abs(dx) != 1 or abs(dy) != 1) continue;
                if (dx < 0 and dy < 0) continue;
                cnt_pos += dx > 0 and dy > 0;
                cnt_alter += dx < 0 or dy < 0;
            }
            clog << db(cnt_pos) << db(cnt_alter) << endl;
            if (cnt_pos) {
                cur_ans *= cnt_pos;
                continue;
            }
            if (cnt_alter != 2) {
                cur_ans = 0;
                break;
            }
            ++node_between;
        }
        if (x != y and node_between != dst[x][y] - 1) cur_ans = 0;
        ans[x][y] = ans[y][x] = cur_ans;
    }
    rep1(x, n) {
        rep1(y, n) cout << ans[x][y] << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker