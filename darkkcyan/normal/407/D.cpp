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

inline int get_input() {
    int a, c;
    while (!isdigit(a = getchar()));
    a -= '0';
    while (isdigit(c = getchar()))
        a = a * 10 + c - '0';
    return a;
}

const int maxn = 512;
const int max_val = 1e6 + 10;

int n, m;
int a[maxn][maxn];

int dp[maxn][maxn];
vector<pair<int, int>> stacks[max_val];
bool vis[max_val];
vector<int> vis_val;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    n = get_input(); 
    m = get_input(); 
    assert(n < maxn); 
    assert(m < maxn); 
    rep(i, 0, n) rep(f, 0, m) { 
        a[f][i] = get_input(); 
        // assert(a[f][i]); 
    } 
    
    vis_val.reserve(n * m + 10);
    
    int ans = 1;
    
    rep(i, 0, n) {
        for (auto x: vis_val) stacks[x].clear();
        
        rep(f, 0, m) {
            if (!vis[a[f][i]]) {
                vis[a[f][i]] = true;
                vis_val.push_back(a[f][i]);
            }
            auto& cur_dp = dp[f];
            cur_dp[i] = f + 1;
            
            if (f) {
                auto& prev_dp = dp[f - 1];
                rep(r, 0, i + 1)
                    cur_dp[r] = min(cur_dp[r], (prev_dp[r] + 1));
            }
            
            for (auto& [r, c]: stacks[a[f][i]]) {
                cur_dp[r] = min(cur_dp[r], (f - c));
            }
            
            int min_width = m;
            int h = 0;
            for (int r = i + 1; r--; ) {
                int val = a[f][r];
                auto& cur_st = stacks[val];
                while (cur_st.size() and cur_st.back().first < r) {
                    cur_st.pop_back();
                }
                auto& cur = cur_dp[r];
                if (cur_st.size()) {
                    cur = min(cur, f - cur_st.back().second);
                }
                while (cur_st.size() and cur_st.back().first == r)
                    cur_st.pop_back();
                cur_st.emplace_back(r, f);
                min_width = cur = min(cur, min_width);
                ans = max(ans, ++h * min_width);
            }
        }
        
    }
    
    cout << ans << '\n';
    
    return 0;
}

// vim: foldmethod=marker