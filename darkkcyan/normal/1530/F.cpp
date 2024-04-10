#pragma GCC optimize ("O3")
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

/**
 * Author: Lucian Bicsi
 * Date: 2015-06-25
 * License: GNU Free Documentation License 1.2
 * Source: csacademy
 * Description: Transform to a basis with fast convolutions of the form
 * $\displaystyle c[z] = \sum\nolimits_{z = x \oplus y} a[x] \cdot b[y]$,
 * where $\oplus$ is one of AND, OR, XOR. The size of $a$ must be a power of two.
 * Time: O(N \log N)
 * Status: stress-tested
 */

template<class T, bool inv>
void FST(vector<T>& a) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) {
            int t = i + step;
            rep(j,i,i+step) {
                auto &u = a[j], &v = a[t++];
                if constexpr(inv) {
                    auto x = v - u, y = u;
                    u = x, v = y;
                } else {
                    auto x = v, y = u + v;
                    u = x; v = y;
                }
                // tie(u, v) = 
                    // inv ? make_pair(v - u, u) : make_pair(v, u + v); // AND 
                    // inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line 
                    // pii(u + v, u - v);                   // XOR /// include-line 
            }
		}
	}
	// if (inv) for (int& x : a) x /= sz(a); // XOR only /// include-line
}

template<class T>
vector<T> conv(vector<T> a, vector<T> b) {
	FST<T, false>(a); FST<T, false>(b);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST<T, true>(a); return a;
}

#define def_op(type, op) \
    friend inline type operator op(type u, const type& v) { return u op##= v; } \
    type& operator op##= (const type& o)
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx = 0): x(xx >= mod ? xx % mod : xx) {}
    def_op(modint, +) {
        if ((x += o.x) >= mod) x -= mod; 
        return *this;
    }
    def_op(modint, -) {
        if ((x -= o.x) < 0) x += mod;  
        return *this;
    }
    def_op(modint, *) {
        return *this = modint(x * o.x);
    }
    
    modint pow(int exp) const {
        modint base = *this, ans = 1;
        for (; exp > 0; exp >>=1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    def_op(modint, /) {
        return *this *= o.pow(mod - 2);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<31607>;
const int maxn = 22;
const mint inv1e4 = mint(1) / (int)1e4;

using vm = vector<mint>;
vm cur_dp;

int n;
mint a[maxn][maxn];

vm new_addition;
int S(int col_mask, bool main_diag, bool anti_diag) {
    return col_mask << 2 | (main_diag << 1) | anti_diag;
};

mint ans = 0;
mint sum_pref = 1;
void backtrack(int row, int col, mint cur, int mask) {
    if (col == n) {
        if (mask == (1 << n) - 1) { 
            ans += sum_pref * cur; 
            sum_pref = sum_pref * (1 - cur);
        } else { 
            bool main_diag = (mask >> row) & 1;
            bool anti_diag = (mask >> (n - row - 1)) & 1;
            new_addition[S(mask, main_diag, anti_diag)] = cur;
        } 
        return ;
    }
    backtrack(row, col + 1, cur * a[row][col], mask | (1 << col));
    backtrack(row, col + 1, cur * (1 - a[row][col]), mask);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // n = 21; 
    // rep(i, 0, n) rep(f, 0, n) a[i][f] = 1000 * inv1e4; 
    
    cin >> n;   
    rep(i, 0, n) {   
        rep(f, 0, n) {   
            int x; cin >> x;   
            a[i][f] = x;   
            a[i][f] *= inv1e4;   
        }   
    }   
    
    int n_state = 1 << (n + 2);
    int all_up = (1 << n) - 1;
    
    cur_dp.resize(n_state);
    cur_dp[S(all_up, 1, 1)] = 1;
    
    FST<mint, false>(cur_dp);
    
    rep(row, 1, n + 1) {
        // int par = row & 1; 
        new_addition.assign(n_state, 0);
        backtrack(row - 1, 0, 1, 0);
        FST<mint, false>(new_addition);
        rep(i, 0, n_state) cur_dp[i] *= new_addition[i];
        // DB(); 
        // clog << db(row) << endl; 
        // clog << db(dp[par]) << endl; 
    }
    
    FST<mint, true>(cur_dp);
    
    rep(mask, 0, (1 << n)) {
        // rep(no_row, 0, 2)  
            rep(main_diag, 0, 2) rep(anti_diag, 0, 2) {
                bool should_pick = mask != 0 || main_diag || anti_diag;
                if (should_pick) ans += cur_dp[S(mask, main_diag, anti_diag)];
            }
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker