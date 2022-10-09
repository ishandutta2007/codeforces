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

struct BIT2D {
    vector<vector<pair<int, int>>> data;
    BIT2D(int n, int m, const pair<int, int>& def_val): data(n + 1, vector<pair<int, int>>(m + 1, def_val)) {}
    
    pair<int, int> get(int i, int f) {
        pair<int, int> ans = {0, -1};
        for (int pi = i + 1; pi > 0; pi -= pi & -pi)
        for (int pf = f + 1; pf > 0; pf -= pf & -pf) 
            ans = max(ans, data[pi][pf]);
        return ans;
    }
    void upd(int i, int f, pair<int, int> val) {
        for (int pi = i + 1; pi < sz(data); pi += pi & -pi)
        for (int pf = f + 1; pf < sz(data[pi]); pf += pf & -pf)
            data[pi][pf] = max(data[pi][pf], val);
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> arr[2];
    map<int, int> val;
    rep(id, 0, 2) {
        int n;
        cin >> n;
        arr[id].resize(n);
        for (auto& x: arr[id]) {
            cin >> x;
            val[x] |= 1 << id;
        }
    }
    vector<int> sval;
    for (auto [v, m]: val) {
        if (m == 3) sval.push_back(v);
    }
    
    BIT2D bit(sz(arr[1]), sz(sval), {0, -1});
    vector<pair<int, int>> trace(sz(arr[0]), {0, -1});
    rep(i, 0, sz(arr[0])) {
        int vp = (int)(lower_bound(all(sval), arr[0][i]) - sval.begin());
        if (vp == sz(sval) or sval[vp] != arr[0][i]) continue;
        rep(f, 0, sz(arr[1])) {
            if (arr[1][f] != arr[0][i]) continue;
            auto mx = bit.get(f - 1, vp - 1);
            mx.first++;
            trace[i] = max(trace[i], mx);
            bit.upd(f, vp, {mx.first, i});
        }
    }
    clog << db(trace) << endl;
    
    auto it = max_element(all(trace)) - trace.begin();
    cout << trace[it].first << '\n';
    if (trace[it].first == 0) return 0;
    vector<int> stk;
    while (it != -1) {
        stk.push_back(arr[0][it]);
        it = trace[it].second;
    }
    reverse(all(stk));
    for (auto x: stk) cout << x << ' ';
    
    
    return 0;
}

// vim: foldmethod=marker