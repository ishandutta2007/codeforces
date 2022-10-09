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

const int maxval = 505050;
const int maxn = 201010;
vector<int> divs[maxval];
int mobius[maxval], pdiv[maxval];

void precal() {
    rep(i, 1, maxval) divs[i].push_back(1);
    mobius[1] = 1;
    rep(i, 2, maxval) {
        if (pdiv[i] == 0) {
            for (int f = i; f < maxval; f += i) pdiv[f] = i;
        }
        if (i / pdiv[i] % pdiv[i]) mobius[i] = -mobius[i / pdiv[i]];
        else mobius[i] = 0;
        for (int f = i; f < maxval; f += i)
            divs[f].push_back(i);
    }
}

int n, q;
int a[maxval];
int has_sign[maxval];
ll cnt[maxval];

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    rep(i, 0, n) {
        cin >> a[i];
        has_sign[i] = -1;
    }
    
    ll cur_ans = 0;
    while (q--) {
        DB();
        int x; cin >> x;
        --x;
        int val = a[x];
        has_sign[x] *= -1;
        ll add = 0;
        clog << db(x) << db(val) << db(has_sign[x]) << endl;
        for (auto d: divs[val]) {
            if (has_sign[x] == -1) --cnt[d];
            clog << db(d) << db(mobius[d]) << db(cnt[d]) << endl;
            add += has_sign[x] * mobius[d] * cnt[d];
            if (has_sign[x] == 1) ++cnt[d];
        }
        clog << db(add) << endl;
        cur_ans += add;
        cout << cur_ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker