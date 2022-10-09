#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const int lim = 450;
const int maxn = 201010;
int n;
vector<vector<int>> elms, in_set;

bool mark[maxn];
pair<int, int> solve() {
    fill(mark, mark + max(sz(elms), sz(in_set)), 0);
    rep(val, 0, sz(in_set)) {
        if (sz(in_set[val]) < lim) continue;
        for (auto x: in_set[val]) mark[x] = 1;
        rep(oval, 0, sz(in_set)) {
            if (oval == val) continue;
            vector<int> match;
            for (auto x: in_set[oval]) {
                if (mark[x]) {
                    match.push_back(x);
                    if (sz(match) == 2) {
                        return {match[0], match[1]};
                    }
                }
            }
        }
        
        for (auto x: in_set[val]) mark[x] = 0;
    }
    
    rep(i, 0, n) {
        for (auto val: elms[i]) {
            if (sz(in_set[val]) >= lim) continue;
            for (auto se: in_set[val]) {
                if (se == i) continue;
                if (mark[se]) {
                    return {se, i};
                }
                mark[se] = true;
            }
        }
        
        for (auto val: elms[i]) {
            if (sz(in_set[val]) >= lim) continue;
            for (auto se: in_set[val]) mark[se] = 0;
        }
    }
    
    return {-1, -1};
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n;
        elms.assign(n, {});
        vector<int> values;
        rep(i, 0, n) {
            int k; cin >> k;
            elms[i].resize(k);
            for (auto& x: elms[i]) {
                cin >> x;
                values.push_back(x);
            }
        }
        sort(all(values));
        values.erase(unique(all(values)), values.end());
        in_set.assign(sz(values), {});
        rep(i, 0, n) {
            for (auto& x: elms[i]) {
                x = (int)(lower_bound(all(values), x) - values.begin());
                in_set[x].push_back(i);
            }
        }
        
        auto [u, v] = solve();
        if (u == -1) cout << "-1\n";
        else cout << u + 1 << ' ' << v + 1 << '\n';
    }
        
    return 0;
}

// vim: foldmethod=marker