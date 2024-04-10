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

ll m, x;  //inputs 

ll bin_mul(ll a, ll b, ll mod) {
    // DB(); 
    // clog << db(a) << db(b) << db(mod) << endl; 
    a %= mod;
    b %= mod;
    ll ans = 0;
    for (ll cur = a; b > 0; (cur += cur) >= mod ? cur -= mod : 0, b >>= 1) {
        if (b & 1) ans += cur;
        if (ans >= mod) ans -= mod;
    }
    // clog << db(ans) << endl; 
    return ans;
}

ll bin_pow(ll base, ll exp, ll mod) {
    // DB(); 
    // clog << db(base) << db(exp) << db(mod) << endl; 
    base %= mod;
    ll ans = 1;
    for (; exp > 0; exp >>= 1 , base = bin_mul(base, base, mod)) {
        if (exp & 1) ans = bin_mul(ans, base, mod);
    }
    return ans;
}

vector<pair<ll, int>> factorize(ll num) {
    vector<pair<ll, int>> ans;
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i) continue;
        auto& cur = ans.emplace_back(i, 0);
        while (num % i == 0) {
            num /= i;
            ++cur.second;
        }
    }
    if (num > 1) ans.emplace_back(num, 1);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> m >> x;
    auto fm = factorize(m);
    vector<vector<pair<ll, int>>> ffm;
    vector<ll> all_fac;
    for (auto& cur_fac: fm) {
        all_fac.push_back(cur_fac.first);
        auto& cur_ff = ffm.emplace_back(factorize(cur_fac.first - 1));
        clog << db(cur_ff) << endl;
        for (auto& cur_cur_fac: cur_ff) {
            all_fac.push_back(cur_cur_fac.first);
        }
    }
    clog << db(fm) << endl;
    clog << db(ffm) << endl;
    
    sort(all(all_fac));
    all_fac.erase(unique(all(all_fac)), all_fac.end());
    for (auto& cur_fac: fm)
        cur_fac.first = lower_bound(all(all_fac), cur_fac.first) - all_fac.begin();
    for (auto& cur_ff: ffm) {
        for (auto& cur_fac: cur_ff) 
            cur_fac.first = lower_bound(all(all_fac), cur_fac.first) - all_fac.begin();
    }
    
    clog << db(all_fac) << endl;
    clog << db(fm) << endl;
    clog << db(ffm) << endl;
    vector<int> fac_count(sz(all_fac));
    function<ll(int, ll, ll)> backtrack = [&](int i, ll d, ll phi_d) -> ll{
        ll ans = 0;
        if (i == sz(fm)) {
            // if (d == 1) return 0; 
            DB();
            clog << db(i) << db(d) << db(phi_d) << db(fac_count) << endl;
            // ll cx = x % d; 
            ll cx = x;
            ll cur_pw = phi_d;
            rep(f, 0, sz(fac_count)) {
                if (fac_count[f] == 0) continue;
                rep(p, 1, fac_count[f] + 1) {
                    ll new_pw = cur_pw / all_fac[f];
                    if (bin_pow(cx, new_pw, d) == 1) {
                        cur_pw = new_pw;
                    } else break;
                }
            }
            // ll ord = bin_pow(cx, cur_pw, d); 
            // clog << db(cur_pw) << db(ord) << endl; 
            ans = phi_d / cur_pw;
            return ans;
        }
        
        ans += backtrack(i + 1, d, phi_d);
        
        d *= all_fac[fm[i].first];
        phi_d *= all_fac[fm[i].first] - 1;
        for (auto cur_fac: ffm[i]) {
            fac_count[cur_fac.first] += cur_fac.second;
        }
        
        rep(f, 1, fm[i].second + 1) {
            ans += backtrack(i + 1, d, phi_d);
            d *= all_fac[fm[i].first];
            phi_d *= all_fac[fm[i].first];
            ++fac_count[fm[i].first];
        }
        fac_count[fm[i].first] -= fm[i].second;
        
        for (auto cur_fac: ffm[i]) {
            fac_count[cur_fac.first] -= cur_fac.second;
        }
        
        return ans;
    };
    
    auto ans = backtrack(0, 1, 1);
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker