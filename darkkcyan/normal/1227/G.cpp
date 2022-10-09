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

const int maxn = 1010;
int n;
int a[maxn];

vector<int> spos; // sorted pos;
list<vector<bool>> solve(int len) {
    if (!len) {
        return {};
    }
    
    int dec_pos = len - 2;
    for (; dec_pos >= 0 and a[spos[dec_pos]] == 1; --dec_pos);
    ++dec_pos;
    list<vector<bool>> ans;
    ans.emplace_back();
    rep(i, 0, dec_pos) {
        --a[spos[i]];
        ans.back().push_back(1);
    }
    rep(i, dec_pos, len - 1) ans.back().push_back(0);
    --a[spos[len - 1]];
    ans.back().push_back(1);
    
    auto rest = solve(len - 1);
    int& last = a[spos[len - 1]];
    if (rest.size()) {
        rest.front().push_back(0);
        for (auto it = ++rest.begin(); it != rest.end(); ++it) {
            it->push_back(!!last);
            if (last) --last;
        }
    }
    if (last) {
        while (last--) {
            rest.emplace_back(len);
            rest.back().back() = 1;
        }
    }
    ans.splice(ans.end(), rest);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    spos.resize(n);
    rep(i, 0, n) spos[i] = i;
    sort(all(spos), [](int u, int v) { return a[u] > a[v]; });
    
    vector<int> rev_pos(n);
    rep(i, 0, n) rev_pos[spos[i]] = i;
    
    auto ans = solve(n);
    cout << sz(ans) << '\n';
    for (auto& row: ans) {
        rep(i, 0, n) cout << row[rev_pos[i]];
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker