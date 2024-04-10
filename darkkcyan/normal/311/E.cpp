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

const ll inf = (ll)1e15;

struct MaxFlow {
    struct Edge {
        int to, eid;
    };
    
    int n;
    vector<ll> cap, flow;
    vector<vector<Edge>> gr;
    MaxFlow(int n_): n(n_), gr(n) {}
    
    void add_edge(int from, int to, ll cur_cap) {
        clog << from << ' ' << to << ' ' << cur_cap << endl;
        gr[from].push_back({to, sz(cap)});
        cap.push_back(cur_cap); flow.push_back(0);
        gr[to].push_back({from, sz(cap)});
        cap.push_back(0); flow.push_back(0);
    }
    
    vector<ll> dist;
    bool bfs(int src, int dst) {
        dist.assign(n, inf);
        queue<int> qu;
        for (qu.push(src), dist[src] = 0; qu.size(); qu.pop()) {
            int u = qu.front();
            for (auto [v, eid]: gr[u]) {
                if (flow[eid] == cap[eid]) continue;
                if (dist[v] != inf) continue;
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
        return dist[dst] != inf;
    }
    
    vector<int> it;
    ll inc_flow(int u, int dst, ll cur_flow = inf) {
        if (cur_flow == 0) return 0;
        if (u == dst) {
            clog << db(u) << db(cur_flow) << endl;
            return cur_flow;
        }
        for (int& i = it[u]; i < sz(gr[u]); ++i) {
            auto [v, eid] = gr[u][i];
            if (flow[eid] == cap[eid]) continue;
            if (dist[u] + 1 != dist[v]) continue;
            ll inced_flow = inc_flow(v, dst, min(cur_flow, cap[eid] - flow[eid]));
            if (!inced_flow) continue;
            clog << db(u) << endl;
            flow[eid] += inced_flow;
            flow[eid^ 1] -= inced_flow;
            return inced_flow;
        }
        return 0;
    }
    
    ll max_flow_question_mark(int src, int dst) {
        DB();
        ll ans = 0;
        while (bfs(src, dst)) {
            DB();
            clog << db(dist) << endl;
            it.assign(n, 0);
            do {
                DB();
                ll inc = inc_flow(src, dst);
                if (inc == 0) break;
                clog << db(inc) << endl;
                ans += inc;
            } while (1);
        }
        return ans;
    }
};

const int maxn = (int)1e4 + 100;
const int maxm = (int)2e3 + 100;

struct Dog {
    int s;
    ll v;
};

struct RichKid {
    int s;
    ll w;
    vector<int> target;
    bool friendly;
};

int n, m;
ll g;
Dog dogs[maxn];
RichKid rk[maxm];

ll solve() {
    ll total_money = 0;
    // rep(i, 0, n) total_money += dogs[i].v; 
    rep(i, 0, m) total_money += rk[i].w;
    
    clog << db(total_money) << endl;
    MaxFlow mf(n + m + 2);
    int s = mf.n - 2, t = mf.n - 1;
    
    rep(i, 0, n) {
        if (dogs[i].s) {
            mf.add_edge(i, t, dogs[i].v);
        } else {
            mf.add_edge(s, i, dogs[i].v);
        }
    }
    
    rep(i, 0, m) {
        int u = i + n;
        ll true_w = rk[i].w + (rk[i].friendly ? g : 0);
        if (rk[i].s) {
            mf.add_edge(u, t, true_w);
            for (auto x: rk[i].target) mf.add_edge(x, u, inf);
        } else {
            mf.add_edge(s, u, true_w);
            for (auto x: rk[i].target) mf.add_edge(u, x, inf);
        }
    }
    
    auto ans = mf.max_flow_question_mark(s, t);
    return total_money - ans;
}

pair<ll, int> brute() {
    DB();
    pair<ll, int> ans {LLONG_MIN, 0};
    rep(mask, 0, (1 << n)) {
        DB();
        clog << db(mask) << endl;
        ll cur_ans = 0;
        rep(i, 0, n) {
            if (dogs[i].s != ((mask >> i) & 1)) {
                cur_ans -= dogs[i].v;
            }
        }
        
        clog << db(cur_ans) << endl;
        
        rep(i, 0, m) {
            bool ok = true;
            for (auto x: rk[i].target) {
                if (((mask >> x) & 1) != rk[i].s) {
                    ok = false;
                    break;
                }
            }
            clog << db(i) << db(ok) << endl;
            if (ok) cur_ans += rk[i].w;
            else if (rk[i].friendly) cur_ans -= g;
        }
        ans = max(ans, {cur_ans, mask});
        clog << db(mask) << db(cur_ans) << endl;
    }
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void gen_test() {
    ofstream test("main.inp");
    n = rand() % 3 + 1;
    m = rand() % 3 + 1;
    g = rand() % 5;
    test << n << ' ' << m << ' ' << g << endl;
    rep(i, 0, n) {
        dogs[i].s = rand() % 2;
        test << dogs[i].s << ' ';
    }
    test << endl;
    rep(i, 0, n) {
        dogs[i].v = rand() % 5;
        test << dogs[i].v << ' ';
    }
    test << endl;
    vector<int> ids(n);
    rep(i, 0, n) ids[i] = i;
    rep(i, 0, m) {
        rk[i].s = rand() % 2;
        rk[i].w = rand() % 5;
        rk[i].target.resize(rand() % n + 1);
        shuffle(all(ids), rng);
        rep(f, 0, sz(rk[i].target)) rk[i].target[f] = ids[f];
        rk[i].friendly = rand() % 2;
        
        test << rk[i].s << ' ' << rk[i].w << ' ' << sz(rk[i].target) << ' ';
        for (auto x: rk[i].target) test << x + 1 << ' ';
        test << rk[i].friendly << endl;
    }
}

void check() {
    for (int testcase = 0; ; ++testcase) {
        cout << db(testcase) << endl;
        gen_test();
        auto exp = brute();
        auto ans = solve();
        if (exp.first == ans) {
            cout << "OK" << endl;
            continue;
        }
        cout << "WA" << endl;
        cout << db(exp) << db(ans) << endl;
        exit(0);
    }
}

int main() {
    // check();   
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> g;
    rep(i, 0, n) {
        cin >> dogs[i].s;
    }
    rep(i, 0, n) {
        cin >> dogs[i].v;
    }
    rep(i, 0, m) {
        int k;
        cin >> rk[i].s >> rk[i].w >> k;
        rk[i].target.resize(k);
        for (auto& x: rk[i].target) {
            cin >> x;
            --x;
        }
        cin >> rk[i].friendly;
    }
    
    cout << solve() << endl;
#ifdef LOCAL
    auto [exp, ms] = brute();
    cout << exp << endl;
    rep(i, 0, n) {
        cout << ((ms >> i) & 1);
    }
    cout << endl;
#endif
    
    return 0;
}

// vim: foldmethod=marker