// #pragma GCC optimize ("O3") 
// #pragma GCC optimize ("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;



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
int pa[maxn], b[maxn];

ordered_set<int> se[maxn];

void init() {
    rep(i, 0, n) {
        for (int u = i + 1; u <= n; u += u & -u)
            se[u].insert(b[i]);
    }
}

void do_swap(int x, int y) {
    for (auto i: {x, y}) {
        for (int u = i + 1; u <= n; u += u & -u)
            se[u].erase(b[i]);
    }
    swap(b[x], b[y]);
    for (auto i: {x, y}) {
        for (int u = i + 1; u <= n; u += u & -u)
            se[u].insert(b[i]);
    }
}

int query(int la, int ra, int i) {
    int ans = 0;
    for (++i; i > 0; i -= i & -i) 
        ans += (int)(se[i].order_of_key(ra) - se[i].order_of_key(la));
    return ans;
}

int query(int la, int ra, int lb, int rb) {
    return query(la, ra, rb - 1) - query(la, ra, lb - 1);
}

// #define gentest   

#ifdef gentest 
vector<int> inputs;
mt19937 rng;
#define rand() ((int)(rng() >> 1))
void gen() {
    inputs.push_back(n = 200'000);
    inputs.push_back(m = 200'000);
    vector<int> num;
    rep(i, 0, 200'000) {
        num.push_back(i);
    }
    shuffle(all(num), rng);
    for (auto i: num) inputs.push_back(i);
    
    shuffle(all(num), rng);
    for (auto i: num) inputs.push_back(i);
    
    rep(i, 0, 200'000) {
        int t = rand() % 1 + 1;
        inputs.push_back(t);
        if (t == 1) {
            int la = rand() % n + 1, ra = rand() % n + 1;
            int lb = rand() % n + 1, rb = rand() % n + 1;
            if (la > ra) swap(la, ra);
            if (lb > rb) swap(lb, rb);
            inputs.push_back(la);
            inputs.push_back(ra);
            inputs.push_back(lb);
            inputs.push_back(rb);
        } else {
            int x, y;
            x = rand() % n + 1;
            y = rand() % n + 1;
            inputs.push_back(x);
            inputs.push_back(y);
        }
    }
    reverse(all(inputs));
}
#endif
int get_num() {
#ifdef gentest
    int x = inputs.back();
    inputs.pop_back();
    return x;
#else
    int a, c;
    while (isspace(a = getchar()));
    a -= '0';
    while (isdigit(c = getchar())) {
        a = a * 10 + c - '0';
    }
    return a;
#endif
}

int main() {
#ifdef gentest
    gen();
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);  
    freopen("main.out", "w", stdout);   
    freopen(".log", "w", stderr); 
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    // cin >> n >> m; 
    n = get_num();
    m = get_num();
    rep(i, 0, n) {
        int x;
        // cin >> x; 
        x = get_num();
        pa[x] = i;
    }
    rep(i, 0, n) {
        int x;
        // cin >> x; 
        x = get_num();
        b[i] = pa[x];
    }
    
    // clog << db(vector<int>(b, b + n)) << endl; 
    
    // cerr << "wth" << endl; 
    init();
    // cerr << "wth" << endl; 
    
    rep(i, 0, m) {
        // cerr << i << endl; 
        int t;
        // cin >> t; 
        t = get_num();
        if (t == 1) {
            int la, ra, lb, rb;
            // cin >> la >> ra >> lb >> rb; 
            la = get_num(); ra = get_num();
            lb = get_num(); rb = get_num();
            --la;
            --lb;
            cout << query(la, ra, lb, rb) << '\n';
        } else {
            int x, y;
            // cin >> x >> y; 
            x = get_num();
            y = get_num();
            --x; -- y;
            do_swap(x, y);
        }
    }
    
    return 0;
}

// vim: foldmethod=marker