#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

const int maxn = 501010;
const int mod = (int)1e9 + 7;

inline int add(int a, int b) {
    a += b;
    if (a >= mod) a-= mod;
    if (a < 0) a += mod;
    return a;
}

inline int sub(int a, int b) {
    a -= b;
    if (a >= mod) a-= mod;
    if (a < 0) a += mod;
    return a;
}

inline int mul(int a, int b) {
    llong ans = 1ll * a * b;
    ans %= mod;
    return (int)ans;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int fac[maxn], ifac[maxn], inv[maxn];
int p2[maxn];
void precal() {
    inv[1] = 1;
    for (int i = 2; i < maxn; ++i)
        inv[i] = sub(0, mul(mod / i % mod, inv[mod % i]));
    fac[0] = ifac[0] = 1;
    rep1(i, maxn - 1) {
        fac[i] = mul(fac[i - 1], i);
        ifac[i] = mul(ifac[i - 1], inv[i]);
    }
    p2[0] = 1;
    rep1(i, maxn - 1) p2[i] = add(p2[i - 1], p2[i - 1]);
}

int choose(int n, int k) {
    if (k > n or k < 0 or n < 0) return 0;
    return mul(mul(fac[n], ifac[k]), ifac[n - k]);
}

int n, m;
vector<int> x[maxn];

int dsu[maxn];
bool has_single[maxn];
bool used[maxn];

int find_set(int u) {
    return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
}

bool join(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return false;
    if (-dsu[u] < -dsu[v]) swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    if (has_single[v]) has_single[u] = 1;
    if (used[v]) used[u] = 1;
    return true;
}


pair<int, vector<int>> solve() {
    memset(dsu, -1, sizeof(dsu));
    vector<int> basis;
    int first_single = -1;
    for (int i = 0; i < n; ++i) {
        if (len(x[i]) == 1) {
            int u = find_set(x[i][0]);
            if (has_single[u]) continue;
            basis.push_back(i);
            has_single[u] = 1;
            if (first_single == -1) {
                first_single = u;
                continue;
            }
            join(first_single, u);
            used[find_set(u)] = true;
            continue;
        }   
        int u = find_set(x[i][0]), v = find_set(x[i][1]);
        if (u == v) continue;
        basis.push_back(i);
        join(u, v);
        used[find_set(u)] = true;
    }
    
    return {p2[len(basis)], basis};
}

const int max_bit = 30;

// pair<int, vector<int>> brute() { 
    // llong basis[60]; 
    // memset(basis, 0, sizeof(basis)); 
    //  
    // auto add = [&](llong num) -> bool { 
        // for (int i = max_bit; i--; ) { 
            // if (!((num >> i) & 1)) continue; 
            // if (!basis[i]) { 
                // basis[i] = num; 
                // return true; 
            // } 
            // num ^= basis[i]; 
        // } 
        // return false; 
    // }; 
    //  
    //  
// } 


int main(void) {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) {
        int k; cin >> k;
        x[i].resize(k);
        rep(f, k) cin >> x[i][f];
    }
    
    auto [t, b] = solve();
    cout << t << ' ' << len(b) << '\n';
    for (auto i: b) cout << i + 1 << ' ';
    
    
    return 0;
}

// vim: foldmethod=marker