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

const ll mod = (int)1e9 + 7;
const int maxn = 1010100;
int n;
ll a[maxn];
int p[maxn];
vector<int> gr[maxn];
ll subcnt[maxn];

void dfs1(int u) {
    subcnt[u] = a[u];
    for (auto v: gr[u]) {
        dfs1(v);
        subcnt[u] += subcnt[v];
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 2, n + 1) {
        cin >> p[i];
        gr[p[i]].push_back(i);
    }
    
    dfs1(1);
    
    vector<ll> cnt(n + 1);
    rep(i, 1, n + 1) {
        ll g = __gcd(subcnt[1], subcnt[i]);
        ll t = subcnt[1] / g;
        clog << db(i) << db(t) << db(subcnt[i]) << endl;
        if (t > n) continue;
        cnt[t]++;
    }
    clog << db(cnt) << endl;
    
    for (int i = n; i-- > 1; ) {
        for (int f = 2 * i; f <= n; f += i)
            cnt[f] += cnt[i];
    }
    
    clog << db(cnt) << endl;
    
    rep(i, 1, n + 1) {
        if (subcnt[1] % cnt[i] == 0 and cnt[i] == i) {
            cnt[i] = 1;
        } else {
            cnt[i] = 0;
        }
    }
    clog << db(cnt) << endl;
    
    for (int i = n; i-- > 1; ) {
        if (!cnt[i]) continue;
        for (int f = 2 * i; f <= n; f += i)  {
            cnt[i] += cnt[f];
            if (cnt[i] >= mod) {
                cnt[i] -= mod;
            }
        }
    }
    
    cout << cnt[1];
    
    return 0;
}

// vim: foldmethod=marker