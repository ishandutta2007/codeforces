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
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
            --a[i];
        }
        
        vector<vector<int>> val(n);
        rep(i, 0, n) {
            assert(a[i] != i);
            val[a[i]].push_back(i);
        }
        
        vector<int> ans(n, -1);
        vector<bool> used(n);
        int matched = 0;
        rep(i, 0, n) {
            if (!sz(val[i])) continue;
            ++matched;
            ans[val[i].back()] = i;
            used[i] = true;
            val[i].pop_back();
        }
        int cur = 0;
        vector<int> unmatched;
        rep(i, 0, n) {
            if (ans[i] != -1) continue;
            while (cur < n and used[cur]) ++cur;
            assert(cur < n);
            ans[i] = cur;
            used[cur] = true;
            unmatched.push_back(i);
        }
        vector<int> coincide;
        for (auto i: unmatched) {
            if (ans[i] == i) coincide.push_back(i);
        }
        if (sz(coincide)) {
            if (sz(coincide) > 1) {
                vector<int> old_val;
                for (auto x: coincide) old_val.push_back(ans[x]);
                rotate(old_val.begin(), old_val.begin() + 1, old_val.end());
                rep(i, 0, sz(coincide)) ans[coincide[i]] = old_val[i];
            } else if (sz(unmatched) > sz(coincide)) {
                int u = coincide[0];
                int v = unmatched[0] == u ? unmatched[1] : unmatched[0];
                swap(ans[u], ans[v]);
            } else {
                int u = coincide[0];
                int v = 0;
                while (v < n and ans[v] != a[u]) ++v;
                assert(v < n);
                swap(ans[u], ans[v]);
            }
        }
        cout << matched << '\n';
        for (auto i: ans) cout << i + 1 << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker