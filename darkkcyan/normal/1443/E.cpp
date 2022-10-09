#include <bits/stdc++.h>
using namespace std;


#define jalsol_orz main   // I did this for a meme :D


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

const int maxval = 16;
ll fac[maxval];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxval) fac[i] = fac[i - 1] * i;
}

vector<int> find_perm(int len, ll pos) {
    DB();
    clog << db((ll)pos) << endl;
    vector<int> ans;
    vector<bool> used(len);
    rep(i, 0, len) {
        int rest = len - i - 1;
        int dig = -1;
        rep(cur, 0, rest + 1) {
            if (pos < fac[rest]) {
                dig = cur;
                break;
            }
            pos -= fac[rest];
        }
        assert(dig != -1);
        ans.push_back(dig);
    }
    clog << db(ans) << endl;
    for (int i = len; i--; ) {
        rep(f, i + 1, len) {
            if (ans[f] >= ans[i]) ++ans[f];
        }
    }
    clog << db(ans) << endl;
    return ans;
}

int jalsol_orz() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> pref_sum(n + 1);
    pref_sum[0] = 0;
    rep(i, 1, n + 1) pref_sum[i] = pref_sum[i - 1] + i;
    
    ll cur_pos = 0;
    rep(qr, 0, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << pref_sum[r] - pref_sum[l - 1] << '\n';
        } else {
            int pop_lim = min(n, maxval - 1);
            rep(i, 0, pop_lim) pref_sum.pop_back();
            int x;
            cin >> x;
            cur_pos += x;
            auto tail = find_perm(pop_lim, cur_pos);
            ll last = sz(pref_sum) >= 2 ? pref_sum.back() - pref_sum.rbegin()[1] : 0;
            for (auto y: tail) {
                pref_sum.push_back(pref_sum.back() + y + last + 1);
            }
            clog << db(x) << db((ll)cur_pos) << db(pref_sum) << db(tail) << endl;
            rep(i, 0, n) {
                clog << db(i) << db(pref_sum[i + 1] - pref_sum[i]) << endl;
            }
        }
    }
    
    return 0;
}

// vim: foldmethod=marker