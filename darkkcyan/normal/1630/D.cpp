#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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

int n, m;
vector<int> a, b;

ll brute() {
    DB();
    auto cal_ans_with_mask = [&](int mask) {
        ll cur_ans = 0;
        rep(i, 0, n) {
            cur_ans += (mask >> i) & 1 ? -a[i] : a[i];
        }
        clog << db(bitset<4>(mask)) << db(cur_ans) << endl;
        return cur_ans;
    };
    queue<int> qu;
    vector<bool> vis(1 << n);
    qu.push(0);
    vis[0] = 1;
    ll ans = LLONG_MIN;
    for (; qu.size(); qu.pop()) {
        int u = qu.front();
        ans = max(ans, cal_ans_with_mask(u));
        for (auto t: b) {
            for (int i = 0, msk = (1 << t) - 1; i + t <= n; ++i, msk <<= 1) {
                int v = u ^ msk;
                if (vis[v]) continue;
                vis[v] = true;
                qu.push(v);
            }
        }
    }
    return ans;
}

ll solve() {
    DB();
    int g = 0;
    for (auto i: b) g = __gcd(g, i);
    clog << db(g) << endl;
    
    vector<multiset<int>> group(g);
    rep(i, 0, n) group[i % g].insert(a[i]);
    
    ll ans = 0;
    for (auto& gr: group) {
        DB();
        assert(sz(gr));
        clog << db(gr) << endl;
        while (*gr.begin() < 0) {
            clog << db(gr) << endl;
            auto x = *gr.begin();
            gr.erase(gr.begin());
            if (sz(gr)  and *gr.begin() < 0) {
                auto y = * gr.begin();
                gr.erase(gr.begin());
                gr.insert(-x);
                gr.insert(-y);
            } else {
                gr.insert(x);
                break;
            }
        }
        if (*gr.begin() < 0 and sz(gr) > 1 and *next(gr.begin()) < abs(*gr.begin())) {
            auto x = *gr.begin();
            gr.erase(gr.begin());
            auto y = *gr.begin();
            gr.erase(gr.begin());
            gr.insert(-x);
            gr.insert(-y);
        }
        ans += accumulate(all(gr), 0ll);
    }
    
    ll oans = ans;
    ll sum_min = 0;
    for (auto& gr: group) {
        sum_min += *gr.begin();
    }
    oans -= 2 * sum_min;
    clog << db(ans) << db(oans) << endl;
    ans = max(ans, oans);
    return ans;
}

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}
void check() {
    n = rand(2, 10);
    m = rand(1, n / 2);
    a.resize(n);
    b.resize(m);
    for (auto& i: a) i = rand(-10, 10);
    for (auto& i: b) i = rand(1, n / 2);
    auto ans = solve();
    auto exp = brute();
    if (ans == exp) {
        cout << "OK" << endl;
        return ;
    }
    ofstream inp("main.inp");
    inp << 1 << endl;
    inp << n << ' ' << m << endl;
    for (auto i: a) inp << i << ' ';
    inp << endl;
    for (auto i: b) inp << i << ' ';
    inp << endl;
    inp << db(ans) << db(exp) << endl;
    exit(0);
}

int main() {
#ifdef LOCAL
    // while (1) check();
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        for (auto& i: a) cin >> i;
        for (auto& i: b) cin >> i;
        cout << solve() << '\n';
#ifdef LOCAL
        cout << db(brute()) << endl;
#endif
    }
    
    return 0;
}

// vim: foldmethod=marker