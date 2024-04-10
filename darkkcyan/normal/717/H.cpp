#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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

const int maxn = 50101;
const int maxm = 101010;
const int maxt = 1010101;

int n, m;
vector<int> gr[maxn];
vector<int> team[maxn];

bool vis[maxn];
bool trainer_side[maxn];
bool team_side[maxn];
int chosen_team[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    int max_t = 0;
    rep(i, 1, n + 1) {
        int l;
        cin >> l;
        team[i].resize(l);
        for (auto& x: team[i]) {
             cin >> x;
             max_t = max(max_t, x);
        }
    }
    
    queue<int> qu;
    fill_n(trainer_side, n + 1, -1);
    rep(s, 1, n + 1) {
        if (vis[s]) continue;
        vis[s] = 1;
        for (qu.push(s); qu.size(); qu.pop()) {
            int u = qu.front();
            int cnt[2] = {0, 0};
            for (auto v: gr[u]) {
                if (vis[v]) {
                    cnt[trainer_side[v]]++;
                } else {
                    qu.push(v);
                    vis[v] = true;
                }
            }
            if (cnt[0] >= cnt[1]) trainer_side[u] = 1;
            else trainer_side[u] = 0;
        }
    }
    
    vector<int> teams;
    rep(i, 1, max_t + 1) teams.push_back(i);
    
    mt19937 rng;
    rng.seed((ll)main);
    
    while (true) {
        shuffle(all(teams), rng);
        rep(i, 0, sz(teams)) {
            team_side[teams[i]] = i < sz(teams) / 2;
        }
        bool ok = true;
        rep(u, 1, n + 1) {
            chosen_team[u] = -1;
            for (auto ct: team[u]) {
                if (team_side[ct] == trainer_side[u]) {
                    chosen_team[u] = ct;
                    break;
                }
            }
            if (chosen_team[u] == -1) {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    
    rep(i, 1, n + 1) cout << chosen_team[i] << ' ';
    cout << '\n';
    rep(i, 1, max_t + 1) cout << team_side[i] + 1 << ' ';
    
    
    return 0;
}

// vim: foldmethod=marker