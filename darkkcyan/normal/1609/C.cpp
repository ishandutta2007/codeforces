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

const int maxn = 201010;
const int maxval = 1010101;

bool not_prime[maxval];
void precal() {
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i * i < maxval; ++i) {
        if (not_prime[i]) continue;
        for (int f = i * i; f < maxval; f += i)
            not_prime[f] = true;
    }
}

ll solve_single(const vector<int>& num) {
    DB();
    clog << db(num) << endl;
    vector<int> non1;
    non1.push_back(-1);
    rep(i, 0, sz(num)) {
        if (num[i] != 1) {
            non1.push_back(i);
        }
    }
    non1.push_back(sz(num));
    clog << db(non1) << endl;
    ll ans = 0;
    rep(i, 1, sz(non1) - 1) {
        int pos = non1[i];
        clog << db(pos) << db(not_prime[num[pos]]) << endl;
        if (not_prime[num[pos]]) continue;
        ll left = pos - non1[i - 1];
        ll right = non1[i + 1] - pos;
        ans += left * right - 1;
    }
    clog << db(ans) << endl;
    return ans;
}

int n, e;

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        clog << db(ntest) << endl;
        cin >> n >> e;
        vector<vector<int>> arr(e);
        rep(i, 0, n) {
            int x;
            cin >> x;
            arr[i % e].push_back(x);
        }
        ll ans = 0;
        rep(i, 0, e) {
            ans += solve_single(arr[i]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker