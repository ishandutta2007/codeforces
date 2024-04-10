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

const int maxn = 201010;
int n, m;
ll x[maxn], t[maxn], c[maxn];
ll p[maxn], b[maxn];

ll pv[maxn];
struct cmp_frog {
    bool operator()(int u, int v) const {
        return x[u] < x[v];
    }
};

set<int, cmp_frog> it[maxn * 4];
void toggle_frog(int fi, int i, int l, int r) {
    if (x[fi] > pv[r] or x[fi] + t[fi] < pv[l]) return ;
    if (x[fi] <= pv[l] and pv[r] <= x[fi] + t[fi]) {
        if (it[i].count(fi)) it[i].erase(fi);
        else it[i].insert(fi);
        return ;
    }
    int mid = (l + r) / 2;
    toggle_frog(fi, 2 * i, l, mid);
    toggle_frog(fi, 2 * i + 1, mid + 1, r);
}

int find_min_frog(ll pos, int i, int l, int r) {
    if (pos < pv[l] or pv[r] < pos) return n;  // a special frog
    auto cur_ans = it[i].empty() ? n : *it[i].begin();
    if (l == r) {
        return cur_ans;
    }
    int mid = (l + r) / 2;
    return min({
        find_min_frog(pos, 2 * i, l, mid),
        find_min_frog(pos, 2 * i + 1, mid + 1, r),
        cur_ans
    }, cmp_frog());
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 0, n) cin >> x[i] >> t[i];
    x[n] = *max_element(x, x + n) + 1;
    
    rep(i, 0, m) cin >> p[i] >> b[i];
    copy_n(p, m, pv);
    sort(pv, pv + m);
    int pvs = (int)(unique(pv, pv + m) - pv);
    
    clog << db(vector<int>(pv, pv + pvs)) << endl;
    
    rep(i, 0, n) toggle_frog(i, 1, 0, pvs - 1);
    set<pair<int, int>> pendding;
    rep(i, 0, m) {
        auto fi = find_min_frog(p[i], 1, 0, pvs - 1);
        clog << db(i) << db(fi) << endl;
        if (fi < n) {
            ++c[fi];
            toggle_frog(fi, 1, 0, pvs - 1);
            t[fi] += b[i];
            
            auto pit = pendding.lower_bound({x[fi], -1});
            while (true) {
                if (pit == pendding.end()) break;
                if (pit->first > x[fi] + t[fi]) break;
                ++c[fi];
                t[fi] += b[pit->second];
                pit = pendding.erase(pit);
            }
            
            toggle_frog(fi, 1, 0, pvs - 1);
        } else {
            pendding.emplace(p[i], i);
        }
    }
    rep(i, 0, n) {
        cout << c[i] << ' ' << t[i] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker