#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const int maxn = 301010;
const int maxm = 22;

int n, m;
vector<int> add[maxn], rem[maxn];
vector<int> gr[maxn];

int comp_id[maxn], id[maxn];
vector<vector<vector<int>>> cnt;

void make_comp(int start) {
    if (len(gr[start]) == 0) return ;
    if (id[start] != -1) return ;
    
    cnt.emplace_back();
    auto& cur_cnt = cnt.back();
    
    queue<int> qu;
    vector<int> nodes(1, start);
    id[start] = 0;
    comp_id[start] = len(cnt) - 1;
    
    for (qu.push(start); qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto v: gr[u]) {
            if (id[v] != -1) continue;
            id[v] = len(nodes);
            comp_id[v] = len(cnt) - 1;
            nodes.push_back(v);
            qu.push(v);
        }
    }
    
    vector<int> adj_mask(len(nodes));
    rep(i, len(nodes)) {
        auto& cur_mask = adj_mask[i];
        for (auto v: gr[nodes[i]]) cur_mask ^= 1 << id[v];
    }
    
    cur_cnt.assign(len(nodes), vector<int>(1 << len(nodes)));
    int max_mask = 0;
    function<void(int, int)> trans = [&](int u, int cur_mask) {
        if (u == len(nodes)) {
            cur_cnt[__builtin_popcount(cur_mask)][cur_mask] = 1;
            max_mask = max(max_mask, __builtin_popcount(cur_mask));
            return ;
        }
        
        if (!(adj_mask[u] & cur_mask)) {
            trans(u + 1, cur_mask ^ (1 << u));
        }
        trans(u + 1, cur_mask);
    };
    trans(0, 0);
    
    cur_cnt.resize(max_mask + 1);
    rep(x, len(cur_cnt)) {
        auto& sos = cur_cnt[x];
        rep(i, len(nodes)) rep(mask, len(sos))
            if ((mask >> i) & 1)
                sos[mask] += sos[mask ^ (1 << i)];
    }
    deb(cur_cnt);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep1(i, n) {
        int l, r; cin >> l >> r;
        add[l].push_back(i);
        rem[r + 1].push_back(i);
    }
    
    rep(i, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    fill(id, id + n + 10, -1);
    rep1(i, n) make_comp(i);
    deb($v(id + 1, id + n + 1));
    
    const llong mod = (llong)998244353;
    
    vector<llong> fac(n + 1, 0ll), ifac(n + 1, 1ll);
    fac[0] = 1;
    rep1(i, n) fac[i] = fac[i - 1] * i % mod;
    
    rep1(i, n) {
        llong exp = mod - 2;
        llong base = fac[i];
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) (ifac[i] *= base) %= mod;
            (base *= base) %= mod;
        }
    }
    auto choose = [&](int x, int y) { return x >= y && y >= 0? fac[x] * ifac[y] % mod * ifac[x - y] % mod : 0ll; };
    
    vector<int> comp_mask(len(cnt));
    
    llong ans = 0;
    
    int rest = 0;
    rep1(i, n) {
        DB(i);
        for (auto x: add[i]) {
            if (id[x] != -1) comp_mask[comp_id[x]] ^= 1 << id[x];
            else ++rest ;
        }
        for (auto x: rem[i]) {
            if (id[x] != -1) comp_mask[comp_id[x]] ^= 1 << id[x];
            else  --rest;
        }
        deb(comp_mask);
        vector<llong> cur_cnt(1, 1);
        rep(comp, len(cnt)) {
            vector<llong> cc(len(cnt[comp]));
            rep(f, len(cnt[comp])) cc[f] = cnt[comp][f][comp_mask[comp]];
            deb(cc);
            
            vector<llong> new_cnt(len(cur_cnt) + len(cc) - 1);
            rep(u, len(cur_cnt)) {
                rep(v, len(cc))
                    (new_cnt[u + v] += cur_cnt[u] * cc[v]) %= mod;
            }
            cur_cnt = new_cnt;
        }
        deb(cur_cnt);
        
        llong cur_ans = 0;
        rep(f, len(cur_cnt)) {
            (cur_ans += 1ll * cur_cnt[f] * choose(rest, i - f) % mod) %= mod;
        }
        (ans += cur_ans) %= mod;
    }
    cout << ans;
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker