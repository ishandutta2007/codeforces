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

const int maxbit = 22;

struct Trie {
    Trie* child[2];
    int level;
    int lazy;
    int cnt;
    
    Trie(int lv): child{0}, level(lv), lazy(0), cnt(0) {}
    ~Trie() {
        if (child[0]) delete child[0];
        if (child[1]) delete child[1];
    }
};

void push(Trie* root) {
    if (!root) return ;
    clog << db(root->lazy) << endl;
    if (root->level == 0) return ;
    if ((root->lazy >> (root->level - 1)) & 1) {
        swap(root->child[0], root->child[1]);
        root->lazy ^= 1 << root->level;
    }
    if (root->child[0]) root->child[0]->lazy ^= root->lazy;
    if (root->child[1]) root->child[1]->lazy ^= root->lazy;
    root->lazy = 0;
}

void add(Trie* root, int num) {
    for (int i = maxbit; i--; ) {
        ++root->cnt;
        int b = (num >> i) & 1;
        if (!root->child[b]) root->child[b] = new Trie(i);
        root = root->child[b];
    }
    ++root->cnt;
}

int mex(Trie* root) {
    int ans = 0;
    for (int i = maxbit; i--; ) {
        DB();
        push(root);
        if (!root->child[0]) {
            return ans;
        }
        clog << db(root->child[0]->cnt) << db(1 << i) << endl;
        if (root->child[0]->cnt != (1 << i)) {
            root = root->child[0];
        } else {
            root = root->child[1];
            ans += 1 << i;
            if (!root) return ans;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    set<int> has;
    Trie* root = new Trie(maxbit);
    rep(i, 0, n) {
        int a;
        cin >> a;
        if (has.count(a)) continue;
        has.insert(a);
        clog << db(a) << endl;
        add(root, a);
    }
    while (m--) {
        DB();
        int x;
        cin >> x;
        root->lazy ^= x;
        auto ans = mex(root);
        cout << ans << '\n';
    }
    delete root;
    
    return 0;
}

// vim: foldmethod=marker