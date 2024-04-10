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

const int base = 5;
const int mod = (int)1e9 + 7;

int mpow(int b, int exp) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, b = (int)(1ll * b * b % mod))
        if (exp & 1) ans = (int)(1ll * ans * b % mod);
    return ans;
}

void add(vector<int>& a, const vector<int> b) {
    rep(i, 0, sz(a)) {
        a[i] += b[i];
        if (a[i] >= base) a[i] -= base;
    }
}

void sub(vector<int>& a, const vector<int> b) {
    rep(i, 0, sz(a)) {
        a[i] -= b[i];
        if (a[i] < 0) a[i] += base;
    }
}

void mul(vector<int>& a, int m) {
    rep(i, 0, sz(a)) a[i] = a[i] * m % base;
}

int inv(int x, int m) {
    rep(y, 1, m) if (x * y % m == 1) return y;
    assert(false);
    return -1;
}

int n, m;
vector<vector<int>> basis;
int add_basis(vector<int> a) {
    rep(i, 0, m) {
        if (a[i] == 0) continue;
        if (basis[i][i] == 0) {
            basis[i] = a;
            return true;
        }
        auto t = basis[i];
        mul(t, a[i] * inv(t[i], base));
        sub(a, t);
    }
    return false;
}

bool check(vector<int> a) {
    rep(i, 0, m) {
        if (a[i] == 0) continue;
        if (basis[i][i] == 0) return false;
        auto t = basis[i];
        mul(t, a[i] * inv(t[i], base));
        sub(a, t);
    }
    return true;
}

vector<int> parse(const string& s) {
    vector<int> ans(sz(s));
    rep(i, 0, sz(s)) ans[i] = s[i] - 'a';
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    basis.resize(m, vector<int>(m));
    int bas_size = 0;
    rep(i, 0, n) {
        string s; cin >> s;
        bas_size += add_basis(parse(s));
    }
    
    int overal = mpow(5, n - bas_size);
    
    int q;
    cin >> q;
    while (q--) {
        string s; cin >> s;
        if (check(parse(s))) cout << overal << '\n';
        else cout << "0\n";
    }
    
    return 0;
}

// vim: foldmethod=marker