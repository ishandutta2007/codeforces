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

#define int ll
const int maxn = 201010;
const ll inf = (ll)1e15;
struct seg {
    int l, r;
    friend print_op(seg) {
        return out << pair{u.l, u.r};
    }
};
int n, m;
int a[maxn];
seg b[maxn];

int32_t main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n >> m;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) cin >> b[i].l >> b[i].r;
        
        sort(a, a + n);
        clog << db(vector<int>(a, a + n)) << endl;
        m = (int)(remove_if(b, b + m, [&](const seg& u) {
            auto it = lower_bound(a, a + n, u.l);
            clog << db(u) << db(*it) << endl;
            if (it != a + n and *it <= u.r) return true;
            return false;
        }) - b);
        clog << db(m) << endl;
        
        sort(b, b + m, [&](const seg& u, const seg& v) {
                if (u.l == v.l) return u.r < v.r;
                return u.l < v.l;
                });
        clog << db(vector<seg>(b, b + m)) << endl;
        
        
        map<ll, ll> rdp;
        int it = 0;
        for (; it < m; ++it) {
            if (b[it].l > a[0]) break;
            rdp[b[it].r] = inf;
        }
        rdp[a[0]] = inf;
        rdp.begin()->second = 0;
        
        clog << db(rdp) << endl;
        
        rep(i, 0, n) {
            DB();
            map<int, ll> ldp_lc, ldp_rc;
            int nxt_v = i == n - 1 ? INT_MAX : a[i + 1];
            clog << db(i) << db(a[i]) << db(nxt_v) << endl;
            int oit = it;
            for (; it < m and b[it].r < nxt_v; ++it) {
                ldp_lc[b[it].l] = inf;
                ldp_rc[b[it].l] = inf;
            }
            
            ldp_lc[a[i]] = inf;
            ldp_rc[a[i]] = inf;
            clog << endl;
            clog << db(ldp_lc) << endl;
            clog << db(ldp_rc) << endl;
            
            for (auto [x, v]: rdp) {
                DB();
                int dist = a[i] - x;
                clog << db(x) << db(v) << db(dist) << db(dist + a[i]) << endl;
                {
                    auto rc_it = ldp_rc.upper_bound(dist + a[i]);
                    if (rc_it != ldp_rc.begin()) {
                        --rc_it;
                        clog << "found rc" << endl;
                        rc_it->second = min(rc_it->second, dist + v);
                        clog << db(*rc_it) << endl;
                    }
                }
                {
                    auto lc_it = ldp_lc.lower_bound(dist + a[i]);
                    if (lc_it != ldp_lc.end()) {
                        lc_it->second = min(lc_it->second, dist * 2 + v);
                        clog << "foudn lc" << endl;
                        clog << db(*lc_it) << endl;
                    }
                }
            }
            
            clog << endl;
            clog << db(ldp_lc) << endl;
            clog << db(ldp_rc) << endl;
            for (auto cur = ldp_rc.rbegin(), nxt = next(cur); nxt != ldp_rc.rend(); cur = nxt++) {
                nxt->second = min(nxt->second, cur->second);
            }
            
            for (auto cur = ldp_lc.begin(), nxt = next(cur); nxt != ldp_lc.end(); cur = nxt++) {
                nxt->second = min(nxt->second, cur->second);
            }
            clog << endl;
            clog << db(ldp_lc) << endl;
            clog << db(ldp_rc) << endl;
            
            map<int, ll> dp;
            for (auto& [x, v]: ldp_lc) {
                dp[x] = (x - a[i]) + v;
            }
            for (auto& [x, v]: ldp_rc) {
                dp[x] = min(dp[x], v + (x - a[i]) * 2ll);
            }
            clog << db(dp) << endl;
            rdp.clear();
            multiset<int> right_points;
            map<int, vector<int>> c;
            rep(f, oit, it) {
                right_points.insert(b[f].r);
                c[b[f].l].push_back(b[f].r);
                rdp[b[f].r] = inf;
            }
            right_points.insert(nxt_v);
            rdp[nxt_v] = inf;
            
            for (auto [x, v]: dp) {
                for (auto y: c[x]) right_points.erase(right_points.find(y));
                auto& cur_it = rdp[*right_points.begin()];
                cur_it = min(cur_it, v);
            }
            clog << db(rdp) <<endl;
        }
        
        auto ans = rdp.rbegin()->second;
        cout << ans << '\n';
        
    }
    
    return 0;
}

// vim: foldmethod=marker