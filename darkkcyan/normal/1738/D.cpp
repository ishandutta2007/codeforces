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
 
vector<int> gen_b(int k, const vector<int>& a) {
    vector<int> b(sz(a));
    rep(i, 1, sz(a)) {
        if (a[i] <= k) {
            b[a[i]] = sz(a);
            for (int j = i - 1; j > 0; --j) {
                if (a[j] > k) {
                    b[a[i]] = a[j];
                    break;
                }
            }
        } else {
            b[a[i]] = 0;
            for (int j = i - 1; j > 0; --j) {
                if (a[j] <= k) {
                    b[a[i]] = a[j];
                    break;
                }
            }
        }
    }
    return b;
}

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}
void gen() {
    ofstream inp("main.inp");
    int n = rand(1, 30);
    int k = rand(0, n);
    vector<int> a(n + 1);
    rep(i, 1, n + 1) a[i] = i;
    shuffle(a.begin() + 1, a.end(), rng);
    auto b = gen_b(k, a);
    inp << 1 << '\n';
    inp << n << endl;
    rep(i, 1, n + 1) inp << b[i] << ' ';
    inp << endl;
    inp.close();
    cout << k << ' ' << db(a) << endl;
    if (system("./main 1")) {
        cout << "RE" << endl;
        exit(0);
    }
    
    {
        ifstream out("main.out");
        int tk;
        out >> tk;
        vector<int> ta(n + 1);
        rep(i, 1, n + 1) out >> ta[i];
        auto nb = gen_b(tk, ta);
        cout << db(ta) << db(nb) << endl;
        assert(nb == b);
    }
    cout << "OK" << endl;
}

int main(int argc, char** argv) {
#ifdef LOCAL
    // if (argc == 1) while (1) gen();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        int n;
        cin >> n;
        vector<int> b(n + 1);
        rep(i, 1, n + 1) {
            cin >> b[i];
        }
        
        int k = 0;
        while (k + 1 <= n and b[k + 1] > k + 1) ++k;
        
        cout << k << '\n';
        
        vector<vector<int>> gr(n + 2);
        vector<int> in_deg(n + 2);
        rep(i, 1, n + 1) {
            gr[b[i]].push_back(i);
            ++in_deg[i];
        }
        
        min_pq<pair<int, int>> qu;
        rep(i, 0, n + 2) if (in_deg[i] == 0) qu.emplace(sz(gr[i]), i);
        
        vector<int> a = {0};
        
        for (; qu.size(); ) {
            auto [du, u] = qu.top();
            qu.pop();
            if (1 <= u and u <= n) {
                a.push_back(u);
            }
            for (auto v: gr[u]) {
                --in_deg[v];
                if (in_deg[v] == 0) qu.emplace(sz(gr[v]), v);
            }
        }
        rep(i, 1, n + 1) cout << a[i] << ' ';
        clog << db(a) << endl;
        clog << db(k) << endl;
        clog << db(b) << endl;
        clog << db(gen_b(k, a)) << endl;
        cout << '\n';
    }
    
    return 0;
}