#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
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

const int max_bit = 30;
struct Trie {
    Trie *child[2];
    int size;
    Trie(): child{0}, size(0) {}
    ~Trie() {
        if (child[0]) delete child[0];
        if (child[1]) delete child[1];
    }
};

void add(Trie* root, int num) {
    for (int i = max_bit; i--; ) {
        ++root->size;
        int bit = (num >> i) & 1;
        if (!root->child[bit])
            root->child[bit] = new Trie();
        root = root->child[bit];
    }
    ++root->size;
}

int cal_ans(Trie* root) {
    DB(root->size);
    if (!root) return 0;
    if (!root->child[0] and !root->child[1]) return 0;
    if (root->size == 1) return 0;
    if (!root->child[0]) return cal_ans(root->child[1]);
    if (!root->child[1]) return cal_ans(root->child[0]);
    
    int ans = min(
            cal_ans(root->child[0]) + root->child[1]->size - 1, 
            cal_ans(root->child[1]) + root->child[0]->size - 1
            );
    clog << db(ans) << endl;
    clog << db(root->child[1]->size) << endl;
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    Trie root;
    rep(i, n) {
        int u; cin >> u;
        add(&root, u);
    }
    int ans = cal_ans(&root);
    cout << ans;
    
    
    return 0;
}

// vim: foldmethod=marker