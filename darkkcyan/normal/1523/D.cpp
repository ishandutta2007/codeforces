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

mt19937 rng;

#define rand() ((int)(rng() >> 1))

const int cnt_iter = 50;
const int maxn = 201010;

int n, m, p;
ll num[maxn];

int main() {
    rng.seed(time(0) ^ (ll)main);
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> p;
    rep(i, 0, n) {
        string s; cin >> s;
        rep(f, 0, m) {
            if (s[f] == '1') num[i] |= 1ll << f;
        }
    }
    
    ll ans = 0;
    
    for (int iter = cnt_iter; iter --; ) {
        int id = rand() % n;
        
        ll mask = num[id];
        
        vector<int> bits;
        rep(i, 0, m) {
            if ((mask >> i) & 1) {
                bits.push_back(i);
            }
        }
        
        int all_on = (1 << sz(bits)) - 1;
        
        vector<int> cnt(1 << sz(bits));
        
        rep(i, 0, n) {
            int cur_num = 0;
            rep(b, 0, sz(bits)) {
                int bit = bits[b];
                if ((num[i] >> bit) & 1) {
                    cur_num |= 1 << b;
                }
            }
            cnt[cur_num ^ all_on]++;
        }
        
        rep(b, 0, sz(bits)) {
            rep(i, 0, sz(cnt)) {
                if (i & (1 << b)) 
                    cnt[i] += cnt[i ^ (1 << b)];
            }
        }
        
        rep(i, 0, sz(cnt)) {
            if (cnt[i] * 2 < n) continue;
            int cur_mask = i ^ all_on;
            if (__builtin_popcountll(cur_mask) < __builtin_popcountll(ans)) continue;
            ans = 0;
            rep(b, 0, sz(bits)) {
                if (cur_mask & (1 << b)) ans |= 1ll << bits[b];
            }
        }
    }
    
    rep(i, 0, m) {
        cout << ((ans >> i) & 1);
    }
    
    return 0;
}

// vim: foldmethod=marker