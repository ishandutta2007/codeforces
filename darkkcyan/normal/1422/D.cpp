// #define multitest 
// #define testing 
// #define print_brute 

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

using ans_type = llong;

const int maxm = 101010;
int n, m;
llong sr, sc, fr, fc;
pair<llong, llong> cross[maxm];
void read() {
    cin >> n >> m;
    cin >> sr >> sc >> fr >> fc;
    rep(i, m) cin >> cross[i].first >> cross[i].second;
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

ans_type solve() {
    vector<llong> r_vals, c_vals;
    r_vals.push_back(sr);
    c_vals.push_back(sc);
    rep(i, m) {
        r_vals.push_back(cross[i].first);
        c_vals.push_back(cross[i].second);
    }
    
    sort(r_vals.begin(), r_vals.end());
    sort(c_vals.begin(), c_vals.end());
    r_vals.erase(unique(r_vals.begin(), r_vals.end()), r_vals.end());
    c_vals.erase(unique(c_vals.begin(), c_vals.end()), c_vals.end());
    
    vector<vector<pair<int, llong>>> gr(len(r_vals) + len(c_vals));
    
    auto pos = [&](vector<llong>& vals, llong val) {
        return (int)(lower_bound(vals.begin(), vals.end(), val) - vals.begin());
    };
    
    auto add_cross_edge = [&](llong r, llong c, llong cost) {
        int ir = pos(r_vals, r);
        int ic = pos(c_vals, c) + len(r_vals);
        gr[ir].emplace_back(ic, cost);
        gr[ic].emplace_back(ir, cost);
    };
    
    add_cross_edge(sr, sc, 0);
    rep(i, m) {
        add_cross_edge(cross[i].first, cross[i].second, 0);
    }
    
    rep(u, len(r_vals) - 1) {
        int v = u + 1;
        llong cost = r_vals[v] - r_vals[u];
        gr[u].emplace_back(v, cost);
        gr[v].emplace_back(u, cost);
    }
    
    rep(u, len(c_vals) - 1) {
        int v = u + 1;
        llong cost = c_vals[v] - c_vals[u];
        gr[u + len(r_vals)].emplace_back(v + len(r_vals), cost);
        gr[v + len(r_vals)].emplace_back(u + len(r_vals), cost);
    }
    
    vector<llong> dist(len(gr), LLONG_MAX);
    using pli = pair<llong, int>;
    priority_queue<pli, vector<pli>, greater<pli>> prio;
    
    int root = pos(r_vals, sr);
    dist[root] = 0;
    prio.emplace(0, root);
    while (len(prio)) {
        auto [cur_dist, u] = prio.top();
        prio.pop();
        if (cur_dist > dist[u]) continue;
        if (u >= len(r_vals)) {
            clog << "col " << c_vals[u - len(r_vals)] << db(cur_dist) << endl;
        } else {
            clog << "row " << r_vals[u] << db(cur_dist) << endl;
        }
        for (auto [v, cost]: gr[u]) {
            llong new_dist = cur_dist + cost;
            if (new_dist >= dist[v]) continue;
            dist[v] = new_dist;
            prio.emplace(new_dist, v);
        }
    }
    
    llong ans = abs(fr - sr) + abs(fc - sc);
    
    rep(i, m) {
        llong d = dist[pos(r_vals, cross[i].first)];
        d += abs(fr - cross[i].first) + abs(fc - cross[i].second);
        ans = min(ans, d);
    }
    
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
#endif
    }
    return 0;
}
#else
void gen_test() {
    ofstream inp("main.inp");
    
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test();
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