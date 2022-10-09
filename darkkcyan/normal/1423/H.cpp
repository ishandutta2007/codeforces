// #define multitest 
#ifdef LOCAL
// #define testing 
// #define print_brute 
#endif

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

using ans_type = vector<int>;

struct Query {
    int type;
    int x, y;
};

const int maxq = 501010;
int n, q, k;
Query qr[maxq];
void read() {
    cin >> n >> q >> k;
    rep(i, q) {
        cin >> qr[i].type;
        if (qr[i].type == 1) cin >> qr[i].x >> qr[i].y;
        else if (qr[i].type == 2) cin >> qr[i].x;
    };
}

void print_ans(ostream& cout, const ans_type& ans) {
    for (auto i: ans) cout << i << '\n';
}

ans_type solve() {
    struct Dsu {
        vector<int> link;
        Dsu(int n_): link(n_, -1) {}
        vector<pair<int, int>> changes;
        
        int find_set(int u) {
            if (link[u] < 0) return u;
            changes.emplace_back(u, link[u]);
            return link[u] = find_set(link[u]);
        }
        
        bool join(int u, int v) {
            u = find_set(u);
            v = find_set(v);
            if (u == v) return false;
            if (-link[u] < -link[v]) swap(u, v);
            changes.emplace_back(u, link[u]);
            changes.emplace_back(v, link[v]);
            link[u] += link[v];
            link[v] = u;
            return true;
        }
        
        void mark() {
            changes.emplace_back(-1, -1);
        }
        
        void rollback() {
            while (len(changes) and changes.back().first != -1) {
                auto [u, old_link] = changes.back();
                link[u] = old_link;
                changes.pop_back();
            }
            if (len(changes) and changes.back().first == -1)
                changes.pop_back();
        }
    };
    
    struct segtree {
        vector<vector<pair<int, int>>> it;
        int sz;
        segtree(int sz_): it(4 * sz_), sz(sz_) {}
        
        void add_int(int from, int to, const pair<int, int>& what, int i, int l, int r) {
            if (from > r or l > to) return ;
            if (from <= l and r <= to) {
                clog << db(i) << db(l) << db(r) << db(what) << endl;
                it[i].push_back(what);
                return ;
            }
            int mid = (l + r) / 2;
            add_int(from, to, what, i * 2, l, mid);
            add_int(from, to, what, i * 2 + 1, mid + 1, r);
        }
        
        void add_int(int l, int r, const pair<int, int>& what) {
            add_int(l, r, what, 1, 0, sz - 1);
        }
        
        void dfs_solve(Dsu& dsu, vector<int>& ans, int i, int l, int r) {
            DB(db(i) << db(l) << db(r));
            dsu.mark();
            for (auto [x, y]: it[i]) {
                clog << "joining " << x << ' ' << y << endl;
                dsu.join(x, y);
            }
            if (l == r) {
                if (qr[l].type == 2) {
                    ans.push_back(-dsu.link[dsu.find_set(qr[l].x)]);
                }
            } else {
                int mid = (l + r) / 2;
                dfs_solve(dsu, ans, i * 2, l, mid);
                dfs_solve(dsu, ans, i * 2 + 1, mid + 1, r);
            }
            dsu.rollback();
        }
        
        void dfs_solve(Dsu& dsu, vector<int>& ans) {
            dfs_solve(dsu, ans, 1, 0, sz - 1);
        }
    };
    
    Dsu dsu(n + 1);
    segtree st(q);
    
    vector<int> day_pos;
    day_pos.emplace_back(0);
    rep(i, q) if (qr[i].type == 3) {
        day_pos.push_back(i);
    }
    
    clog << db(day_pos) << endl;
    
    int cur_day = 0;
    rep(i, q) {
        if (qr[i].type == 3) ++cur_day;
        else if (qr[i].type == 1) {
            int nxt_day = cur_day + k;
            int nxt_day_pos = nxt_day < len(day_pos) ? day_pos[nxt_day] - 1 : q;
            clog << db(i) << db(nxt_day_pos) << endl;
            st.add_int(i, nxt_day_pos, {qr[i].x, qr[i].y});
        }
    }
    
    vector<int> ans;
    st.dfs_solve(dsu, ans);
    
    return ans;
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
ans_type brute();
#ifndef testing
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = 1;
#ifdef multitest
    cin >> ntest;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        auto ans = solve();
        print_ans(cout, ans);
#ifdef print_brute
        auto br = brute();
        print_ans(cout << endl << "====" << endl, br);
        cout << endl << "==============" << endl;
#endif
    }
    return 0;
}
#else
void gen_test(int cur_test) {
    ofstream inp("main.inp");
    
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        auto ans = solve();
        auto br = brute();
        assert(ans == br);
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    return ans_type();
}

// vim: foldmethod=marker