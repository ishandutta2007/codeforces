// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

/*{{{*/
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int debug = 1;
#define DB(...) stringstream CONCAT(ss, __LINE__); CONCAT(ss, __LINE__) << __VA_ARGS__; debug_block CONCAT(dbbl, __LINE__)(CONCAT(ss, __LINE__).str())
#else
int debug = 0;
#define DB(...)
#endif
int __db_level = 0;
#define clog if (debug) cerr << string(__db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

#define maxn 1024
#define maxq 101010
int n, m, q;

struct operation {
    int type;
    int i, j;
    operation() {}
    operation(int t, int i_, int j_): type(t), i(i_), j(j_) {}
};

vector<pair<int, operation>> gr[maxq];
int ans[maxq];

bitset<maxn> shelf[maxn];
bitset<maxn> mask;
llong cur_ans = 0;
void dfs(int u) {
    ans[u] = (int)cur_ans;
    for (auto [v, op]: gr[u]) {
        switch (op.type) {
            case 1: 
            case 2: {
                int old_val = shelf[op.i][op.j];
                int new_val = op.type == 1 ? 1 : 0;
                cur_ans += new_val - old_val;
                shelf[op.i][op.j] = new_val;
                dfs(v);
                shelf[op.i][op.j] = old_val;
                cur_ans += old_val - new_val;
                break;
            }
            case 3: {
                cur_ans -= shelf[op.i].count();
                shelf[op.i] ^= mask;
                cur_ans += shelf[op.i].count();
                dfs(v);
                cur_ans -= shelf[op.i].count();
                shelf[op.i] ^= mask;
                cur_ans += shelf[op.i].count();
                break;
            }
            case 4: {
                dfs(v);
                break;
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    rep(i, m) mask[i] = 1;
    rep1(i, q) {
        operation cur_op; cin >> cur_op.type;
        int parent = i - 1;
        if (cur_op.type <= 2) cin >> cur_op.i >> cur_op.j;
        else if (cur_op.type == 3) cin >> cur_op.i;
        else cin >> parent;
        --cur_op.i; --cur_op.j;
        gr[parent].emplace_back(i, cur_op);
    }

    dfs(0);
    rep1(i, q) cout << ans[i] << '\n';

    return 0;
}