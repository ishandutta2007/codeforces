// #define multitest 
#ifdef LOCAL
#define testing     
#define print_brute 
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

using ans_type = pair<int, vector<bool>>;

const int maxn = 501010;
int n, m;
vector<pair<int, int>> rgr[maxn];
void read() {
    cin >> n >> m;
    rep1(i, n) rgr[i].clear();
    rep(i, m) {
        int u, v, c; cin >> u >> v >> c;
        // gr[u].emplace_back(v, c); 
        rgr[v].emplace_back(u, c);
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans.first << '\n';
    rep1(i, n) cout << ans.second[i];
}

ans_type solve() {
    vector<bool> color (n + 1);
    vector<bool> color_assigned (n + 1);
    vector<int> dist(n + 1, -1);
    queue<int> qu;
    
    for (qu.push(n), dist[n] = 0; len(qu); qu.pop()) {
        int u = qu.front();
        for (auto [v, c]: rgr[u]) {
            if (dist[v] != -1) continue;
            if (color_assigned[v]) {
                if (color[v] != c) continue;
                dist[v] = dist[u] + 1;
                qu.push(v);
            } else {
                color_assigned[v] = true;
                color[v] = !c;
            }
        }
    }
    return {dist[1], color};
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
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;
    m = min(m, n * (n - 1) * 2);
    set<tuple<int, int, int>> edges;
    rep1(i, n) rgr[i].clear();
    
    inp << n << ' ' <<  m << '\n';
    rep(i, m) {
        int u, v, c;
        do {
            u = rand() % n + 1;
            do {
                v = rand() % n + 1;
            } while (v == u);
            c = rand() & 1;
        } while (edges.count({u, v, c}));
        edges.emplace(u, v, c);
        rgr[v].emplace_back(u, c);
        inp << u << ' ' << v << ' ' << c << '\n';
    }
}

int get_dist(const vector<bool>&) ;
int main(void) {
    rep1(testcase, 10000) {
        cout << "gentest" << endl;
        gen_test(testcase);
        cout << "solving" << endl;
        auto ans = solve();
        cout << "brutefocring" << endl;
        auto br = brute();
        bool check = ([&] {
            if (ans.first != br.first) {
                return false;
            }
            int x = get_dist(ans.second);
            if (x != ans.first) return false;
            return true;
        })();
        
        if (!check) {
            cout << "FAILED" << endl;
            print_ans(cout, ans);
            cout << "======";
            print_ans(cout, br);
            return 1;
        }
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

int get_dist(const vector<bool>& color) {
    vector<int> dist(n + 1, -1);
    queue<int> qu;
    for (qu.push(n), dist[n] = 0; len(qu); qu.pop()) {
        int u = qu.front();
        for (auto [v, c]: rgr[u]) {
            if (color[v] != c) continue;
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            qu.push(v);
        }
    }
    return dist[1];
}

ans_type brute() {
    vector<bool> color(n + 1, 0);
    ans_type ans(0, color);
    while (true) {
        int cur_ans = get_dist(color);
        if (cur_ans == -1) return {cur_ans, color};
        ans = max(ans, {cur_ans, color});
        int first0 = 1;
        while (first0 <= n and color[first0] == 1) color[first0++] = 0;
        if (first0 == n + 1) break;
        color[first0] = 1;
    }
    return ans;
}

// vim: foldmethod=marker