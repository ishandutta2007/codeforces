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
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////
#define db(val) "["#val"] = "<<(val)<<"; "
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
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

const int maxn = 2222;
const ll inf = (ll)1e15;
int n, k;
ll l[maxn], r[maxn], a[maxn];

ll dp[maxn][2];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> l[i] >> r[i] >> a[i];
    }
    
    rep(i, 0, n + 1) rep(start_at, 0, 2) dp[i][start_at] = inf;
    
    dp[0][0] = 0;
    ll ans = inf;
    rep(i, 0, n) {
        rep(start_at, 0, 2) {
            DB();
            ll cur_cost = dp[i][start_at];
            ll rem = k;
            ll cur_time = start_at + l[i];
            clog << db(i) << db(start_at) << db(cur_cost) << db(cur_time) << endl;
            
            rep(f, i, n) {
                DB();
                clog << db(f) << endl;
                if (cur_cost != inf) {
                    cur_time = max(cur_time, l[f]);
                    clog << db(a[f] < rem) << endl;
                    if (a[f] < rem) {
                        if (cur_time > r[f]) {
                            cur_cost = inf;
                        } else {
                            rem -= a[f];
                            cur_cost += a[f];
                        }
                    } else {
                        ll need = a[f] - rem;
                        clog << db(need) << endl;
                        ll required_time = (need + k - 1) / k;
                        clog << db(required_time) << endl;
                        if (required_time > r[f] - cur_time) {
                            cur_cost = inf;
                        } else {
                            cur_cost += a[f];
                            rem = k - need % k;
                            cur_time += required_time;
                            if (rem == k) ++cur_time;
                        }
                    }
                }
                
                clog << db(cur_cost) << db(cur_time) << db(rem) << endl;
                
                dp[f + 1][1] = min(dp[f + 1][1], cur_cost + rem);
                if (f + 1 < n and cur_time < l[f + 1])
                    dp[f + 1][0] = min(dp[f + 1][0], cur_cost + rem);
                if (f == n - 1) ans = min(ans, cur_cost);
            }
        }
    }
    
    if (ans >= inf) ans = -1;
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker