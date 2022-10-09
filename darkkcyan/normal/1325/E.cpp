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

const int maxn = 1000000 + 1;
const int maxlg = 22;
int pdiv[maxn];

void preprocess() {
    for (int i = 2; i < maxn; ++i) {
        if (pdiv[i] != 0) continue;
        for (int f = i; f < maxn; f += i)
            pdiv[f] = i;
    }
}

vector<int> pdiv_parity(int num) {
    vector<int> ans;
    while (num > 1) {
        int p = pdiv[num];
        int par = 0;
        while (num % p == 0) {
            num /= p;
            par ^= 1;
        }
        if (par) ans.push_back(p);
    }
    return ans;
}

int n;
int a[maxn];
vector<int> singles;
vector<int> gr[maxn];

int min_cycle_length() {
    int ans = INT_MAX;
    for (int s = 1; s * s <= maxn; ++s) {
        if (sz(gr[s]) <= 1) continue;
        vector<int> d(maxn, -1), p(maxn, -1);
        queue<int> qu;
        for (qu.push(s), d[s] = 0, p[s] = 0; qu.size(); qu.pop()) {
            int u = qu.front();
            for (auto v: gr[u]) {
                if (d[v] != -1) {
                    if (v != p[u]) ans = min(ans, d[u] + d[v] + 1);
                    continue;
                }
                d[v] = d[u] + 1;
                p[v] = u;
                qu.push(v);
            }
        }
    }
    return ans;
}

int min_connect_singles() {
    vector<int> d(maxn, -1), color(maxn, -1);
    queue<int> qu;
    for (auto u: singles) {
        qu.push(u);
        d[u] = 1;
        color[u] = u;
    }
    
    int ans = INT_MAX;
    for (; qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto v: gr[u]) {
            if (d[v] != -1) {
                if (color[v] == color[u]) continue;
                ans = min(ans, d[u] + d[v] + 1);
                continue;
            }
            d[v] = d[u] + 1;
            color[v] = color[u];
            qu.push(v);
        }
    }
    return ans;
}

int main() {
    preprocess();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    
    {
        set<vector<int>> pds;
        bool has_2 = false;
        rep(i, 0, n) {
            auto pd = pdiv_parity(a[i]);
            assert(sz(pd) <= 2);
            if (sz(pd) == 0) {
                cout << "1\n";
                return 0;
            }
            if (sz(pd) == 2) {
                int &u = pd[0], &v = pd[1];
                gr[u].push_back(v);
                gr[v].push_back(u);
                if (u > v) swap(u, v);
            } else {
                singles.push_back(pd[0]);
            }
            if (pds.count(pd)) {
                has_2 = true;
            }
            else pds.insert(pd);
        }
        if (has_2) {
            cout << "2\n";
            return 0;
        }
    }
    
    int cl = min_cycle_length();
    int cs = min_connect_singles();
    int ans = min(cl, cs);
    // if (n == 78503 and a[0] == 934639 and a[1] == 971549 and a[2] == 969259 ) { 
        // cout << cl << ' ' << cs << ' ' << endl; 
    // } 
    
    if (ans >= INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
    
    return 0;
}

// vim: foldmethod=marker