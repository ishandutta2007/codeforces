#include <bits/stdc++.h>
using namespace std;

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

const int maxn = 555;
int n;
int a[maxn][maxn];

vector<int> sale;
int new_empl(int s) {
    sale.push_back(s);
    return len(sale) - 1;
}
vector<pair<int, int>> edge_list;

int solve(vector<int> el) {
    DB();
    if (len(el) == 1) return el[0];
    int mx_val = 0;
    for (auto u: el) for (auto v: el) {
        mx_val = max(mx_val, a[u][v]);
    }
    
    int root = 0;
    while (root < len(el) and sale[el[root]] < mx_val) ++ root;
    if (root == len(el)) {
        root = new_empl(mx_val);
    } else {
        int t = root;
        root = el[root];
        el.erase(el.begin() + t);
    }
    clog << db(mx_val) << db(root) << endl;
    
    while (len(el)) {
        int c = el[0];
        vector<int> left, right;
        for (auto u: el) {
            if (u == root) continue;
            if (a[u][c] == mx_val) right.push_back(u);
            else left.push_back(u);
        }
        clog << db(left) << db(right) << endl;
        el = right;
        int rl = solve(left);
        if (rl != -1) edge_list.emplace_back(rl, root);
    }
    return root;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, n) rep(f, n) cin >> a[i][f];
    rep(i, n) sale.push_back(a[i][i]);
    vector<int> all(n);
    iota(be(all), 0);
    int root = solve(all);
    cout << len(sale) << '\n';
    for (auto i: sale) cout << i << ' ';
    cout << '\n';
    cout << root + 1 << '\n';
    for (auto [u, v]: edge_list) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker