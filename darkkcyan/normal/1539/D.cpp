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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, 0, n) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(all(a), [&](const pair<ll, ll>& u, const pair<ll, ll>& v) {
            if (u.second == v.second) return u.first > v.first;
            return u.second < v.second;
            });
    
    vector<ll> filled(n);
    ll total_filled = 0;
    ll ans = 0;
    auto inc = [&](int i, ll spent) {
        filled[i] += spent;
        total_filled += spent;
    };
    int big = n - 1, small = 0;
    while (big > small) {
        ll discount = max(0ll, a[small].second - total_filled);
        ll big_lim = a[big].first - filled[big];
        ll spent = min(discount, big_lim);
        
        inc(big, spent);
        ans += 2 * spent;
        if (filled[big] == a[big].first) --big;
        if (a[small].second <= total_filled) {
            inc(small, a[small].first);
            ans += a[small].first;
            ++small;
        }
    }
    
    if (big == small) {
        ll need = a[small].first - filled[small];
        ll discount = max(0ll, a[small].second - total_filled);
        
        ll spent = min(need, discount);
        
        inc(small, spent);
        ans += 2 * spent;
        need -= spent;
        
        spent = need;
        ans += spent;
        inc(small, spent);
    }
    
    cout << ans;
    return 0;
}

// vim: foldmethod=marker