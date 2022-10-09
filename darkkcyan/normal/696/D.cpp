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

const ll inf = 1e18;
struct MPMat {
    vector<vector<ll>> data;
    MPMat(int n, int m, ll init_val = inf): data(n, vector<ll>(m, init_val)) {}
    vector<ll>& operator[](int id) { return data[id]; }
    const vector<ll>& operator[](int id) const { return data[id]; }
    
    int nrow() const { return sz(data); }
    int ncol() const { return sz(data[0]); }
    
    friend MPMat operator*(const MPMat& u, const MPMat& v) {
        assert(u.ncol() == v.nrow());
        MPMat ans(u.nrow(), v.ncol());
        rep(i, 0, u.nrow())
        rep(f, 0, v.ncol())
        rep(k, 0, u.ncol())
            ans[i][f] = min(ans[i][f], u[i][k] + v[k][f]);
        return ans;
    }
    
    MPMat pow(ll exp) const {
        assert(nrow() == ncol());
        MPMat base = *this, ans(nrow(), nrow(), 0);
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};
print_op(MPMat) {
    for (auto& row: u.data) {
        out << row << endl;
    }
    return out;
}

struct AhoCorasick {
    enum {alpha = 26, fch = 'a', init_val = 0};
    struct Node {
        int next[alpha];
        int link = -1;
        int p, pch;
        int val = init_val;
        Node(int from, int ch): p(from), pch(ch) {
            memset(next, -1, sizeof(next));
        }
    };
    vector<Node> nodes = vector(1, Node(0, -1));
    void insert(const string& s, int val) {
        int root = 0;
        for (auto c: s) {
            int ch = c - fch;
            if (nodes[root].next[ch] == -1) {
                nodes[root].next[ch] = sz(nodes);
                nodes.emplace_back(root, ch);
            }
            root = nodes[root].next[ch];
        }
        nodes[root].val += val;
    }
    
    int go(int u, int ch) {
        // clog << db(u) << db(ch) << endl; 
        if (nodes[u].next[ch] == -1) {
            if (u) nodes[u].next[ch] = go(get_link(u), ch);
            else nodes[u].next[ch] = 0;
        }
        return nodes[u].next[ch];
    }
    
    int get_link(int u) {
        if (nodes[u].link != -1) return nodes[u].link;
        if (u == 0 or nodes[u].p == 0) nodes[u].link = nodes[u].p;
        else nodes[u].link = go(get_link(nodes[u].p), nodes[u].pch);
        get_link(nodes[u].link);
        nodes[u].val += nodes[nodes[u].link].val;
        return nodes[u].link;
    }
    
    string get(int u) {
        string ans = "";
        while (u) {
            ans += char(fch + nodes[u].pch);
            u = nodes[u].p;
        }
        reverse(all(ans));
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    ll l;
    cin >> n >> l;
    vector<int> val(n);;
    vector<string> s(n);
    rep(i, 0, n) cin >> val[i];
    rep(i, 0, n) cin >> s[i];
    
    AhoCorasick ac;
    rep(i, 0, n) ac.insert(s[i], val[i]);
    
    int ns = sz(ac.nodes);
    int maxval = 0;
    rep(node, 0, ns) {
        ac.get_link(node);
        maxval = max(maxval, ac.nodes[node].val);
    }
    
    MPMat coef(ns, ns);
    rep(from_node, 0, ns) {
        rep(ch, 0, ac.alpha) {
            int to_node = ac.go(from_node, ch);
            coef[to_node][from_node] = maxval - ac.nodes[to_node].val;
            clog << quoted(ac.get(from_node)) << " + " << char(ch + 'a') << " => " << quoted(ac.get(to_node)) << ' ' << (ac.nodes[to_node].val) << ' ';
            clog <<  " <- "<<  quoted(ac.get(ac.get_link(to_node))) << endl;
        }
    }
    clog << db(coef) << endl;
    
    auto tcoef = coef.pow(l);
    clog << db(tcoef) << endl;
    MPMat ans(ns, 1);
    ans[0][0] = 0;
    ans = tcoef * ans;
    clog << db(ans) << endl;
    ll final_ans = inf;
    rep(i, 0, ns) final_ans = min(final_ans, ans[i][0]);
    final_ans = maxval * l - final_ans;
    cout << final_ans;
    
    return 0;
}

// vim: foldmethod=marker