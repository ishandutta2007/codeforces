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

vector<string> transpose(const vector<string>& u) {
    vector<string> v(sz(u[0]), string(sz(u), ' '));
    
    rep(i, 0, sz(u)) {
        rep(f, 0, sz(u[0])) {
            v[f][i] = u[i][f];
        }
    }
    rep(i, 0, sz(v)) rep(f, 0, sz(v[0])) {
        if (v[i][f] == 'L') v[i][f] = 'U';
        else if (v[i][f] == 'U') v[i][f] = 'L';
        else if (v[i][f] == 'R') v[i][f] = 'D';
        else if (v[i][f] == 'D') v[i][f] = 'R';
    }
    return v;
}

void do_op(vector<string>& u, int r, int c) {
    assert(r < sz(u) - 1 and c < sz(u[0]) - 1);
    assert(u[r][c] == 'U' or u[r][c] == 'L');
    if (u[r][c] == 'U') {
        assert(u[r][c + 1] == 'U');
        assert(u[r + 1][c] == 'D');
        assert(u[r + 1][c + 1] == 'D');
        u[r][c] = u[r + 1][c] = 'L';
        u[r][c + 1] = u[r + 1][c + 1] = 'R';
    } else {
        assert(u[r][c + 1] == 'R');
        assert(u[r + 1][c] == 'L');
        assert(u[r + 1][c + 1] == 'R');
        u[r][c] = u[r][c + 1] = 'U';
        u[r + 1][c] = u[r + 1][c + 1] = 'D';
    }
};
vector<pair<int, int>> normalize(vector<string> u) {
    vector<pair<int, int>> ans;
    
    auto loc_do_op = [&](int r, int c) {
        do_op(u, r, c);
        ans.emplace_back(r, c);
    };
    
    function<void(int, int)> require_hor, require_ver;
    
    require_hor = [&](int r, int c) {
        if (u[r][c] == 'L') return ;
        require_ver(r, c + 1);
        loc_do_op(r, c);
    };
    require_ver = [&](int r, int c) {
        if (u[r][c] == 'U') return ;
        require_hor(r + 1, c);
        loc_do_op(r, c);
    };
    
    assert(sz(u[0]) % 2 == 0);
    rep(r, 0, sz(u) - 1) {
        for (int c = 0; c < sz(u[0]); c += 2) {
            require_hor(r, c);
        }
    }
    
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(f, 0, n) cin >> b[f];
    
    bool trans = 0;
    if (m & 1) {
        trans = 1;
        a = transpose(a);
        b = transpose(b);
    }
    
    auto ans_a = normalize(a);
    auto ans_b = normalize(b);
    
    reverse(all(ans_b));
    auto ans = move(ans_a);
    ans.insert(ans.end(), all(ans_b));
    
    if (trans) {
        for (auto& [r, c]: ans) swap(r, c);
    }
    
    cout << sz(ans) << '\n';
    for (auto [r, c]: ans) cout << r + 1 << ' ' << c + 1 << '\n';

    
    return 0;
}

// vim: foldmethod=marker