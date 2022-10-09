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

struct Edge {
    int to, cap, toll;
};
struct Query {
    int require, id;
};
struct AnsT {
    int max_e, min_toll;
    AnsT(int me, int mt): max_e(me), min_toll(mt) {}
    AnsT(): max_e(-1), min_toll(0) {}
    AnsT comb_toll(int other_toll) {
        AnsT ans = *this;
        ans.min_toll = max(ans.min_toll, other_toll);
        return ans;
    }
    friend print_op(AnsT) {
        return out << "(" << u.max_e << ", " << u.min_toll << ")";
    }
};

bool operator<(const AnsT& u, const AnsT& v) {
    if (u.max_e != v.max_e) return u.max_e < v.max_e;
    return u.min_toll < v.min_toll;
}
bool operator<=(const AnsT& u, const AnsT& v) {
    if (u.max_e == v.max_e) return u.min_toll <= v.min_toll;
    return u.max_e < v.max_e;
}

inline bool operator>(const AnsT& u, const AnsT& v) {
    return v < u;
}

const int maxn = 301010;
const int maxlogn = 18;
int n, q;
int e[maxn];
Query qr[maxn];
vector<Edge> gr[maxn];
AnsT ans[maxn];
vector<Query> queries[maxn];

struct CentroidDecomposor {
    bool mark[maxn];
    int sub_cnt[maxn];
    void dfs(int u, int p) {
        sub_cnt[u] = 1;
        for (auto& [v, _1, _2]: gr[u]) {
            if (v == p or mark[v]) continue;
            dfs(v, u);
            sub_cnt[u] += sub_cnt[v];
        }
    }
    int dfs2(int u, int p, int total) {
        for (auto& [v, _1, _2]: gr[u]) {
            if (v == p or mark[v]) continue;
            if (sub_cnt[v] * 2 > total) return dfs2(v, u, total);
        }
        return u;
    }
    
    int find_centroid(int u) {
        dfs(u, u);
        int cen = dfs2(u, u, sub_cnt[u]);
        mark[cen] = true;
        return cen;
    }
} dc;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    rep(i, 1, n + 1) cin >> e[i];
    rep(i, 0, n - 1) {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        gr[u].push_back(Edge{v, c, t});
        gr[v].push_back(Edge{u, c, t});
    }
    
    rep(i, 0, q) {
        int v, x;
        cin >> v >> x;
        queries[x].push_back(Query{v, i});
    }
    
    vector<int> toll_to_cen(n + 1), cap_to_cen(n + 1), par(n + 1);
    rep(node, 1, n + 1) while (!dc.mark[node]) {
        DB();
        int cen = dc.find_centroid(node);
        clog << db(node) << db(cen) << db(e[cen]) << endl;
        static map<int, AnsT> good;
        rep(_, 0, 2) {
            reverse(all(gr[cen]));
            DB();
            good.clear();
            good[INT_MAX] = AnsT(e[cen], 0);
            static stack<int> st;
            toll_to_cen[cen] = 0;
            cap_to_cen[cen] = INT_MAX;
            
            auto upd_st = [&](int u, int c, int t, int p) {
                if (dc.mark[u]) return ;
                toll_to_cen[u] = max(t, toll_to_cen[p]);
                cap_to_cen[u] = min(c, cap_to_cen[p]);
                par[u] = p;
                st.push(u);
            };
            
            par[cen] = cen;
            for (auto [adj, ac, at]: gr[cen]) {
                if (dc.mark[adj]) continue;
                upd_st(adj, ac, at, cen);
                
                while (sz(st)) {
                    DB();
                    int u = st.top();
                    clog << db(u) << db(toll_to_cen[u]) << db(cap_to_cen[u]) << endl;
                    st.pop();
                    for (auto [req, qid]: queries[u]) {
                        if (req > cap_to_cen[u]) continue;
                        auto it = good.lower_bound(req);
                        if (it != good.end()) {
                            clog << db(qid) << db(it->second) << db(toll_to_cen[u]) << endl;
                            clog << db(ans[qid]) << endl;
                            ans[qid] = max(ans[qid], it->second.comb_toll(toll_to_cen[u]));
                            clog << db(ans[qid]) << endl;
                        }
                    }
                    for (auto [v, c, t]: gr[u]) {
                        if (v == par[u] or dc.mark[v]) continue;
                        clog << db(v) << db(c) << db(t) << endl;
                        upd_st(v, c, t, u);
                    }
                }
                st.push(adj);
                while (st.size()) {
                    int u = st.top();
                    st.pop();
                    AnsT new_ans(e[u], toll_to_cen[u]);
                    auto it = good.upper_bound(cap_to_cen[u]);
                    if (it == good.end() or it->second <= new_ans) {
                        while (it != good.begin() and prev(it)->second <= new_ans) {
                            it = good.erase(prev(it));
                        }
                        auto& cur = good[cap_to_cen[u]];
                        cur = max(cur, new_ans);
                    }
                    for (auto [v, c, t]: gr[u]) {
                        if (v == par[u] or dc.mark[v]) continue;
                        clog << db(v) << db(c) << db(t) << endl;
                        st.push(v);
                    }
                }
            }
            clog << db(good) << endl;
            
        }
        clog << db(good) << endl;
        for (auto [req, qid]: queries[cen]) {
            auto it = good.lower_bound(req);
            if (it != good.end()) {
                clog << db(qid) << db(it->second) << endl;
                clog << db(ans[qid]) << endl;
                ans[qid] = max(ans[qid], it->second);
                clog << db(ans[qid]) << endl;
            }
        }
    }
    
    rep(i, 0, q) {
        cout << ans[i].max_e << ' ' << ans[i].min_toll << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker