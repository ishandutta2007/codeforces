#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

const int maxn = 1030;
const int maxk = 111;
int n, k, m;

int add(int u, int v) {
    u += v;
    if (u >= m) u -= m;
    return u;
}

int mul(int u, int v) {
    return (int)(1ll * u * v % m);
}

int addu(int& u, int v) {
    return u = add(u, v);
}

int cnt[maxk], p10_k[maxn], p10_m[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> m;
    p10_k[0] = p10_m[0] = 1;
    rep1(i, n + 10) {
        p10_k[i] = p10_k[i - 1] * 10 % k;
        p10_m[i] = mul(p10_m[i - 1], 10);
    }
    rep1(i, 9) addu(cnt[i % k], 1);
    
    int ans = 0;
    for (int suff_length = 1; suff_length < n; ++suff_length) {
        addu(ans, mul(cnt[0], mul(9, p10_m[n - suff_length - 1])));
        clog << db(suff_length) << db(ans) << endl;
        int new_cnt[maxk];
        memset(new_cnt, 0, sizeof(new_cnt));
        rep1(cur_mod, k - 1) {
            rep(dig, 10) {
                int new_mod = (cur_mod + dig * p10_k[suff_length]) % k;
                addu(new_cnt[new_mod], cnt[cur_mod]);
            }
        }
        rep1(dig, 9) {
            int new_mod = p10_k[suff_length] * dig % k;
            addu(new_cnt[new_mod], 1);
        }
        memcpy(cnt, new_cnt, sizeof(cnt));
        clog << db(vector<int>(cnt, cnt + 10)) << endl;
    }
    
    addu(ans, cnt[0]);
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker