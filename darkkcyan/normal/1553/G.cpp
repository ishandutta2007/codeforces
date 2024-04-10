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

struct DSU {
    vector<int> par;
    DSU() = default;
    DSU(int len): par(len, -1) {}
    int find_set(int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    }
    
    void join(int u, int v) {
        clog << "join " << db(u) << db(v) << endl;
        u = find_set(u);
        v = find_set(v);
        if (u == v) return;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
    }
    
    bool same(int u, int v) {
        return find_set(u) == find_set(v);
    }
};

const int maxn = 150'000 + 100;
const int maxq = 2 * maxn;
const int maxval = (int)1e6 + 100;

int n, q;
ll a[maxn];
map<int, set<int>> gr;
DSU dsu;
bitset<maxval> has;

int last_div[maxval];

void preprocess() {
    dsu = DSU(maxval * 2);
    memset(last_div, 0, sizeof(last_div));
    gr.clear();
    rep(v, 2, maxval) {
        if (last_div[v] == 0) last_div[v] = v;
        for (int f = v; f < maxval; f += v) {
            if (has[f]) dsu.join(v + maxval, f);
            if (last_div[v] == v) last_div[f] = v;
        }
    }
    
    rep(i, 2, maxval - 1) {
        if (!has[i]) continue;
        if (!dsu.same(i, i + 1)) {
            int u = dsu.find_set(i);
            auto& gu = gr[u];
            // auto& gv = gr[v]; 
            vector<int> pr;
            for (int t = i + 1; t > 1; ) {
                int dv = last_div[t];
                while (t % dv == 0) t /= dv;
                int x = dsu.find_set(dv + maxval);
                gu.insert(x);
                clog << db(i) << db(u) << db(u - maxval) << db(dv) << endl;
                for (auto du: pr) {
                    int y = dsu.find_set(du + maxval);
                    gr[y].insert(x);
                    gr[x].insert(x);
                }
                pr.push_back(dv);
            }
            // for (int t = i; t > 1; ) { 
                // int du = last_div[t]; 
                // while (t % du == 0) t /= du; 
                // gv.insert(dsu.find_set(du + maxval)); 
            // } 
            // gu.insert(v); 
            // gv.insert(u); 
        }
    }
}

int query(int s, int t) {
    int u = (int)a[s], v = (int)a[t];
    s = dsu.find_set(u);
    t = dsu.find_set(v);
    clog << db(s) << db(t) << db(s - maxval) << db(t - maxval) << endl;
    if (s == t) return 0;
    auto& gu = gr[s];
    auto& gv = gr[t];
    if (gu.count(t) or gv.count(s)) return 1; 
    for (int x = v; x > 1; ) {
        int dv = last_div[x];
        while (x % dv == 0) x /= dv;
        if (gu.count(dsu.find_set(dv + maxval))) {
            clog << db(dv) << endl;
            return 1;
        }
    }
    for (int x = u; x > 1; ) {
        int du = last_div[x];
        while (x % du == 0) x /= du;
        if (gv.count(dsu.find_set(du + maxval))) {
            clog << db(du) << endl;
            return 1;
        }
    }
    return 2;
}

int brute(int s, int t) {
    auto bfs = [&] {
        vector<bool> vis(n + 1);
        queue<int> qu;
        for (vis[s] = 0, qu.push(s); qu.size(); qu.pop()) {
            int u = qu.front();
            if (u == t) return true;
            rep(i, 0, n + 1) {
                if (a[i] == -1) continue;
                if (vis[i]) continue;
                if (gcd(a[i], a[u]) == 1) continue;
                vis[i] = true;
                qu.push(i);
            }
        }
        return false;
    };
    
    a[n] = -1;
    if (bfs()) return 0;
    for (int i = 0; i < n; ++i) {
        a[n] = a[i] * (a[i] + 1);
        if (bfs()) {
            clog << db(a[n]) << db(i) << db(a[i]) << endl;
            return 1;
        }
    }
    return 2;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (true) {
        has.reset();
        ofstream inp("main.inp");
        n = rand() % 10 + 1;
        rep(i, 0, n) a[i] = rand() % 20 + 1;
        rep(i, 0, n - 1) a[i + 1] += a[i];
        rep(i, 0, n) has[a[i]] = true;
        shuffle(a, a + n, rng);
        preprocess();
        rep(i, 0, n) rep(f, i + 1, n) {
            int ans = query(i, f);
            freopen(".log", "w", stderr);
            int exp = brute(i, f);
            if (ans == exp) continue;
            inp << n << ' ' <<  1 << '\n';
            rep(x, 0, n) inp << a[x] << ' ';
            inp << '\n';
            inp << i + 1 << ' ' << f  + 1<< '\n';
            inp << db(ans) << db(exp) << endl;
            inp.close();
            cout << "FAILED" << endl;
            exit(0);
        }
        cout << "OK" << endl;
    }
}

int main() {
    // check();      
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep(i, 0, n) {
        cin >> a[i];
        has[a[i]] = true;
    }
    
    preprocess();
    while (q--) {
        int s, t; cin >> s >> t;
        --s;
        --t;
        cout << query(s, t) << '\n';  
        // cout << brute(s, t) << '\n';  
    }
    
    return 0;
}

// vim: foldmethod=marker